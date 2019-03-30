//
//  Many_Body_Problem.h
//  
//
//  Created by Andrew Jackson on 5/5/15.
//
//

#ifndef ____Many_Body_Problem__
#define ____Many_Body_Problem__

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

class Body
{
    private:
    
    long double velocity_x;
    long double velocity_y;
    long double velocity_z;
    long double position_x;
    long double position_y;
    long double position_z;
    long double mass;
    
    public:
    
    Body(long double velocity_x, long double velocity_y, long double velocity_z, long double position_x, long double position_y, long double position_z, long double mass);
    
    //set functions
    void set_velocity_x(long double velocity_x);
    void set_velocity_y(long double velocity_y);
    void set_velocity_z(long double velocity_z);
    void set_position_x(long double position_x);
    void set_position_y(long double position_y);
    void set_position_z(long double position_z);
    
    //get functions
    long double get_velocity_x();
    long double get_velocity_y();
    long double get_velocity_z();
    long double get_position_x();
    long double get_position_y();
    long double get_position_z();
    long double get_mass();
    
    long double Acceleration_x(long double G, long double position_x, long double position_y, long double position_z, long double mass);
    long double Acceleration_y(long double G, long double position_x, long double position_y, long double position_z, long double mass);
    long double Acceleration_z(long double G, long double position_x, long double position_y, long double position_z, long double mass);
    long double Num_Velocity_x(long double Summed_Force_Term_x, long double change_in_time);
    long double Num_Velocity_y(long double Summed_Force_Term_y, long double change_in_time);
    long double Num_Velocity_z(long double Summed_Force_Term_z, long double change_in_time);
    long double Num_Position_x(long double change_in_time);
    long double Num_Position_y(long double change_in_time);
    long double Num_Position_z(long double change_in_time);
};
#endif /* defined(____Many_Body_Problem__) */

