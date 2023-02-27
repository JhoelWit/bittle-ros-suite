#include <bittle_driver/bittle_driver.h>
#include <iostream> // Used for cout or cin


// Constructor
BittleDriver::BittleDriver(){
    // Constructor implementation
};

BittleDriver::~BittleDriver(){
    // Destructor implementation
}

void BittleDriver::set_speed(float speed){
    linear_vel_ = speed;
}

void BittleDriver::set_turn_radius(float radius){
    turn_radius_ = radius;
}