#include<iostream>
#include<string>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"

// helps user select the option from the list
void carmenu(Car list[])
{
    int num=1;
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\tWelcome to the OOP car rental Company ,Choose the car would like from the menu : "<<endl<<flush;

    // for loop to display the cars that the user can choose from
    for (int i = 0; i < 10; i++)
    {
        cout<<"\t\t\t";
        cout<<"Enter "<<num<<" - To Select "<<list[i].get_maker()<<" "<<list[i].get_model()<<endl<<flush;
        num++;
    }
    
}

// Function to populate the Car class. 
void start_carload(Car list[])
{
    // defining what has to go in the classes
    string Car_list[10]={"Holden","Kia","Mercedes","Audi","Tesla","Mitsibishi","Volkswagun","Toyota","Nissan","Hyundai"};
    string Car_makelist[10]={"Commodore","Sorrento","S-Class","R8","Model 3","Outlander","Beetle","Corolla","Ultima", "Santa Fe"};
    string Car_color[10]={"White","Grey","Red","Yellow","Blue","Black","Purple","Pearl","Purple", "White"};
    string Car_type[10]={"Sedan","SUV","Sedan","Sedan","Hatchback","SUV","Hatchback","Sedan","Hatchback", "SUV"};
    bool Car_stat[10]={1,1,1,1,1,1,1,1,1,1};

    // for loop that populates the classes. 
    for (int i = 0; i < 10; i++)
    {
        list[i].set_maker(Car_list[i]);
        list[i].set_model(Car_makelist[i]);
        list[i].set_color(Car_color[i]);
        list[i].set_car_type(Car_type[i]);
        list[i].set_status(Car_stat[i]);
    }
}

// function to populate the truck class
void start_truckload(Truck list[])
{
    // defining what has to go in the classes
    string truck_color[9]={"White","Grey","Red","Yellow","Blue","Black","Purple","Pearl", "White"};
    int truck_size[9]={14,14,14,46,46,46,56,56,56};
    bool truck_stat[9]={1,1,1,1,1,1,1,1,1};

    // for loop to populate the classes
    for (int i = 0; i < 9; i++)
    {
        list[i].set_size(truck_size[i]);
        list[i].set_status(truck_stat[i]);
    }
}
// function that displays the trucks that user can choose from
void truckmenu(Truck Truck_list[])
{
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\tWelcome to the OOP truck rental company ,Choose the truck size you would like from the menu : "<<endl<<flush;
    cout<<"\t\t\tAll sizes are in cubic meters"<<endl;
    int num=1;

    // for loop to show the options to the user
    for (int i = 0; i < 9; i++)
    {
        cout<<"\t\t\t";
        cout<<"Enter "<<num<<" - To Select size "<<Truck_list[i].get_size()<<endl<<flush;
        num++;
    }
}
// function that grabs the booking details from the user
void booking_menu(Bookings list[], int booking_number)
{
    // declaring variables
    string firstname,lastname;
    int start_date,start_month,end_date, end_month;

    // asking user for their first name
    cout<<"Please Enter Your first name: ";
    cin>>firstname;
    // setting the users first name for the booking
    list[booking_number-1].set_firstname(firstname);
    
    // asking user for last name
    cout<<"Please Enter Your last name: ";
    cin>>lastname;
    // setting the users last name for the booking
    list[booking_number-1].set_lastname(lastname);

    // asks for the date that the booking should start on
    cout<<"Enter Booking Start date : ";
    cin>>start_date;

    // validates the the date
    while (start_date<1||start_date>31)
    {
        cout<<"Wrong Entry, Please enter again: ";
        cin>>start_date;
    }
    // sets the start date
    list[booking_number-1].set_sdate(start_date);

    // asks for the month that the booking should start on
    cout<<"Enter Booking Start month: ";
    cin>>start_month;
    // validates if the month is valid
    while (start_month<1||start_month>12)
    {
        cout<<"Wrong Entry, Please enter again: ";
        cin>>start_month;
    }

    // sets the month for the user
    list[booking_number-1].set_smonth(start_month);
    
    // asks for the booking end date
    cout<<"Enter Booking end date : ";
    cin>>end_date;

    // validates the end date
    while (end_date<1||end_date>31)
    {
        cout<<"Wrong Entry, Please enter again: ";
        cin>>end_date;
    }

    // sets the end date
    list[booking_number-1].set_edate(end_date);

    // asks for the booking end month
    cout<<"Enter Booking end month: ";
    cin>>end_month;

    // validates the month
    while (end_month<1||end_month>12)
    {
         cout<<"Wrong Entry, Please enter again: ";
        cin>>end_month;
    }
    // sets the end month
    list[booking_number-1].set_emonth(end_month);
    
}

