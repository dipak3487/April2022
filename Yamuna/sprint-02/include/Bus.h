#ifndef __BUS_H
#define __BUS_H

#include <string>
#include <vector>

class Bus
{
	public:

	 std::string busNumber;
	 std::string busDriver;
	 std::string journeyDate;
	 std::string arrivalTime;
	 std::string departureTime;
	 std::string fromStation;
	 std::string toStation;
	 std::vector<std::string>seats;

	public:

	bool displayInformation();
	bool empty();
	bool reserveSeat(std::string name,int seatNo);
	bool cancelSeat(int seatNo);
	bool showReservation();
};


#endif
