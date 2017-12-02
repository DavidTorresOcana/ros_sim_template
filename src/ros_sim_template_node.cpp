#define SIMULINK_MODEL_NAME "dbx_control"

#include <ros/ros.h>
#include "ros_sim_template/ros_sim_template.hpp"
#include "dbx_control/dbx_control.cpp"
#include "dbx_control/dbx_control_data.cpp"

int main(int argc, char **argv) {
	ros::init(argc, argv, "ros_sim_template");

	ros::NodeHandle nodeHandle;
	dbx_controlModelClass dbx_controlModelObj;
	dbx_controlModelObj.initialize();

	// Subscriptions

	// Publishers

	ros::Rate loopRate(20);

	ros::WallTime begin = ros::WallTime::now();
	double elapsed = begin.toSec();
	while (ros::ok()) {
		ROS_INFO_STREAM("  Effective frequency "<<1.0/(ros::WallTime::now().toSec()-begin.toSec())<<" Hz");
		begin = ros::WallTime::now();

		// Define Simulink inputs here
		dbx_controlModelObj.dbx_control_U.runtime = 0;
		dbx_controlModelObj.dbx_control_U.mag_x = 0;
		dbx_controlModelObj.dbx_control_U.mag_y = 0;
		dbx_controlModelObj.dbx_control_U.mag_z = 0;
		dbx_controlModelObj.dbx_control_U.acc_x = 0;
		dbx_controlModelObj.dbx_control_U.acc_y = 0;
		dbx_controlModelObj.dbx_control_U.acc_z = 0;
		dbx_controlModelObj.dbx_control_U.gyro_x = 0;
		dbx_controlModelObj.dbx_control_U.gyro_y = 0;
		dbx_controlModelObj.dbx_control_U.gyro_z = 0;
		dbx_controlModelObj.dbx_control_U.rate_roll = 0;
		dbx_controlModelObj.dbx_control_U.rate_pitch = 0;
		dbx_controlModelObj.dbx_control_U.rate_yaw = 0;
		dbx_controlModelObj.dbx_control_U.att_roll = 0;
		dbx_controlModelObj.dbx_control_U.att_pitch = 0;
		dbx_controlModelObj.dbx_control_U.att_yaw = 0;
		dbx_controlModelObj.dbx_control_U.q0 = 0;
		dbx_controlModelObj.dbx_control_U.q1 = 0;
		dbx_controlModelObj.dbx_control_U.q2 = 0;
		dbx_controlModelObj.dbx_control_U.q3 = 0;
		dbx_controlModelObj.dbx_control_U.baro_alt = 0; 
		dbx_controlModelObj.dbx_control_U.gps_sat = 0;
		dbx_controlModelObj.dbx_control_U.gps_lat = 0;
		dbx_controlModelObj.dbx_control_U.gps_lon = 0;
		dbx_controlModelObj.dbx_control_U.gps_alt = 0;
		dbx_controlModelObj.dbx_control_U.gps_vel = 0;
		dbx_controlModelObj.dbx_control_U.gps_vel_n = 0;
		dbx_controlModelObj.dbx_control_U.gps_vel_e = 0;
		dbx_controlModelObj.dbx_control_U.gps_vel_d = 0;
		dbx_controlModelObj.dbx_control_U.ch1 = 0;
		dbx_controlModelObj.dbx_control_U.ch2 = 0;
		dbx_controlModelObj.dbx_control_U.ch3 = 0;
		dbx_controlModelObj.dbx_control_U.ch4 = 0;
		dbx_controlModelObj.dbx_control_U.ch5 = 0;
		dbx_controlModelObj.dbx_control_U.ch6 = 0;
		dbx_controlModelObj.dbx_control_U.ch7 = 0;
		dbx_controlModelObj.dbx_control_U.ch8 = 0;


		// Rus ONE step of Simulink model. Make sure this wrapper frequesny and Simulink frequency are the same
		dbx_controlModelObj.step();

		// Get outputs from Simulink and do what you need
		ROS_INFO("%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\n",
				(double)(dbx_controlModelObj.dbx_control_U.runtime/1000000),
				(double)dbx_controlModelObj.dbx_control_Y.debug1,
				(double)dbx_controlModelObj.dbx_control_Y.debug2,
				(double)dbx_controlModelObj.dbx_control_Y.debug3,
				(double)dbx_controlModelObj.dbx_control_Y.debug4,
				(double)dbx_controlModelObj.dbx_control_Y.debug5,
				(double)dbx_controlModelObj.dbx_control_Y.debug6,
				(double)dbx_controlModelObj.dbx_control_Y.debug7,
				(double)dbx_controlModelObj.dbx_control_Y.debug8);



		ros::spinOnce();
		loopRate.sleep();

	}
	dbx_controlModelObj.terminate();
	return 0;
}
