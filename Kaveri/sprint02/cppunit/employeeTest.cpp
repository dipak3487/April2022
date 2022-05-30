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
//int Config::mymath()
//{
//	return 2;
//}
/*bool Config::setFilePath(std::string path)
{
    filePath = path;
    return true;
}
*/
/*
filename : readOneRecord
created on : 25th May 2022
Description: reads one record and append it to records vector.

*/

bool CppUnittest::readOneRecord()
{

	cppemp.name = oneRecord["name"].asString();
	cppemp.empCode = oneRecord["empCode"].asString();
	cppemp.salary = oneRecord["salary"].asInt();
	cppemp.title = oneRecord["title"].asString();


	cpprecords.push_back(cppemp);

    return true;
}

/*
filename : readRecords
created on : 25th May 2022
Description: takes the records from json value and ask the readOneRecord function to append them into records vector 
*/

bool CppUnittest::readRecords()
{
    const Json::Value EmpRecords = unittest["EmployeeRecords"];
    for ( int index = 0; index < EmpRecords.size(); ++index )
    {
        oneRecord = EmpRecords[index];
        readOneRecord();
    }
    return true;
}

/*
filename : readConfig
created on : 25th May 2022
Description: takes the input file from filepath and parse it to a json value
*/

bool CppUnittest::readConfig()
{
    //std::ifstream ifs(filePath);
    std::ifstream ifs("employeeRecords.json");
	
    Json::Reader jr;

    jr.parse(ifs, unittest);

    return true;
}

/*
filename : searchRecord
created on : 25th May 2022
Description: searches for an employee record based on the empCode of the employee 
*/

bool CppUnittest::searchRecord(std::string str1)
{
	//std::string str1;

//	std::cout<<"enter the empCode of the employee"<<std::endl;
//	std::cin>>str1;
//	str1="E1003";
	bool result = false;
	std::vector<Employee> :: iterator it;
	//std::cout<<records<<std::endl;
	for( it=cpprecords.begin(); it!=cpprecords.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == str1)
		{
//				std::cout <<"name of the employee is: \t"<<e.name<< std::endl;
//				std::cout<<"the code of the employee is: \t"<<e.empCode<<std::endl;
//				std::cout<<"the salary of the employee is: \t"<<e.salary<<std::endl;
//				std::cout<<"the title of the employee is: \t"<<e.title<<std::endl;
			result = true;
		}
	}
	return result;
}

/*
filename : saverecordinjson
created on : 25th May 2022
Description: saves the records vector in json file 
*/

bool CppUnittest::saverecordinjson()
{
	Json::Value root, content;

	Json::Value emp;
	for(auto it=cpprecords.begin(); it!=cpprecords.end(); it++)
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
	std::ofstream outputFileStream("test.json");
	writer->write(root, &outputFileStream);

    return true;
}

/*
filename : editRecord
created on : 25th May 2022
Description: edits an employee record based on the empCode of the employee 
*/

bool CppUnittest::editRecord(std::string code,std::string name,int salary,std::string title)
{
	//std::string code;
    //std::cout<<"enter the empCode of the employee"<<std::endl;
    //std::cin>>code;
	bool result=false;
	for(auto it=cpprecords.begin(); it!=cpprecords.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == code)
		{
			e.name=name;
			e.salary=salary;
			e.title=title;
			result = true;
		}
	}
	
	saverecordinjson();
	return result;
}

/*
filename : createRecord
created on : 25th May 2022
Description: creates a new employee record when a new employee is added  
*/

bool CppUnittest::createRecord(std::string newcode,std::string newname,int newsalary,std::string newtitle)
{
	std::string name;
    std::string empCode;
    int salary;
    std::string title;
	name=newname;
	empCode=newcode;
	salary=newsalary;
	title=newtitle;
	cpprecords.push_back(Employee(name, empCode, salary, title));


	saverecordinjson();
	
return true;

}
	//Employee create;
//	std::string name;
//	std::string empCode;
//	int salary;
//	std::string title;
/*
	std::cout<<"First name of the Employee is: \t"<<std::endl;
	std::cin>>firstname;
	std::cout<<"last name of the Employee is: \t"<<std::endl;
	std::cin>>lastname;
*/
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

/*
filename : deleteRecord
created on : 25th May 2022
Description: delete an employee record based on the empCode of the employee 
*/

bool CppUnittest::deleteRecord(std::string code)
{
	bool result=false;
//	std::string code;
//	std::cout<<"enter the empCode of the employee"<<std::endl;
//	std::cin>>code;
	for(auto it=cpprecords.begin(); it!=cpprecords.end(); it++)
	{
		Employee &e = *it;
				
				if(e.empCode == code)
				{
					cpprecords.erase(it);
					result = true;
				}
		}
	saverecordinjson();

return result;

}

/*
filename : getpayrolldetails
created on : 25th May 2022
Description: gets the payroll details of an employee and asks the printpayslip function to print all the payroll details of that employee 
*/

bool CppUnittest::getpayrolldetails(std::string code)
{

	int INCOME_TAX = 0;
	int PROVISION_FUND =0;
	int INSURANCE = 0;
	int NET_PAY = 0;
	bool result = false;
//	std::string code;

  //  std::cout<<"enter the empCode of the employee"<<std::endl;
   // std::cin>>code;

	int salary = 0;
	for(auto it=cpprecords.begin(); it!=cpprecords.end(); it++)
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
		printpayslip(salary,INCOME_TAX,PROVISION_FUND,INSURANCE,NET_PAY);
		result = true;
		}
	}
return result;

}

/*
filename : printpayslip
created on : 25th May 2022
Description: prints the all the payrolldetails based on the values given from getpayrollfunction 
*/

bool CppUnittest::printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY)
{

		std::cout << "The base salary of the employee: \t" << salary << std::endl;
		std::cout << "The income tax of  the employee: \t" << INCOME_TAX << std::endl;
		std::cout << "The provision fund the employee: \t" << PROVISION_FUND << std::endl;
		std::cout << "The insurance of the employee:  \t" << INSURANCE << std::endl;
		std::cout << "The net salary the employee receives is \t" << NET_PAY << std::endl;
return true;
}

CppUnittest::CppUnittest()
{
}
