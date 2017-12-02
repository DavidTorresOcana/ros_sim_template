# ROS_node simulink target template
A ROS node template to embed Simulink code generated with ertw


## Requirements

* Requires Matlab 2015a or above
* Matlab Code Generation Toolbox
* Ubuntu 14 or above
* ROS Indigo or later versions

## Where to find the main files
* Head to /ros_sim_template/src. Here you will find
  - ROS node definition
  - Simulink model  wich generate the code with


## Usage

### 1. Code generation within Matlab/Simulink (If you fail this step, skip to step2)
This step can be done within Linux environment or Widnows, where ever you have Matlab installed.

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
 
### 2. Unzip Matlab/Simulink code generated
* Unzip "dbx_control.zip" into the folder "dbx_control"
  - So that "dbx_control.c" file should be found in /ros_sim_template/src/dbx_control/dbx_control.c

### 3. Package build in ROS
This step assumes you already created a workspace in which you put this package

```
cd ~/catkin_ws/
catkin build
source devel/setup.bash
```
### 4. Running the node
```
roscore
rosrun ros_sim_template ros_sim_template 
```

## 5. Now, your Simulink model
* Repeat same steps (1.) of code generation with your model
  - It is highly recomended you reuse the Simulink model "dbx_control.slx", so Simulink configuration is already set for you
  - Deploy your generated code into a folder with **same name** as your Simulink model
* In file /ros_sim_template/src/ros_sim_template_node.cp:
   - Those parts of the code with ### MODIFY HERE ###  would need to be modified
   - In First line substitue "dbx_control" with the name of your model. E.g.:
       + ```#define SIM_MOD(x) dbx_control##x``` would look like ```#define SIM_MOD(x) your_simulink_model_name##x``` where "your_simulink_model_name" is your Simulink mode name: E.g. ```#define SIM_MOD(x) Lat_control##x``` for a Simulink model named "Lat_control"
* (OPTIONAL) Change the name of the node, or even the package

