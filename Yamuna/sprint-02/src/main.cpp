#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fstream>


#include "UI.h"
#include "Bus.h"
#include"json.h"

using namespace std;

int main(int argc,char*argv[])		
{


	int choice;

	int busIndex = 0;
	string name;
	int seatNo;

	readJsonFile(argv[1]);
	while(1)
	{
		UI::DisplayMainMenu();
		choice = UI::GetMenuChoice();

		switch(choice)
		{
			case Menu::ADD_BUS: 
				busses.push_back(UI::add_new_number_of_bus());
				break;

			case Menu::RESERVE_SEAT: 
				cout << "\n\n\t\t\tRESERVE_SEAT menu is selected" << endl;

				busIndex = 0;
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					cout << "\n\nSelect " << busIndex << " for : " << endl;
					(*it).displayInformation();
					busIndex++;
				}

				cout<<"\nSELECT YOUR BUS FROM THE LIST: ";
				cin >> busIndex;

				cout <<"\n\nEnter your name : ";
				cin >> name;

				cout <<"\n\nChoose your SeatNo : ";
				cin >> seatNo;

				(busses[busIndex]).reserveSeat(name, seatNo);

				cout<<"\n\n\t\t\tYour Seat Booked Successfully, HAPPY JOURNEY!"<<endl;

				break;

			case Menu::SHOW_RESERVATION: 
				cout << "\n\n\t\t\tSHOW_RESERVATION menu is selected" << endl;

				busIndex = 0;
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					cout << "\n\nSelect " << busIndex << " for : " << endl;
					(*it).displayInformation();
					busIndex++;
				
				}

				cout<<"\nSELECT YOUR BUS FROM THE LIST: ";
				cin >> busIndex;

				(busses[busIndex]).showReservation();

				break;

			case Menu::SHOW_AVAILABILITY: 
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					(*it).displayInformation();
				}
				break;

			case Menu::CANCEL_RESERVATION: 
				cout << "CANCEL_RESERVATION menu is selected" << endl;

				busIndex = 0;
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					cout << "\n\nSelect " << busIndex << " for : " << endl;
					(*it).displayInformation();
					busIndex++;
				}

				cout<<"\nSELECT YOUR BUS FROM THE LIST: ";
				cin >> busIndex;

				cout <<"\nChoose your SeatNo : ";
				cin >> seatNo;

				(busses[busIndex]).cancelSeat(seatNo);

				cout<<"\n\t\t\tYour Bus Seat Cancelled Successfully"<<endl;
				break;

			case Menu::EXIT: 
				writeJsonFile(argv[1]);
				exit(0);
				break;
		}
	}
}
