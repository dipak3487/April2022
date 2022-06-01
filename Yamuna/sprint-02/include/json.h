#ifndef _JSON_FUNCTIONS_H
#define _JSON_FUNCTIONS_H

#include<jsoncpp/json/json.h>
#include<vector>

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

        const Json::Value reservations = jsonRoot["Reservations"];
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
	Json::Value root, content, booking;

	for(auto it=busses.begin(); it!=busses.end(); it++)
	{

		Bus &busObj = *it;
		content.clear();
		content["busNumber"] = busObj.busNumber;
		content["Reservations"] = Json::arrayValue;
		for ( int index = 0; index < busObj.seats.size(); ++index )
		{
			booking = busObj.seats[index].c_str();
			content["Reservations"].append(booking);
		}
		root["BusRecords"].append(content);
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
