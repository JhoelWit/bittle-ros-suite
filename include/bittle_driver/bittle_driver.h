#ifndef BITTLE_DRIVER
#define BITTLE_DRIVER


class BittleDriver{
    private:
    float turn_radius_;
    float linear_vel_;

    public:
    // Constructor
    BittleDriver();

    // Destructor
    ~BittleDriver();

    // Set linear speed of the robot
    void set_speed(float speed);

    // Set turn radius of the robot
    void set_turn_radius(float turn_radius);

};

#endif