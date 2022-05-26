#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"
void Vehicle::display_details()
    {

    }
void Vehicle::set_model(string mod)
    {
        Vehicle_model=mod;
    }
void Vehicle::set_maker(string company)
    {
        Vehicle_maker=company;
    }
void Vehicle::set_color(string colour)
    {
        Vehicle_color=colour;
    }
void Vehicle::set_status(bool stat)
    {
        Vehicle_status=stat;
    }
string Vehicle::get_model()
    {
        return Vehicle_model;
    }
string Vehicle::get_maker()
    {
        return Vehicle_maker;
    }
string Vehicle::get_color()
    {
        return Vehicle_color;
    }
bool Vehicle::get_status()
    {
        return Vehicle_status;
    }
