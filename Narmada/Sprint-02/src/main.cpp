#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#include"Vehicle.h"
#include"Car.h"
#include"Truck.h"
#include"Bookings.h"




extern void carmenu(Car object[10]);
extern void start_carload(Car object[10]);
extern void truckmenu(Truck Truck_list[]);
extern void start_truckload(Truck list[]);
extern void booking_menu(Bookings list[], int booking_number);
extern void cancel_car_booking(Bookings list[],Car Car_list[]);
extern void cancel_truck_booking(Bookings list[],Truck Truck_list[]);
int main()
{

    // defining object lists 
    Car car_list[10];
    Truck Truck_list[9];
    Bookings Booking_list_car[10];
    Bookings Booking_list_truck[9];

    // initialsing variables
    int car_or_truck=0;
    string decision="yes";
    int book_decision=0;
    int truck_book_decision=0;
    int booking_number=1;
    int booking_truck_number=1;
    int final_decision=0;
    string main=" ";
    // Functions to popuate object lists
    start_carload(car_list);
    start_truckload(Truck_list);


    // while loop used to make sure the program runs until asked to close
    while (decision!="exit")
    {   
        system("clear");
        // assigning values to variables so they reset when loop restarts
        car_or_truck=0;
        book_decision=0;

        // displaying options to choose from
        cout<<"\t\t\t----------------------------------------------\n";
        cout<<"\t\t\tWelcome to the Narmada car rental services ,Choose the vehicle type you would like from the menu : "<<endl;
        cout<<"\t\t\t1. Truck"<<endl;
        cout<<"\t\t\t2. Car"<<endl;
        cout<<"\t\t\t3. Cancel Car Booking"<<endl;
        cout<<"\t\t\t4. Cancel Truck Booking"<<endl;
        cout<<"\t\t\t5. Exit"<<endl;
	cout<<"\t\t\t6. Display All Car Details"<<endl;
	cout<<"\t\t\t7. Display Bill"<<endl;
        
        // taking input
        cout<<"Your Choice: ";
        cin>>car_or_truck;

        // Using while loop for input validation
        while (car_or_truck<1||car_or_truck>5)
        {
            cout<<"Invalid Choice"<<endl;
            cout<<"Please enter choice again: ";
            cin>>car_or_truck;
        }

        // using clear in terminal to clear screen
        system("clear");

        // if statemnent to check what option was chosen by user
        if (car_or_truck==1)
        {
            // displaying truck menu where user can select the size of truck they would like to rent
            truckmenu(Truck_list);
            
            // Taking input for the size selected
            int selected_size;
            cout<<"Your Choice: ";
            cin>>selected_size;

            // input validation using while loop
            while(selected_size<=0||selected_size>=10)
            {
                cout<<"Please Enter Choice Again"<<endl;
                cout<<"Your Choice: ";
                cin>>selected_size;
            }

            // Using clear to clear terminal
            system("clear");

            // using function defined in object class to display details of the truck selected
            Truck_list[selected_size-1].display_details(selected_size-1,Truck_list);

            // if statement to check if the truck is avalaible. If it is, it will offer options
            if (Truck_list[selected_size-1].get_status()==1)
            {
                cout<<"Would you Like to book this one??"<<endl;
                cout<<"Enter 1 for yes, 2 for no: ";
                cin>>book_decision;
            }

            // if the truck isnt avalaible. it will let the user know
            else if (Truck_list[selected_size-1].get_status()==0)
            {
                int cont;
                cout<<"This truck is not avaliable. Please choose another one"<<endl;
                cout<<"Enter any number to continue: ";
                cin>>cont;
            }

            // if the user decides that they would like to book the truck
            if (book_decision==1)
            {
                // function to ask for customers info. 
                booking_menu(Booking_list_truck,selected_size);
                
                // function to show booking info and confirm from the user
                Booking_list_truck[selected_size-1].get_booking_info(selected_size,Booking_list_truck);
                
                // Final booking confirmation
                cout<<"Would you like to finailise your booking (Enter 1 for yes, 2 for no): ";
                cin>>final_decision;

                // if statement to confirm user choice
                if (final_decision==1)
                {
                    cout<<"Your booking has been finalised"<<endl;
                    Truck_list[selected_size-1].set_status(false);
                    cout<<"Enter 1 to return to main menu: "<<endl;
                    cin>>main;
                    system("clear");
                }
            }
        }
        // else if statement used if customer wanted to rent a car
        else if (car_or_truck==2)
        {
            // Declaring variable
            int Selected_Car=0;

            // Function to display the car menu
            carmenu(car_list);
            
            // getting input from user
            cout<<"Your Choice: ";
            cin>>Selected_Car;

            // Using while loop for input validation
            while(Selected_Car<=0||Selected_Car>=11)
            {
                cout<<"Please Enter Choice Again"<<endl;
                cout<<"Your Choice: ";
                cin>>Selected_Car;
            }

            // Clearing Command line
            system("clear");

            // function used to display details of the car selected by user
            car_list[Selected_Car-1].display_details(Selected_Car-1, car_list);

            // if statement to check if the car is avaliable
            if (car_list[Selected_Car-1].get_status()==1)
            {
                // user input 
                cout<<"Would you Like to book this one??"<<endl;
                cout<<"Enter 1 for yes, 2 for no: ";
                cin>>book_decision;
            }

            // else if statement used if the car is unavaliable
            else if (car_list[Selected_Car-1].get_status()==0)
            {
                   int cont;
                cout<<"This car is not avaliable. Please choose another one"<<endl;
                cout<<"Enter any number to continue: ";
                cin>>cont;
            }

            // if user selects yes to booking, this if statement will execute
            if (book_decision==1)
            {
                // Booking menu fucntion used to get info. Function can be found in the function file
                booking_menu(Booking_list_car,Selected_Car);
                
                // function used to display the booking details entered
                Booking_list_car[Selected_Car-1].get_booking_info(Selected_Car,Booking_list_car);

                // asking for final confirmation
                cout<<"Would you like to finailise your booking (Enter 1 for yes, 2 for no): ";
                cin>>final_decision;

                // if statement if the user chooses yes. 
                if (final_decision==1)
                {
                    // Giving Confirmation to user
                    cout<<"Your booking has been finalised"<<endl;
                    cout<<"Enter 1 to return to main menu"<<endl;
                    cin>>main;

                    // setting selected car status to unavailable
                    car_list[Selected_Car-1].set_status(false);

                    // clearing terminal screen
                    system("clear");
                }
                
            }
            // using else if for book decision. If user selects no, the program restarts
            else if (book_decision==2)
            {
                
            }
        }

        // if user selects cancel car booking, the function will run. The function can be found in function.cpp
        else if (car_or_truck==3)
        {
            cancel_car_booking(Booking_list_car, car_list);
        }
        // if user selects cancel truck booking, the function will run. The function can be found in function.cpp
        else if (car_or_truck==4)
        {
            cancel_truck_booking(Booking_list_truck,Truck_list);
        }
        // if user selects exit, the decision string will be changed and the while loop will stop
        else if (car_or_truck==5)
        {
            decision="exit";
        }
    }
    cout<<"Team Narmada" << endl;
}
