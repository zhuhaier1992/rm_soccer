from setuptools import setup
from glob import glob
import os

package_name = 'rm_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zhe',
    maintainer_email='zhe@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'rm_control = rm_control.rm_control:main',
            'strategy = rm_control.strategy:main',
            'rm_test = rm_control.rm_test:main',
        ],
    },
)
