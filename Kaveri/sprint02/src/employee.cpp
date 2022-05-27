/*

filename: employee.cpp
created on: 25th May2022
Description: executes the files which are asked in main.cpp

*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include "employee.h"
#include<memory>
#include<bits/stdc++.h>

/*
filename : setFilePath
created on : 25th May 2022
Description: sets the input path to the filePath
*/

bool Config::setFilePath(std::string path)
{
    filePath = path;
    return true;
}

/*
filename : readOneRecord
created on : 25th May 2022
Description: reads one record and append it to records vector.

*/

bool Config::readOneRecord()
{

	emp.name = oneEmp["name"].asString();
	emp.empCode = oneEmp["empCode"].asString();
	emp.salary = oneEmp["salary"].asInt();
	emp.title = oneEmp["title"].asString();


	records.push_back(emp);

    return true;
}

/*
filename : readRecords
created on : 25th May 2022
Description: takes the records from json value and ask the readOneRecord function to append them into records vector 
*/

bool Config::readRecords()
{
    const Json::Value EmpRecords = configRoot["EmployeeRecords"];
    for ( int index = 0; index < EmpRecords.size(); ++index )
    {
        oneEmp = EmpRecords[index];
        readOneRecord();
    }
    return true;
}

/*
filename : readConfig
created on : 25th May 2022
Description: takes the input file from filepath and parse it to a json value
*/

bool Config::readConfig()
{
    std::ifstream ifs(filePath);

    Json::Reader jr;

    jr.parse(ifs, configRoot);

    return true;
}

/*
filename : searchRecord
created on : 25th May 2022
Description: searches for an employee record based on the empCode of the employee 
*/

bool Config::searchRecord()
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
	return true;
}

/*
filename : saverecordinjson
created on : 25th May 2022
Description: saves the records vector in json file 
*/

bool Config::saverecordinjson()
{
	Json::Value root, content;

	Json::Value emp;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		
		Employee &e = *it;
		content.clear();	
		content["name"] = e.name;
		content["empCode"]= e.empCode;
		content["salary"]=e.salary;
		content["title"]=e.title;
		root["EmployeeRecords"].append(content);
	}	
	
	//	std::cout << root.toStyledString()<<std::endl;
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "   ";
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	std::ofstream outputFileStream("../config/test.json");
	writer->write(root, &outputFileStream);

    return true;
}

/*
filename : editRecord
created on : 25th May 2022
Description: edits an employee record based on the empCode of the employee 
*/

bool Config::editRecord()
{
	std::string code;
	std::string string1;
	std::string string2;
	std::string string3;
    std::cout<<"enter the empCode of the employee"<<std::endl;
    std::cin>>code;

	for(auto it=records.begin(); it!=records.end(); it++)
	{
		
		Employee &e = *it;
		if(e.empCode == code)
		{
			std::cout<<"do you want to change the name:"<<e.name<<std::endl;
			std::cout<<"enter yes or no"<<std::endl;
			std::cin>>string1;
			if(string1 == "yes")
			{
				std::cout<<"change the name"<<std::endl;
				std::cin>>e.name; 
			}
			std::cout<<"do you want to change the salary:"<<e.salary<<std::endl;
			std::cout<<"enter yes or no"<<std::endl;
			std::cin>>string2;
			if(string2 == "yes")
			{
				std::cout<<"change the salary"<<std::endl;
				std::cin>>e.salary; 
			}
			std::cout<<"do you want to change the title:"<<e.title<<std::endl;
			std::cout<<"enter yes or no"<<std::endl;
			std::cin>>string3;
			if(string3 == "yes")
			{
				std::cout<<"change the title"<<std::endl;
				std::cin>>e.title; 
			}
		}
	}
	saverecordinjson();
	return true;
}

/*
filename : createRecord
created on : 25th May 2022
Description: creates a new employee record when a new employee is added  
*/

