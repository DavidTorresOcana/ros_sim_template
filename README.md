# ROS_node_simulink_target_template
A ROS node template to embed Simulink code generated with ertw



## Requirements

* Requires Matlab 2015a or above
* Matlab Code Generation Toolbox
* Ubuntu 14 or above
* ROS Indigo or later versions

## Usage
### Where to find the main files
* Head to /ros_sim_template/src. Here you will find
  - ROS node definition
  - Simulink model withwich generate the code

### Code generation within Matlab/Simulink
This step can be done withn in Linux environment or Widnows, where ever you have  Matlab.

* Open the model "dbx_control.slx"
* Build the model with Ctrl+b. This will generate the appropiate code. See model configuration for further details
* In Matlab console:
```
cd dbx_control_ert_rtw\
load('buildInfo.mat')
packNGo(buildInfo)
cd ..
```
* If you are in a diferent folder from the ROS node (where you found the Simulink model):
  - Copy an paste the file "dbx_control.zip" into the folder /ros_sim_template/src
 
* Unzip "dbx_control.zip" into the folder "dbx_control": dbx_control.c file should be found then in /ros_sim_template/src/dbx_control/dbx_control.c

### Package build in ROS
This step assumes you already created a workspace in which you put this package

```
cd ~/catkin_ws/
catkin build
source devel/setup.bash
```
### Running the node
```
roscore
rosrun ros_sim_template ros_sim_template 
```

