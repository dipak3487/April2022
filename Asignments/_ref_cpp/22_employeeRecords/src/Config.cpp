#include<iostream>
#include<fstream>
#include "Config.h"

bool Config::setFilePath(std::string path)
{
	filePath = path;
	return true;
}

bool Config::readOneRecord()
{

	std::cout << oneEmp["name"].asString() << std::endl;
	emp.name = "first last";

	//
	//

	records.push_back(emp);

	return true;
}

bool Config::readRecords()
{
	const Json::Value EmpRecords = configRoot["EmployeeRecords"];

	// Iterate over the sequence elements.
	for ( int index = 0; index < EmpRecords.size(); ++index )
	{
		oneEmp = EmpRecords[index];
		readOneRecord();
	}
	return true;
}

bool Config::readConfig()
{
	std::ifstream ifs(filePath);

	Json::Reader jr;

	jr.parse(ifs, configRoot);

	return true;
}

std::string Config::getLogfilePath()
{
	return configRoot["logfile"].asString();
}

Config::Config() : filePath("../config/employeeRecords.json") {};

Config::Config(std::string path) : filePath(path) {};