bool Config::createRecord()
{
	//Employee create;
	std::string name;
	std::string empCode;
	int salary;
	std::string title;
/*
	std::cout<<"First name of the Employee is: \t"<<std::endl;
	std::cin>>firstname;
	std::cout<<"last name of the Employee is: \t"<<std::endl;
	std::cin>>lastname;
*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << " Name: ";		std::getline(std::cin,name);
	std::cout << " Salary: ";	std::cin >> salary;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << " Emp Code: ";	std::getline(std::cin,empCode);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << " Title: ";	std::getline(std::cin,title);
	
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//	create.name = firstname + " " + lastname;
//	std::cout<<"Name of the Employee is: \t"<<std::endl;
//	std::cin>>create.name;


/*
	std::cout<<"Salary of the Employee is: \t"<<std::endl;
	std::cin>>create.salary;

	std::cout<<"Title of the Employee is: \t"<<std::endl;
	std::cin>>create.title;

	std::cout<<"Code of the Employee is: \t"<<std::endl;
	std::cin>>create.empCode;
	
	
	*/
//	create.name = "Renu Wagh";


	//records.push_back(create);
	records.push_back(Employee(name, empCode, salary, title));


	saverecordinjson();
	
return true;

}

/*
filename : deleteRecord
created on : 25th May 2022
Description: delete an employee record based on the empCode of the employee 
*/

bool Config::deleteRecord()
{
	std::string code;

    std::cout<<"enter the empCode of the employee"<<std::endl;
    std::cin>>code;

	for(auto it=records.begin(); it!=records.end(); it++)
	{
		
		Employee &e = *it;
		if(e.empCode == code)
		{
			records.erase(it);
		}
	}
	saverecordinjson();

return true;

}

/*
filename : getpayrolldetails
created on : 25th May 2022
Description: gets the payroll details of an employee and asks the printpayslip function to print all the payroll details of that employee 
*/

bool Config::getpayrolldetails()
{
	int INCOME_TAX = 0;
	int PROVISION_FUND =0;
	int INSURANCE = 0;
	int NET_PAY = 0;
	std::string code;

    std::cout<<"enter the empCode of the employee"<<std::endl;
    std::cin>>code;

	int salary = 0;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == code)
		{
			 salary = e.salary;
			 //std::cout<<"salary \n"<<e.salary<<std::endl;
			 if(salary < 21000)
			 {
					INCOME_TAX = 0;
			 }
			 else if(salary > 21000 && salary <42000)
			 {
				 INCOME_TAX = 0.05 * salary;
			 }
			 else if(salary > 42000 && salary < 84000)
			 {
				 INCOME_TAX = 0.20 * salary;
			 }
			 else if(salary > 84000)
			 {
				 INCOME_TAX = 0.30 * salary;
			 }
			 else
			 {
				 std::cout<<"edit the salary. salary is defined wrong"<<std::endl;
			 }
			 PROVISION_FUND = 0.12 * salary;

			 INSURANCE = 0.0475 * salary;
		NET_PAY = salary - (INSURANCE + PROVISION_FUND + INCOME_TAX);
		//std::cout << "The net salary the employee receives is \n" << NET_PAY << std::endl;
		printpayslip(salary,INCOME_TAX,PROVISION_FUND,INSURANCE,NET_PAY);
		}
	}
return true;

}

/*
filename : printpayslip
created on : 25th May 2022
Description: prints the all the payrolldetails based on the values given from getpayrollfunction 
*/

bool Config::printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY)
{

		std::cout << "The base salary of the employee: \t" << salary << std::endl;
		std::cout << "The income tax of  the employee: \t" << INCOME_TAX << std::endl;
		std::cout << "The provision fund the employee: \t" << PROVISION_FUND << std::endl;
		std::cout << "The insurance of the employee:  \t" << INSURANCE << std::endl;
		std::cout << "The net salary the employee receives is \t" << NET_PAY << std::endl;
return true;
}

Config::Config()
{
}


