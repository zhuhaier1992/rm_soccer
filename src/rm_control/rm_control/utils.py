import torch
import torch.nn.functional as F
from math import *
import numpy as np
from numpy.linalg import norm
from ros2_interfaces.msg import RobotPose
from geometry_msgs.msg import Vector3, Pose2D
from interval import Interval
import logging
from .RVO_neo import RVO_update, compute_V_des
import sympy as sp

# def get_ori(p1,p2):
#     return atan2(p1[1]-p2[1], p1[0]-p2[0])*180/pi

def distance(p1, p2):
    """
    compute Euclidean distance for 2D
    input: np array or list
    return: float or double    
    """
    return sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) 

def dis_pose2d(p1: Pose2D, p2: Pose2D):
    """ compute distance according to pose inputs """
    return sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2) 

def get_ori(z,w):
    t=atan2(2*w*z,1-2*z**2)+pi/2 # 动捕建立刚体时以y轴为朝向，但实际返回的偏转角度还是以x轴，所以+90°以获得y轴偏转角
    return limit_pi(t)



def get_len(x,y):
    return (x**2+y**2)**0.5

def limit_phi(phi):
    '''restrict phi in the range (-pi, pi]'''
    if phi>180:
        phi=phi-360
    elif phi<=-180:
        phi=phi+360
    return phi

def limit_pi(t):
    if t>=pi:
        return t-2*pi
    elif t<=-pi:
        return t+2*pi
    return t


def check_contain_only(l, a):
    '''check if l only contains a'''
    if len(l)==0:
        return False
    for i in l:
        if i!=a:
            return False
    return True

def check_catched(p,b, vb):
    '''check if catched ball according to pose_ep and pose_ball'''
    dphi=limit_pi(atan2(b.y-p.y,b.x-p.x)*180/pi-limit_pi(p.phi)) # 球和ep的朝向角度差
    d=((b.x-p.x)**2+(b.y-p.y)**2)**0.5 # 球和ep中心的距离
    logging.debug(f'是否抓住：角度差:{dphi}, 距离（m）:{d}')
    return (abs(dphi)<3 and d in Interval(0.28,0.314+vb.get_norm()/30))

# def check_catchable(ps, pb):
#     cphi=atan2(pb.y-ps.y, pb.x-ps.x)*180/pi
#     dphi=limit_pi(abs(cphi-ps.phi))
#     d=dis_pose(ps, pb)
#     if dphi<4 and 0.280<d<0.314:
#         return True
#     else:
#         return False

# def check_inline(ps, pb):
#     '''check if can enter chase phase 1'''
#     cphi=atan2(pb.y-ps.y, pb.x-ps.x)*180/pi
#     dphi=limit_pi(abs(cphi-ps.phi))
#     d=dis_pose(ps, pb)
#     logging.debug(f'距离:{d} 角度差:{dphi}')
#     if dphi<6:
#         return True
#     elif d>0.32 and dphi<(d-0.32)*100+6:
#         return True
#     else: 
#         return False
def clip_pose2d(p, low, high):
    if isinstance(p, Pose2D):
        if p.x<low[0]:
            p.x=float(low[0])
        elif p.x>high[0]:
            p.x=float(high[0])
        if p.y<low[1]:
            p.y=float(low[1])
        elif p.y>high[1]:
            p.y=float(high[1])
        return p
        


def pose2d_to_nparray(poses):
    # print(poses)
    if isinstance(poses, Pose2D):
        return np.array([poses.x, poses.y, poses.theta])
    l=len(poses)
    r=np.zeros([l, 3])
    for i in range(l):
        r[i,:]=[poses[i].x, poses[i].y, poses[i].theta]
    return r


def nparray_to_pose2d(arr):
    if arr.ndim==1:
        return Pose2D(x=arr[0],y=arr[1], theta=arr[2])
    r=[]
    for i in range(arr.shape[0]):
        r.append(Pose2D(x=arr[i][0],y=arr[i][1], theta=arr[i][2]))
    return r


def calc_catching_pose(b: Pose2D, a: Pose2D, catch_phase1=False):
    '''Calc pose to catch ball. b: ball pose, a: agent pose'''
    x,y=sp.symbols('x, y')
    distance=0.316 if catch_phase1 else 0.42 # distance from ball to pose
    # logging.debug(f'dist:{distance}')
    solutions=sp.nonlinsolve([(x-b.x)*(b.y-a.y)-(y-b.y)*(b.x-a.x),
                              (x-b.x)**2+(y-b.y)**2-distance**2],[x,y])
    for s in solutions:
        if (s[0]-b.x)*(a.x-b.x)>0 and (s[1]-b.y)*(a.y-b.y)>0:
            # logging.debug(f'solved pt: x:{s[0]},y:{s[1]}')
            print(s[0],s[1])
            return Pose2D(x=float(s[0]),y=float(s[1]),theta=float(atan2(b.y-a.y, b.x-a.x)))
 
