//
//  Many_Body_Problem.cpp
//  
//
//  Created by Andrew Jackson on 5/5/15.
//
//

#include "Many_Body_Problem.h"

Body::Body(long double initial_velocity_x, long double initial_velocity_y, long double initial_velocity_z, long double initial_position_x, long double initial_position_y, long double initial_position_z, long double mass)
{
    this -> position_x = initial_position_x;
    this -> position_y = initial_position_y;
    this -> position_z = initial_position_z;
    this -> velocity_x = initial_velocity_x;
    this -> velocity_y = initial_velocity_y;
    this -> velocity_z = initial_velocity_z;
    this -> mass = mass;
}

//get and set functions

long double Body::get_mass()
{
    return this -> mass;
}

long double Body::get_position_x()
{
    return this -> position_x;
}

long double Body::get_position_y()
{
    return this -> position_y;
}

long double Body::get_position_z()
{
    return this -> position_z;
}

long double Body::get_velocity_x()
{
    return this -> velocity_x;
}

long double Body::get_velocity_y()
{
    return this -> velocity_y;
}

long double Body::get_velocity_z()
{
    return this -> velocity_z;
}

void Body::set_position_x(long double position_x)
{
    this -> position_x = position_x;
}

void Body::set_position_y(long double position_y)
{
    this -> position_y = position_y;
}

void Body::set_position_z(long double position_z)
{
    this -> position_z = position_z;
}

void Body::set_velocity_x(long double velocity_x)
{
    this -> velocity_x = velocity_x;
}

void Body::set_velocity_y(long double velocity_y)
{
    this -> velocity_y = velocity_y;
}

void Body::set_velocity_z(long double velocity_z)
{
    this -> velocity_z = velocity_z;
}

//other functions

long double Body::Acceleration_x(long double G, long double position_x, long double position_y, long double position_z, long double mass)
{
    return (((G * mass) * (position_x - (this -> position_x)))/pow(sqrt(pow((position_x - this -> position_x),2) + pow((position_y - this -> position_y),2) + pow((position_z - this -> position_z),2)),3));
}

long double Body::Acceleration_y(long double G, long double position_x, long double position_y, long double position_z, long double mass)
{
    return (((G * mass) * (position_y - (this -> position_y)))/pow(sqrt(pow((position_x - this -> position_x),2) + pow((position_y - this -> position_y),2) + pow((position_z - this -> position_z),2)),3));
}

long double Body::Acceleration_z(long double G, long double position_x, long double position_y, long double position_z, long double mass)
{
    return (((G * mass) * (position_z - (this -> position_z)))/pow(sqrt(pow((position_x - this -> position_x),2) + pow((position_y - this -> position_y),2) + pow((position_z - this -> position_z),2)),3));
}

long double Body::Num_Velocity_x(long double Summed_Force_Term_x, long double change_in_time)
{
    return ((Summed_Force_Term_x * change_in_time) + (this -> velocity_x));
}

long double Body::Num_Velocity_y(long double Summed_Force_Term_y, long double change_in_time)
{
    return ((Summed_Force_Term_y * change_in_time) + (this -> velocity_y));
}

long double Body::Num_Velocity_z(long double Summed_Force_Term_z, long double change_in_time)
{
    return ((Summed_Force_Term_z * change_in_time) + (this -> velocity_z));
}

long double Body::Num_Position_x(long double change_in_time)
{
    return (((this -> velocity_x) * change_in_time) + (this -> position_x));
}

long double Body::Num_Position_y(long double change_in_time)
{
    return (((this -> velocity_y) * change_in_time) + (this -> position_y));
}

long double Body::Num_Position_z(long double change_in_time)
{
    return (((this -> velocity_z) * change_in_time) + (this -> position_z));
}