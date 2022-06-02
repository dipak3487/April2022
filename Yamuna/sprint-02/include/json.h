#ifndef _JSON_FUNCTIONS_H
#define _JSON_FUNCTIONS_H

#include<jsoncpp/json/json.h>
#include<vector>
#include<iostream>

std::vector<Bus> busses;

bool readJsonFile(std::string filePath)
{
	Json::Value jsonRoot;
	Json::Value oneBus;
	Bus busObj;

	std::ifstream ifs(filePath);
	Json::Reader reader;
	reader.parse(ifs, jsonRoot);

	const Json::Value busRecords = jsonRoot["BusRecords"];
	for ( int index = 0; index < busRecords.size(); ++index )
	{
		oneBus = busRecords[index];
		busObj.busNumber = oneBus["busNumber"].asString();
		busObj.busDriver  = oneBus["driver"].asString();
		busObj.journeyDate  = oneBus["journeyDate"].asString();
		busObj.arrivalTime  = oneBus["arrivalTime"].asString();
		busObj.departureTime  = oneBus["departureTime"].asString();
		busObj.fromStation  = oneBus["fromStation"].asString();
		busObj.toStation  = oneBus["toStation"].asString();


		busObj.empty();
		const Json::Value reservations = oneBus["Reservations"];
		for ( int index = 0; index < reservations.size(); ++index )
		{
			busObj.seats[index] = reservations[index].asString();

		}

		busses.push_back(busObj);
	}
	return true;

}

bool writeJsonFile(std::string filePath)
{
	//Json::Value root, content, booking;
	Json::Value root;

	for(auto it=busses.begin(); it!=busses.end(); it++)
	{
		{
			Json::Value content, booking;

			Bus &busObj = *it;
			content.clear();
			content["busNumber"] = busObj.busNumber;
			content["driver"] = busObj.busDriver;
			content["journeyDate"] = busObj.journeyDate ;
			content["arrivalTime"] = busObj.arrivalTime;
			content["departureTime"] = busObj.departureTime;
			content["fromStation"] = busObj.fromStation ;
			content["toStation"] = busObj.toStation;


			content["Reservations"] = Json::arrayValue;
			//booking.clear();
			content["Reservations"].clear();
		//	for ( int index = 0; index < busObj.seats.size(); ++index )
			for ( int index = 0; index < 32; ++index )
			{
				booking = busObj.seats[index].c_str();
				content["Reservations"].append(booking);
			}
			root["BusRecords"].append(content);
		}
	}

	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "   ";
	Json::StreamWriter *writer(builder.newStreamWriter());
	std::ofstream outputFileStream(filePath);
	writer->write(root, &outputFileStream);
	outputFileStream.close();

	return true;
}


#endif