def calc_aiming_goal(pa, pg):
    '''
    calculate the radian to aim agent in pa against goal in pg
    pa: position of agent
    pg: position of goal
    return: radian 
    '''
    return atan2(pg[1]-pa[1], pg[0]-pa[0])


def trans_relative_co(ps: Pose2D, pt:Pose2D):
    '''pt: 目标的坐标    ps: 自己的坐标    return: 在新坐标系下的坐标'''
    t=ps.theta
    trans_matrix=np.array([[cos(t), -sin(t), ps.x],[sin(t),cos(t),ps.y],[0,0,1]])
    trans_pt=np.linalg.inv(trans_matrix)@np.hstack((pt.x,pt.y,1))
    theta_d=limit_pi(pt.theta-ps.theta)
    return Pose2D(x=trans_pt[0],y=trans_pt[1],theta=theta_d)


def reach_time(pa: Pose2D, pb: Pose2D, vb: Pose2D):
    '''
    for agent from position pa with constant speed va to
    reach ball from position pb with constant speed vb, 
    calculate the shortest time
    '''
    # van=np.array([va.x, va.y]) # 0.5
    vbn=np.array([vb.x, vb.y])
    pan=np.array([pa.x, pa.y])
    pbn=np.array([pb.x, pb.y])
    p=pan-pbn
    t=sp.Symbol('t')
    eq=(0.5**2-np.linalg.norm(vbn)**2)*t**2 \
        +2*t*np.dot(p, vbn)-np.linalg.norm(p)**2
    solutions=sp.nonlinsolve([eq],[t])
    t=10000
    for s in solutions:
        # print(s[0])
        if s[0]>0 and s[0]<t:
            t=s[0]
    # t=next(iter(solutions))[0]
    p0=pbn+vbn*t
    return t, p0


def find_closest(robot_pose: RobotPose, vb: Pose2D):
    '''
    robot_pose.pose: 7 Pose2D list, ball at 0, 1~6 is robomaster
    vb: ball velocity
    '''
    pb=robot_pose.pose[0]
    t_min=1000.
    p0=np.array([0,0])
    id=0
    for i in range(len(robot_pose.pose)-1):
        i+=1
        t, p=reach_time(robot_pose.pose[i], pb, vb)
        # print(t)
        
        if 0< t < t_min:
            t_min, p0, id=t, p, i
    return id, t_min, p0


def shoot_position(pb:Pose2D, pg:Pose2D, d=0.4):
    '''
    calc the position to shoot
    pb: ball position
    pg: goal position
    return: np array
    '''
    pa=pose2d_to_nparray([pb, pg])
    pba,pga=pa[0], pa[1]
    bga=pba-pga
    pt=pba[:2]+bga[:2]/norm(bga[:2])*d
    theta= atan2(-bga[1], -bga[0])
    pt=np.append(pt, limit_pi(theta))
    return pt




# def get_rvo_vel_old(p_cur,v_cur,pt_cur):
#     '''
#     given all positions and velocities and target positions, calc the best velocity
#     p_cur: nparray: 7 poses
#     v_cur: nparray: 7 speeds
#     pt_cur: nparray: 7poses'''
#     # logging.basicConfig(level=logging.DEBUG)
#     v_max = [0.5 for i in range(7)]
#     ws_model = dict()
#     ws_model['robot_radius'] = [0.035]+[0.16]*6
#     ws_model['circular_obstacles'] = []
#     # logging.debug(f'current position:{p_cur}')
#     v_des = compute_V_des(p_cur, pt_cur, v_max)
#     v_best = RVO_update(p_cur, v_des, v_cur, ws_model)
    
#     # logging.debug(f'best vel first:{v_best}')
#     for i in range(1, 4):
#         if distance(pt_cur[i], p_cur[i])<0.5:
#              continue
#         if np.linalg.norm(v_best[i])<0.1:
#             logging.debug(f'v{i} too slow as {v_best[i]}')
#             v_best[i]=v_best[i]/np.linalg.norm(v_best[i])*0.1

#     return v

# def new_point(po):
#     pn1=np.array([[po[0]-0.033*cos(po[2]), po[1]-0.033*sin(po[2])]])
#     pn2=np.array([[po[0]+0.21*cos(po[2]), po[1]+0.21*sin(po[2])]])
#     return pn1, pn2

# def get_rvo_vel(p_cur,v_cur,pt_cur):
#     '''
#     add extra moving obstacles as the extension part of agent
#     given all positions and velocities and target positions, calc the best velocity
    
