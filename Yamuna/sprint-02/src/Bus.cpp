#include <iostream>
#include <cstring>
#include "Bus.h"


using namespace std;

bool Bus::displayInformation()                                                                
{
	cout << "\n****************************\n" << endl;

	cout<<"BusNumber: \t"<<busNumber << endl;
	cout<<"BusDriver: \t"<<busDriver << endl;
	cout<<"JourneyDate: \t"<<journeyDate << endl;
	cout<<"ArrivalTime: \t"<<arrivalTime << endl;
	cout<<"DepartureTime: \t"<<departureTime << endl;
	cout<<"FromStation: \t"<<fromStation << endl;
	cout<<"ToStation: \t"<<toStation << endl;

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
	if(seatNo>=32)
	{
		return false;

	}
	seats[seatNo] = name;
	return true;


}

bool Bus::cancelSeat(int seatNo)
{
	if(seatNo>=32)
	{
		return false;
	}
	seats[seatNo] ="Empty";

	return true;

}

bool Bus::showReservation()

{
	for(int i=0; i<32; i++)
	{

		if(i%4==0)
		{
			cout<<endl;
		}
		cout<<i<<". "<<seats[i]<<"\t\t"; 

	}


	return true;

}





