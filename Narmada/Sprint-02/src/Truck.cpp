#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"
// Function to display the deatils of the truck selected
    void Truck::display_details(int selected_size,Truck list[])
    {
        cout<<"The truck you selected is "<<endl;
        cout<<"\t\t\tSize "<<list[selected_size].get_size()<<" cubic metres"<<endl;

        // if statement to check if the truck is avaliable
        if (list[selected_size].get_status()==1)
        {
            cout<<"\t\t\tStatus: Avaliable"<<endl;
        }
        // else if statement to check if the truck is unavalaible
        else if (list[selected_size].get_status()==0)
        {
            cout<<"Status: Unavaliable"<<endl;
        }
    }
    // function to set the size of the truck
    void Truck::set_size(int siz)
    {
        Truck_size=siz;
    }
    // function to get the size of the truck
    int Truck::get_size()
    {
        return Truck_size;
    }