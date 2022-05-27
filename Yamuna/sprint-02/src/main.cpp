#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "UI.h"
#include "Bus.h"


using namespace std;



int main()
{
	int choice;
	std::vector<Bus> busses;
	int busIndex = 0;
    string name;
	int seatNo;

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
				cout << "RESERVE_SEAT menu is selected" << endl;

				busIndex = 0;
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					cout << "Select " << busIndex << " for : " << endl;
					(*it).displayInformation();
					busIndex++;
				}
				cin >> busIndex;
				
				cout <<"Enter your name :"<<endl;
				cin >> name;

				cout <<"Choose your SeatNo :"<<endl;
				cin >> seatNo;
				
				(busses[busIndex]).reserveSeat(name, seatNo);


				//busses[busIndex].displayInformation();
				//busses[busIndex].reserveSeat();	//this we need to define in Bus class. and call here. 

				break;
			case Menu::SHOW_RESERVATION: 
				cout << "SHOW_RESERVATION menu is selected" << endl;
				break;
			case Menu::SHOW_AVAILABILITY: 
				for(std::vector<Bus>::iterator it = busses.begin(); it != busses.end(); it++)
				{
					(*it).displayInformation();
				}
				break;
			case Menu::CANCEL_RESERVATION: 
				cout << "CANCEL_RESERVATION menu is selected" << endl;
				break;
			case Menu::EXIT: 
				exit(0);
				break;
		}
	}
}
