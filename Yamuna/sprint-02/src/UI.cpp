#include<iostream>
#include "UI.h"

using namespace std;

Bus& UI::add_new_number_of_bus()
{

	Bus *bus = new Bus;

  cout<<"Enter Bus Number: ";

  cin>>bus->busNumber;

  cout<<"\nEnter Driver Name: ";

  cin>>bus->busDriver;

  cout<<"\nEnter Date: ";

  cin>>bus->journeyDate;


  cout<<"\nArrival Time: ";

  cin>>bus->arrivalTime;

  cout<<"\nDeparture: ";

  cin>>bus->departureTime;

  cout<<"\nFrom: \t\t\t";

  cin>>bus->fromStation;

  cout<<"\nTo: \t\t\t";

  cin>>bus->toStation;

  bus->empty();
  
  cout<<"\n\n***New Bus Added Successfully***\t\t\t";

	return *bus;

}

int UI::GetMenuChoice()
{

	int choice = 0;

	while(choice < UI::MinMenu || choice > UI::MaxMenu)
	{

		cout<<"\n\n\n\t\t\t Please Enter your Choice:- ";
		cin >> choice;
	}
	return choice;
}

bool UI::DisplayMainMenu()
{

		cout<<"\n\n\n";
		//   cout << "\n\n \t\tWelcome To Flight Reservation System" << endl << endl;
		cout <<"\t\t\t   <><><><><><><><><><><><><><><><><><>\n";
		cout << "\t\t\t     WELCOME TO BUS RESERVATION SYSTEM" << endl;
		cout <<"\t\t\t   <><><><><><><><><><><><><><><><><><>";


		cout<<"\n\n";
		cout<<"\t\t\t1.Add New Bus Number\n\t\t\t"

			<<"2.Reservation\n\t\t\t"

			<<"3.Show Reservation\n\t\t\t"

			<<"4.Buses Available \n\t\t\t"

			<<"5.Cancel Reservation\n\t\t\t"

			<<"6.Exit";



return true;
}
