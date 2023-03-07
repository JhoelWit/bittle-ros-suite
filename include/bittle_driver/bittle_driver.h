#ifndef BITTLE_DRIVER
#define BITTLE_DRIVER

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <serial/serial.h>
#include <unordered_map>


class BittleDriver{
private:
    int bittleState = 0;
    float turnRadius_;
    float linearVel_;
    serial::Serial bittleSerial;
    std::unordered_map<int, std::string> directions = 
    {
        {1, "kwk"},     //  walk
        {-1, "kbk"},    // move backwards
        {2, "kcrR"},    // crawl right
        {3, "kcrL"},    // crawl left
        {0, "kbalance"} // imu balancing
    };

public:
    // Constructor
    BittleDriver(std::string port="/dev/ttyS0", int baudRate=115200);

    // Destructor
    ~BittleDriver();

    // Set linear speed of the robot
    void setSpeed(float speed);

    // Set turn radius of the robot
    void setTurnRadius(float turn_radius);

    // We'll add a callback for the ROS wrapper
    void cmdVelCallback(const geometry_msgs::Twist::ConstPtr& msg);

    // Serial methods
    void serialWrite(std::string token);

};

#endif