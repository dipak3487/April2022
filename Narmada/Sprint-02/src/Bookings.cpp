#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"

// function to display the booking info
void Bookings::get_booking_info(int info_booking, Bookings list[])
{
    cout<<"Your booking details are: "<<endl;
    cout<<"\t\t\tName: "<<list[info_booking-1].get_firstname()<<" "<<list[info_booking-1].get_lastname()<<endl; 
    cout<<"\t\t\tBooking Start Date: "<<list[info_booking-1].get_sdate()<<"-"<<list[info_booking-1].get_smonth()<<endl;
    cout<<"\t\t\tBooking End Date: "<<list[info_booking-1].get_edate()<<"-"<<list[info_booking-1].get_emonth()<<endl;
}
// function to get the first name 
string Bookings::get_firstname()
{
    return Booking_firstname;
}
// function to set the booking id
void Bookings::set_firstname(string firstname)
{
    Booking_firstname = firstname;
}
// function to get the starting booking date
int Bookings::get_sdate()
{
    return Booking_date;
}
// function to set the starting booking date
void Bookings::set_sdate(int start)
{
    Booking_date = start;
}
// function to get the end date for the booking
int Bookings::get_edate()
{
    return End_date;
}
// function to set the end date for the booking
void Bookings::set_edate(int end)
{
    End_date = end;
}
// function to set the start month for the booking
void Bookings::set_smonth(int month)
{
    Booking_month=month;
}
// function to get the start month for the booking
int Bookings::get_smonth()
{
    return Booking_month;
}
// function to get the end month for the booking
int Bookings::get_emonth()
{
    return End_month;
}
// function to set the end month
void Bookings::set_emonth(int emonth)
{
    End_month=emonth;
}
// function to get the last name for the booking
string Bookings::get_lastname()
{
    return Booking_lastname;
}
// function to set the last name for the booking
void Bookings::set_lastname(string lastname)
{
    Booking_lastname=lastname;
}