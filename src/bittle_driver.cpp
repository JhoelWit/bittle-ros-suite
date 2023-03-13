#include <bittle_driver/bittle_driver.h>
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <string>
#include <serial/serial.h>

serial::Serial* bittleSerial;

// Constructor
BittleDriver::BittleDriver(std::string port, int baudRate){
    // Constructor implementation
    // Initialize the serial object
    ROS_INFO_STREAM("Opening serial connection with port: " << port << " and baud rate: " << baudRate);
    serial::Serial* bittleSerial = new serial::Serial(port, baudRate, serial::Timeout::simpleTimeout(1000));
};

BittleDriver::~BittleDriver(){
    // Destructor implementation
    bittleSerial->close();

    delete bittleSerial;
}

void BittleDriver::setSpeed(float speed){
    linearVel_ = speed;
}

void BittleDriver::setTurnRadius(float radius){
    turnRadius_ = radius;
}

void BittleDriver::cmdVelCallback(const geometry_msgs::Twist& msg){
    ROS_INFO_STREAM("Received a twist message! Linear: " << msg.linear.x << "Angular: " << msg.angular.z);
    int msgState;
    if (msg.linear.x > 0) {msgState = 1;}
    else if (msg.linear.x < 0) {msgState = -1;}
    else if (msg.angular.z > 0) {msgState = 2;}
    else if (msg.angular.z < 0) {msgState = 3;}
    else {msgState = 0;}

    if (msgState != bittleState)
    {
        serialWrite(directions[msgState]);
        bittleState = msgState;
    }
}

void BittleDriver::serialWrite(std::string token){
    ROS_INFO_STREAM("Writing token: " << token << "!!");
    if (!bittleSerial->isOpen())
    {
        ROS_INFO_STREAM("Port was closed for some reason.. Attempting to re-open");
        bittleSerial->open();
    }
    bittleSerial->write(token);
}
