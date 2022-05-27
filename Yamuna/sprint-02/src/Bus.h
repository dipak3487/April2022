#ifndef __BUS_H
#define __BUS_H

#include <string>
#include <vector>

class Bus
{
	public:
	 //char bus_number[5], bus_driver[10], bus_date[12],bus_arrival[8], bus_depart[8], b_from[10], b_to[10], bus_seat[8][4][10];
	 std::string busNumber;
	 std::string busDriver;
	 std::string journeyDate;
	 std::string arrivalTime;
	 std::string departureTime;
	 std::string fromStation;
	 std::string toStation;
	 std::vector<std::string> seats;

	public:

	//TODO: std::string getBusNumber(), setBusNumber(std::string), etc

	bool displayInformation();
	bool empty();
};


#endif
