#define SIM_MOD(x) dbx_control##x // ### MODIFY HERE ### Substitute here dbx_control with the name ofr your Simulink model

#include <ros/ros.h>
#include "ros_sim_template/ros_sim_template.hpp"
#include "dbx_control/dbx_control.cpp"
#include "dbx_control/dbx_control_data.cpp"

// Define the Simulink object
SIM_MOD(ModelClass) SIM_MOD(ModelObj);

void define_simulink_inputs();

int main(int argc, char **argv) {
	ros::init(argc, argv, "ros_sim_template");

	ros::NodeHandle nodeHandle;
	

	// Subscriptions

	// Publishers

	ros::Rate loopRate(20);

	ros::WallTime begin = ros::WallTime::now();
	double elapsed = begin.toSec();
	while (ros::ok()) {
		ROS_INFO_STREAM("  Effective frequency "<<1.0/(ros::WallTime::now().toSec()-begin.toSec())<<" Hz");
		begin = ros::WallTime::now();

		// Init Simulink
		SIM_MOD(ModelObj).initialize();

		// Define Simulink inputs here
		define_simulink_inputs();

		// Rus ONE step of Simulink model. Make sure this wrapper frequesny and Simulink frequency are the same
		SIM_MOD(ModelObj).step();

		// ### MODIFY HERE ###  Get outputs from Simulink and do what you need
		ROS_INFO("%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\n",
				(double)(SIM_MOD(ModelObj).SIM_MOD(_U).runtime/1000000),
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug1,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug2,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug3,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug4,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug5,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug6,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug7,
				(double)SIM_MOD(ModelObj).SIM_MOD(_Y).debug8);



		ros::spinOnce();
		loopRate.sleep();

	}
	SIM_MOD(ModelObj).terminate();
	return 0;
}

// ### MODIFY HERE ### : put the exact inputs names
void define_simulink_inputs(){

	SIM_MOD(ModelObj).SIM_MOD(_U).runtime = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).mag_x = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).mag_y = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).mag_z = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).acc_x = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).acc_y = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).acc_z = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gyro_x = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gyro_y = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gyro_z = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).rate_roll = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).rate_pitch = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).rate_yaw = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).att_roll = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).att_pitch = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).att_yaw = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).q0 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).q1 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).q2 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).q3 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).baro_alt = 0; 
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_sat = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_lat = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_lon = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_alt = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_vel = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_vel_n = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_vel_e = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).gps_vel_d = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch1 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch2 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch3 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch4 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch5 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch6 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch7 = 0;
	SIM_MOD(ModelObj).SIM_MOD(_U).ch8 = 0;


}
