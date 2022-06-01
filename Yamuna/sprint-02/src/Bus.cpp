#include <iostream>
#include<cstring>
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





