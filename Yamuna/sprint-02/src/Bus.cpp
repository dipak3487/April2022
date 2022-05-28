#include <iostream>
#include "Bus.h"


using namespace std;

bool Bus::displayInformation()
{
	cout << "****************************" << endl;

	cout<<"Bus Number: \t"<<busNumber << endl;
	cout<<"busDriver: \t"<<busDriver << endl;
	cout<<"journeyDate: \t"<<journeyDate << endl;
	cout<<"arrivalTime: \t"<<arrivalTime << endl;
	cout<<"departureTime: \t"<<departureTime << endl;
	cout<<"fromStation: \t"<<fromStation << endl;
	cout<<"toStation: \t"<<toStation << endl;

	return true;
}

bool Bus::empty()
{
	for(int i=0; i<32; i++)
	{
		seats.push_back("Empty");
	}

	return true;
}

bool Bus::reserveSeat(string name,int seatNo)
{

	seats[seatNo] = name;
	return true;


}

 
