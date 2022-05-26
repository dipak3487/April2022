#ifndef CAR_H
#define CAR_H
#include<string>
#include<iostream>
#include "Vehicle.h"
using namespace std;
class Car: public Vehicle
{
    // public functions
    public:
    void display_details(int selected_car,Car list[]);
    string get_car_type();
    void set_car_type(string type);
    // private variables
    private:
    string cartype;
    
};
#endif