#     p_cur: nparray: 7*3 poses with [x, y, phi]
#     v_cur: nparray: 7*2 speeds
#     pt_cur: nparray: 7*3 poses'''
#     # logging.basicConfig(level=logging.DEBUG)
#     v_max = [0.5 for i in range(7)]
#     ws_model = dict()
#     ws_model['robot_radius'] = [0.035]+[0.18]*12
#     ws_model['circular_obstacles'] = []
#     p_new=np.zeros((10,2))
#     p_new[:7]=p_cur[:,:2]
    
#     pt_cur=pt_cur[:,:2]
#     pt_new=np.zeros((10,2))
#     pt_new[:7]=pt_cur[:,:2]
    

#     for i in range(1, 4):
#         c1, c2=new_point(p_cur[i])
#         p_new[i]=c1
#         p_new[i+6]=c2
#         t1, t2=new_point([pt_cur[i][0],pt_cur[i][1],p_cur[i][2]])
#         pt_new[i]=t1
#         pt_new[i+6]=t2
#         v_cur=np.concatenate((v_cur, np.expand_dims(v_cur[i],0)))

#     # logging.debug(f'current position:{p_cur}')
#     v_des = compute_V_des(p_new, pt_new, v_max)
#     v_best = RVO_update(p_new, v_des, v_cur, ws_model)
#     v_best=v_best[:7]
    
#     # logging.debug(f'best vel first:{v_best}')
#     for i in range(len(v_best)):
#         if distance(pt_new[i], p_new[i])<0.5:
#              continue
#         if np.linalg.norm(v_best[i])<0.08:
#             logging.debug(f'v too slow as {v_best[i]}')
#             v_best[i]=v_best[i]/np.linalg.norm(v_best[i])*0.08
#     v=speeds()
#     v.set_arr(v_best)
#     return v    

# def closest_enemy(ps, p):
#     '''ps: self pose, p: all poses
#     return the closes enemy id and the distance'''
#     sd=10
#     id=0
#     for i in range(4,7):
#         d=dis_pose(ps, p.pl[i])
#         if d<sd:
#             id=i
#             sd=d
#     return id, sd

# def obstacle_enemy(ps, pt, p):
    
#     '''ps, pt: pose, p: poses
#     return an enemy that stands between ps and pt'''
#     l=get_line_func(ps.x, ps.y, pt.x, pt.y)
#     for i in range(4,7):
#         d=dist_point_to_line(p[i].x,p[i].y,l)
#         if d<0.4:
#             return i, d
#     return 0,0

# def get_line_func(x1,y1,x2,y2):
#     a=y1-y2
#     b=x2-x1
#     c=x1*y2-x2*y1
#     return [a,b,c]

# def dist_point_to_line(x,y,l):
#     '''from point(x,y) to line l [a,b,c]'''
#     t=sqrt(l[0]*l[0]+l[1]*l[1])
#     if t==0:
#         t=0.0001
#     return abs((l[0]*x+l[1]*y+l[2])/t)


# def calc_closest_pose_on_v(p,b,v):
#     '''
#     计算p在向量v（球速度）上的投影点, v经过点b（球）
#     pt_local: 投影点的位置,速度角度的反方向（机器人应当接球的方向)
#     '''
#     tx,ty=sp.symbols('tx, ty')
#     s=sp.solve([(tx-b.x)*v.y-v.x*(ty-b.y), v.x*(tx-p.x)+v.y*(ty-p.y)],[tx,ty])
#     pt_local=pose(s[tx],s[ty])
#     dphi=limit_pi(atan2(v.y,v.x)*180/pi+180-p.phi)
#     trans_pt=trans_relative_co(p,pt_local)
#     trans_pt.update(trans_pt.x,trans_pt.y,dphi)
#     # logging.info(f'dynamic v1 catch trans_pt: x: {trans_pt.x}, y:{trans_pt.y}, phi:{trans_pt.phi}')
#     return trans_pt

# def angle_to_aim(ps, pt):
#     '''calculate the angel to face the target'''
#     dphi=limit_pi(atan2(pt.y-ps.y, pt.x-ps.x)*180/pi)
#     return dphi

# def get_passing_pose(ps:pose, pt:pose, po:pose):
#     '''po: obstacle position'''
#     # l=get_line_func(ps.x,ps.y,pt.x,pt.y)
#     # d=dist_point_to_line(po.x,po.y,l)
#     pst=pose(ps.x, ps.y, angle_to_aim(ps, pt)) # 理想姿态
#     # logging.debug(f'relative pose is: {pst} versus before: {ps}')
#     trans_po=trans_relative_co(pst,po) # 理想姿态下敌人/障碍的相对坐标
#     # logging.debug(f'enemy at :{po}, relative at: {trans_po}')
#     if abs(trans_po.y)<0.3:
#         trans_pt=pose(0,0.5*np.sign(trans_po.y), limit_pi(angle_to_aim(ps, pt)-ps.phi))
#         return trans_pt
#     else:
#         return pose()
    