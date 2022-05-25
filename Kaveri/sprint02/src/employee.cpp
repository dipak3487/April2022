#include<iostream>
#include<fstream>
#include<cstring>
#include "employee.h"
#include<memory>
bool Config::setFilePath(std::string path)
{
    filePath = path;
    return true;
}

bool Config::readOneRecord()
{

	emp.name = oneEmp["name"].asString();
	emp.empCode = oneEmp["empCode"].asString();
	emp.salary = oneEmp["salary"].asInt();
	emp.title = oneEmp["title"].asString();
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
int Config::searchRecord()
{
	std::string str1;

	std::cout<<"enter the empCode of the employee"<<std::endl;
	std::cin>>str1;
	
	
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == str1)
		{
				std::cout <<"name of the employee is: \t"<<e.name<< std::endl;
				std::cout<<"the code of the employee is: \t"<<e.empCode<<std::endl;
				std::cout<<"the salary of the employee is: \t"<<e.salary<<std::endl;
				std::cout<<"the title of the employee is: \t"<<e.title<<std::endl;
		}
	}
	return 1;
}
bool Config::saverecordinjson()
{
/*	Json::Value root, content(Json::arrayValue);
//	Json::Value emp;
	content.append(records["name"]);
	content.append(records["empCode"]);
	content.append(records["salary"]);
	content.append(records["title"]);
	root["EmployeeRecords"]=content;
	std::cout << root.toStyledString()<<std::endl;*/
	/*
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "   ";
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	std::ofstream outputFileStream("../config/test.json");
	//Json::Value jsonrecords;
	Json::Value myvect content(Json::arrayValue);;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		myvect.append(it->records);
	}
	writer->write(myvect, &outputFileStream);
*/
    return true;
}
int Config::editRecord()
{
	std::string code;

    std::cout<<"enter the empCode of the employee"<<std::endl;
    std::cin>>code;

	for(auto it=records.begin(); it!=records.end(); it++)
	{
		
		Employee &e = *it;
		if(e.empCode == code)
		{
			std::cout<<"change the name"<<std::endl;
			std::cin>>e.name; 
		//	e.name="c++";	
		}
	}
	saverecordinjson();
	return 0;
}
int Config::createRecord()
{
return 0;

}
int Config::deleteRecord()
{
return 0;

}
int Config::editpayroll()
{
return 0;

}
int Config::printpayslip()
{

return 0;
}

Config::Config()
{
}


