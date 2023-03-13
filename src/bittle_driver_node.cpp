#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <bittle_driver/bittle_driver.h>

int main(int argc, char **argv)
{
    // Initialize ROS node
    ros::init(argc, argv, "bittle_driver");
    ros::NodeHandle nh("~");

    // Get serial port and baudrate from ROS parameters
    std::string port;
    int baudRate;
    nh.param<std::string>("port", port, "/dev/ttyS0");
    nh.param<int>("baudrate", baudRate, 115200);

    // Instantiate BittleDriver object
    BittleDriver* driver = new BittleDriver(port, baudRate);
    ROS_INFO_STREAM("Bittle driver initialized");

    // Subscribe to cmd_vel topic
    ros::Subscriber sub = nh.subscribe("/cmd_vel", 1, &BittleDriver::cmdVelCallback, driver);

    // Spin
    ros::spin();

    // Delete the driver object
    delete driver;

    return 0;
}
