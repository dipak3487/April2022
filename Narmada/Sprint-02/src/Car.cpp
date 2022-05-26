#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"

// function to display details of the car that was selected by the user
void Car::display_details(int selected_car,Car list[])
{
    // displaying details
    cout<<"The Car you selected is "<<endl;
    cout<<"\t\t\tCompany: "<<list[selected_car].get_maker()<<endl;
    cout<<"\t\t\tModel: "<<list[selected_car].get_model()<<endl;
    cout<<"\t\t\tColor: "<<list[selected_car].get_color()<<endl;

    // using if statement to check if the car is avaliable, if it is, it will display "Status avaliable"
    if (list[selected_car].get_status()==1)
    {
        cout<<"\t\t\tStatus: Avaliable"<<endl;
    }
    // using else if statement to check if car is unavaliable, if it is, it will display "Status unavaliable"
    else if (list[selected_car].get_status()==0)
    {
        cout<<"Status: Unavaliable"<<endl;
    }
    
    
}

// function to return the car type
string Car::get_car_type()
{
    return cartype;
}
// function to set the car type
void Car::set_car_type(string type)
{
    cartype=type;
}
