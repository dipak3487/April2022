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
	Json::Value root, content(Json::arrayValue);

	Json::Value emp;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		//content.append("{");
		content.append(e.name);
		content.append(e.empCode);
		content.append(e.salary);
		content.append(e.title);
		//content.append("}");
	}	
	root["EmployeeRecords"]=content;
	
		std::cout << root.toStyledString()<<std::endl;
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "   ";
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	std::ofstream outputFileStream("../config/test.json");
	writer->write(root, &outputFileStream);

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
	Employee create;
	create.name = "Rahul dravid";
	create.empCode = "E1006";
	create.salary = 24555;
	create.title = "Assistant Manager";


	records.push_back(create);


/*	for(auto i=records.cbegin(); i!=records.cend(); i++)
	{
		Employee &e = *i;
		std::cout << *i <<std::endl;
		//std::cout <<"name of the employee is: \t"<<e.name<< std::endl;
				//std::cout<<"the title of the employee is: \t"<<e.title<<std::endl;
	}

*/
	saverecordinjson();
	
return 0;

}
int Config::deleteRecord()
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
	/*for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
				std::cout <<"name of the employee is: \t"<<e.name<< std::endl;
				std::cout<<"the title of the employee is: \t"<<e.title<<std::endl;
	}*/
	saverecordinjson();

return 0;

}
int Config::editpayroll()
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
			 std::cout<<"salary \n"<<e.salary<<std::endl;
			 if(salary < 21000)
			 {
			//	#define INCOME_TAX = 0;
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
		std::cout << "The net salary the employee receives is \n" << NET_PAY << std::endl;
		printpayslip(salary,INCOME_TAX,PROVISION_FUND,INSURANCE,NET_PAY);
		}
	}
return 0;

}
int Config::printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY)
{

		std::cout << "The base salary of the employee: \t" << salary << std::endl;
		std::cout << "The income tax of  the employee: \t" << INCOME_TAX << std::endl;
		std::cout << "The provision fund the employee: \t" << PROVISION_FUND << std::endl;
		std::cout << "The insurance of the employee:  \t" << INSURANCE << std::endl;
		std::cout << "The net salary the employee receives is \t" << NET_PAY << std::endl;
return 0;
}

Config::Config()
{
}


