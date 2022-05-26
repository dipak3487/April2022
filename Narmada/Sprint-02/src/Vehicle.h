#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>
#include<iostream>
using namespace std;
class Vehicle
{
    // public functions
    public:
    virtual void display_details();
    void set_model(string mod);
    void set_maker(string company);
    void set_color(string colour);
    void set_status(bool stat);
    string get_model();
    string get_maker();
    string get_color();
    bool get_status();
    // private variables
    private:
    string Vehicle_model;
    string Vehicle_maker;
    string Vehicle_color;
    bool Vehicle_status;

};
#endif
