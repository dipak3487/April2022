#include <iostream>
#include "UI.h"

using namespace std;

Bus& UI::add_new_number_of_bus()
{

	Bus *bus = new Bus;

  cout<<"\n\n\t\t\t\tEnter Bus Number: \t\t";
  cin>>bus->busNumber;

  cout<<"\n\t\t\t\tEnter Driver Name: \t\t";
  cin>>bus->busDriver;

  cout<<"\n\t\t\t\tEnter Date: \t\t\t";
  cin>>bus->journeyDate;


  cout<<"\n\t\t\t\tArrival Time: \t\t\t";
  cin>>bus->arrivalTime;

  cout<<"\n\t\t\t\tDeparture: \t\t\t";
  cin>>bus->departureTime;

  cout<<"\n\t\t\t\tFrom: \t\t\t\t";
  cin>>bus->fromStation;

  cout<<"\n\t\t\t\tTo: \t\t\t\t";
  cin>>bus->toStation;

  bus->empty();
  
  cout<<"\n\n\t\t\t\t\t@@@@@@->New Bus Added Successfully<-@@@@@@\t\t\t";

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
		cout <<"\t\t\t   <><><><><><><><><><><><><><><><><><>\n";
		cout << "\t\t\t     WELCOME TO BUS RESERVATION SYSTEM" << endl;
		cout <<"\t\t\t   <><><><><><><><><><><><><><><><><><>";


		cout<<"\n\n";
		cout<<"\t\t\t\t1.Add New Bus Details\n\n\t\t\t"

			<<"\t2.Seat Reservation\n\n\t\t\t"

			<<"\t3.Show Seat Reservation\n\n\t\t\t"

			<<"\t4.Buses Available \n\n\t\t\t"

			<<"\t5.Cancel Seat Reservation\n\n\t\t\t"

			<<"\t6.Exit";



return true;
}