// function to cancel the car booking
void cancel_car_booking(Bookings list[], Car Car_list[])
{
    // declaring variables
    int num=1,choice,cancel_decision,return_num;
    bool dec;

    // for loop to check if there are any bookings
    for (int i = 0; i < 10; i++)
    {
        // if statement that changes the bool value if there are no bookings
        if (Car_list[i].get_status()==false)
        {
            dec=true;
        }
        
    }
    // if statement that checks if there are any bookings
    if (dec==true)
    {
        // for loop to display if there are any bookings to cancel
        for (int i = 0; i < 10; i++)
        {
            // if statment that displays the car if it is unavailable
            if(Car_list[i].get_status()==false)
            {
                cout<<"\t\t\t";
                cout<<"Enter "<<i+1<<" - To Select "<<Car_list[i].get_maker()<<" "<<Car_list[i].get_model()<<endl<<flush;
                num++;
            }
        }
        // asks user what booking they want to cancel if there are any
        cout<<"Your Choice: ";
        cin>>choice;
        choice=choice-1;

        // asks for confimation
        cout<<"Are you sure you want to cancel the booking (enter 1 for yes, 2 for no): ";
        cin>>cancel_decision;
        // validates that the input is correct
        while (cancel_decision<1||cancel_decision>2)
        {
            cout<<"invalid choice"<<endl;
            cout<<"Your Choice: ";
            cin>>cancel_decision;
        }

        // sets the status of the car to available
        Car_list[choice].set_status(true);
    }
    // else statement to display if there are no bookings
    else
    {
        cout<<"There are no bookings"<<endl;
        cout<<"Enter any number to return: ";
        cin>>return_num;
    }
    
    
}

// function to cancel the truck booking
void cancel_truck_booking(Bookings list[], Truck Truck_list[])
{
    // declaring the variables
    int num=1,choice,cancel_decision,return_num;
    bool dec;
    // for loop to check if there are any bookings
    for (int i = 0; i < 10; i++)
    {
        // if statment that changes the bool value if there are any bookings
        if (Truck_list[i].get_status()==false)
        {
            dec=true;
        }
        
    }
    // if statment to check if there are any bookings
    if (dec==true)
    {
        // for loop to list any bookings that may be there
        for (int i = 0; i < 10; i++)
        {
            // if statement to display any bookings that may be there
            if(Truck_list[i].get_status()==false)
            {
                cout<<"\t\t\t";
                cout<<"Enter "<<i+1<<" - To Select "<<Truck_list[i].get_maker()<<" "<<Truck_list[i].get_model()<<endl<<flush;
                num++;
            }
        }
        // asks user for input
        cout<<"Your Choice: ";
        cin>>choice;
        choice=choice-1;

        // asks for confimation
        cout<<"Are you sure you want to cancel the booking (enter 1 for yes, 2 for no): ";
        cin>>cancel_decision;

        // while loop to check for input validation
    while (cancel_decision<1||cancel_decision>2)
    {
        cout<<"invalid choice"<<endl;
        cout<<"Your Choice: ";
        cin>>cancel_decision;
    }

    // sets the status of the car to avalaible
    Truck_list[choice].set_status(true);
    }
    // else statement to display a message if there are no bookings
    else
    {
        cout<<"There are no bookings"<<endl;
        cout<<"Enter any number to return: ";
        cin>>return_num;
    }
}