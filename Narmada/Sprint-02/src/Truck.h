#ifndef TRUCK_H
#define TRUCK_H
#include<string>
#include<iostream>
#include "Vehicle.h"
using namespace std;
class Truck: public Vehicle
{
    // public functions
    public:
    void display_details(int selected_size,Truck list[]);
    void set_size(int siz);
    int get_size();
    // private variables
    private:
    int Truck_size;

};
#endif
