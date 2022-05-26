#ifndef BOOKINGS_H
#define BOOKINGS_H
#include<string>
#include<iostream>
#include "Car.h"
using namespace std;
class Bookings
{
    // public functions
    public:
    // set functions for inputs
    void get_booking_info(int info_booking, Bookings list[]);
    void set_firstname(string firstname);
    void set_lastname(string lastname);
    void set_sdate(int date);
    void set_smonth(int month);
    void set_edate(int end);
    void set_emonth(int emonth);

    // set functions for inputs
    string get_firstname();
    string get_lastname();
    int get_sdate();
    int get_smonth();
    int get_edate();
    int get_emonth();

    // private variables
    private:
    string Booking_firstname;
    string Booking_lastname;
    int Booking_date;
    int Booking_month;
    int End_month;
    int End_date;

};
#endif
