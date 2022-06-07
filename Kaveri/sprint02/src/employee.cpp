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
#define MIN_NAME_LENGTH 4
#define MIN_SALARY 1000
#define MIN_TITLE_LENGTH 4
#define EMPCODE_LENGTH 5
#define PF_Percentage 0.12
#define Insurance_Percentage 0.0475
#define IT_LessThan21K 0
#define IT_21KTo42K 0.05
#define IT_42KTo84K 0.20
#define IT_GreaterThan84K 0.30
/*
filename : SetFilePath
created on : 25th May 2022
Description: sets the input path to the filePath string.
return true on success, and return false in case of failure.
*/
bool Config::SetFilePath(std::string path)
{
    filePath = path;
    return true;
}

/*
filename : ReadOneRecord
created on : 25th May 2022
Description: reads one employee's record and append it to records vector.
return true on success, and return false in case of failure.
*/

bool Config::ReadOneRecord()
{

	emp.name = oneEmp["name"].asString();
	emp.empCode = oneEmp["empCode"].asString();
	emp.salary = oneEmp["salary"].asInt();
	emp.title = oneEmp["title"].asString();


	records.push_back(emp);

    return true;
}

/*
filename : ReadRecords
created on : 25th May 2022
Description: takes the records from json value and calls the ReadOneRecord function to append them into records vector 
return true on success, and return false in case of failure.
*/

bool Config::ReadRecords()
{
    const Json::Value EmpRecords = configRoot["EmployeeRecords"];
    for ( int index = 0; index < EmpRecords.size(); ++index )
    {
        oneEmp = EmpRecords[index];
        ReadOneRecord();
    }
    return true;
}

/*
filename : ReadConfig
created on : 25th May 2022
Description: takes the input file path from filepath string and parse it to a json value
return true on success, and return false in case of failure.
*/

bool Config::ReadConfig()
{
    std::ifstream ifs(filePath);

    Json::Reader jr;

    jr.parse(ifs, configRoot);
	ifs.close();
	return true;
}

/*
filename : SearchRecordInpi
created on : 25th May 2022
Description: It takes the empcode of an employee gives it to the records vector and store the vector in the json file given in saverecordinjson file.
return true on success, and return false in case of failure.
*/
bool Config::SearchRecordInp(std::string str)
{
	bool search = false;
	std::vector<Employee> :: iterator it;
	for(it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == str)
		{
				std::cout <<"\n \t Name of the employee is: \t"<<e.name<< std::endl;
				std::cout<<"\t Code of the employee is: \t"<<e.empCode<<std::endl;
				std::cout<<"\t Salary of the employee is: \t"<<e.salary<<std::endl;
				std::cout<<"\t Title of the employee is: \t"<<e.title<<std::endl;
				search = true;
				return true;
		}
	}
	if(search == false)
	{
		std::cout<<"The employee code is not present in our system"<<std::endl;
	}
	return false;
}


/*
filename : SearchRecord
created on : 25th May 2022
Description: It asks the user to enter the empcode of an employee and calls the function SearchRecordInp with the details the user gave to the function.
return true on success, and return false in case of failure.
*/
bool Config::SearchRecord()
{
	std::string str1;

	std::cout<<"Enter the empCode of the employee"<<std::endl;
	std::cin>>str1;
	
	SearchRecordInp(str1);	
	return true;
}

/*
filename : SaveRecordinjson
created on : 25th May 2022
Description: Saves the records vector in json file. 
*/

bool Config::SaveRecordinjson()
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
	//std::ofstream outputFileStream(filePath);
	std::ofstream outputFileStream("../InputFiles/test.json");
	writer->write(root, &outputFileStream);
	outputFileStream.close();
    return true;
}

/*
filename : EditRecordInp
created on : 25th May 2022
Description: It takes the details of an employee and checks whether changes have been made or not, if changes are made we edit them and gives it to the records vector and store the vector in the json file given in saverecordinjson file.
return true on success, return false in case of failure.
*/

bool Config::EditRecordInp(std::string code,std::string name,int salary,std::string title)
{
	bool result = false;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == code)
		{
			if(name.length() >= MIN_NAME_LENGTH)
			{
				e.name=name;
			}
			if(salary >= MIN_SALARY)
			{
				e.salary=salary;
			}
			if(title.length() >= MIN_TITLE_LENGTH)
			{
				e.title=title;
			}
			result =true;
		}
	}
	if(result == false)
	{
		std::cout<<"\t The employee code is not present in the system"<<std::endl;
	}
	SaveRecordinjson();
    for(auto it=records.begin(); it!=records.end(); it++)
    {
        Employee &e = *it;
        if(e.empCode == code)
        {
				std::cout<<"\t The edited record details are:"<<std::endl;
                std::cout <<"\t Name of the employee is: \t"<<e.name<< std::endl;
                std::cout<<"\t Code of the employee is: \t"<<e.empCode<<std::endl;
                std::cout<<"\t Salary of the employee is: \t"<<e.salary<<std::endl;
                std::cout<<"\t Title of the employee is: \t"<<e.title<<std::endl;
        }

    }


return result;
}

/*
filename : EditRecord
created on : 25th May 2022
Description: It asks the user to enter the empcode and ask the user to enter the details of an employee the user wants to edit and calls the EditRecordInp function.
return true on success, return false in case of failure.
*/

bool Config::EditRecord()
{
	std::string code;
	std::string string1;
	std::string string2;
	std::string string3;
    std::cout<<"Enter the empCode of the employee"<<std::endl;
    std::cin>>code;
	std::string editname=" ";
	std::string edittitle=" ";
	int editsalary=0;
			std::cout<<"Do you want to change the name:"<<std::endl;
			std::cout<<"enter yes or no:"<<std::endl;
			std::cin>>string1;
			if(string1 == "yes")
			{
				std::cout<<"Change the name:"<<std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";		
				std::getline(std::cin,editname);
				while((editname).length() < MIN_NAME_LENGTH)
				{
					std::cout<<"Name can't be less than 4 letters.Please enter the name again:"<<std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Name: ";		
					std::getline(std::cin,editname);
				}
			}
			std::cout<<"Do you want to change the salary:"<<std::endl;
			std::cout<<"enter yes or no:"<<std::endl;
			std::cin>>string2;
			if(string2 == "yes")
			{
				std::cout<<"Change the salary:"<<std::endl;
				std::cout<<"Salary:";	
				std::cin>>editsalary; 
				while(editsalary<MIN_SALARY)
				{
					std::cout<<"Salary can not be less than 1000. Enter the salary again:"<<std::endl;
					std::cout<<"Salary:";	
					std::cin>>editsalary; 
				}
			}
			std::cout<<"Do you want to change the title:"<<std::endl;
			std::cout<<"enter yes or no:"<<std::endl;
			std::cin>>string3;
			if(string3 == "yes")
			{
				std::cout<<"Change the title:"<<std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Title: ";		
				std::getline(std::cin,edittitle);
				while((edittitle).length() < MIN_TITLE_LENGTH)
				{
					std::cout<<"Employee title can't be less than 4 letters.Please enter the title again:"<<std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Title: ";	
					std::getline(std::cin,edittitle);
				}
			}
		EditRecordInp(code,editname,editsalary,edittitle);
	return true;
}


/*
filename : CreateRecordInp
created on : 25th May 2022
Description: It takes all the details(name,empCode,salary,title) of an employee, gives it to the records vector and store the vector in the json file given in saverecordinjson file.
return: true when success, false when failed to run.
*/
bool Config::CreateRecordInp(std::string newname, std::string newempCode, int newsalary, std::string newtitle)
{
	std::string name;
    std::string empCode;
    int salary;
	int flag=0;
    std::string title;
	try
	{
	if(newname.length()<MIN_NAME_LENGTH || newsalary < MIN_SALARY || newtitle.length() < MIN_TITLE_LENGTH || newempCode.length()!=EMPCODE_LENGTH)
    {
		throw flag;
    }	
    else
    {
    name=newname;
    empCode=newempCode;
    salary=newsalary;
    title=newtitle;
    records.push_back(Employee(name, empCode, salary, title));
	for(auto it=records.begin(); it!=records.end(); it++)
        {
            Employee &e = *it;
            if(e.empCode == newempCode)
            {
				SaveRecordinjson();
                std::cout <<"\t Name of the employee is: \t"<<e.name<< std::endl;
                std::cout<<"\t Code of the employee is: \t"<<e.empCode<<std::endl;
                std::cout<<"\t Salary of the employee is: \t"<<e.salary<<std::endl;
                std::cout<<"\t Title of the employee is: \t"<<e.title<<std::endl;
				return true;
            }
        } 
	}
	}
	catch(int x)
	{
		std::cout<<"\t Employee details are not valid. " <<std::endl;
		return false;
	}
return false;
}


/*
filename : CreateRecord
created on : 25th May 2022
Description: It asks the user to enter all the details(name,empCode,salary,title) of an employee and calls the function CreateRecordInp with the details the user gave to the function.  
return: true when success, false when failed to run.
*/
bool Config::CreateRecord()
{
	
	std::string name;
	std::string empCode;
	int salary;
	std::string title;

	while(1)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout <<"Employee Name: ";		
		std::getline(std::cin,name);
	while(name.length() < MIN_NAME_LENGTH)
	{
		std::cout<<"Name cannnot be less than 4 letters.Please enter the name again."<<std::endl;	
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		std::cout<<"Employee Name: ";
		std::getline(std::cin,name);
	}

	std::cout <<"Employee Salary: ";	
	std::cin >> salary;
	while(salary< MIN_SALARY)
	{
		std::cout<<"Salary can not be less than 1,000.Please enter the salary again: "<<std::endl;
		std::cout<<"Employee Salary: ";
		std::cin>>salary;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout <<"Employee Code: ";
	std::getline(std::cin,empCode);
	while(empCode.length()!= EMPCODE_LENGTH)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout <<"Invalid Emp Code.Please enter Emp Code of length 5. "<<std::endl;
		std::cout <<"Employee Code: ";	
		std::getline(std::cin,empCode);
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout <<"Employee Title: ";	
	std::getline(std::cin,title);
	while(title.length() < MIN_TITLE_LENGTH)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout <<"Invalid title.Please enter Employee title having length more than 4 letters. " <<std::endl;
		std::cout <<"Employee Title: ";	
		std::getline(std::cin,title);
	}
	break;
	}
	
Config::CreateRecordInp(name, empCode,  salary, title);
	
return true;

}

/*
filename : DeleteRecordInp
created on : 25th May 2022
Description: It takes employee code as a parameter and deletes the employee details in records vector and calls the saverecordinjson file to save the updated records in json file.
return true on success, return false in case of failure.
*/
bool Config::DeleteRecordInp(std::string code)
{
	bool result = false;
	for(auto it=records.begin(); it!=records.end()+1; it++)
	{
		Employee &e = *it;
		if(e.empCode == code)
		{
			records.erase(it);
			result = true;
		}
	}
		std::cout<<"123"<<std::endl;
	if(result == false)
	{
		std::cout<<"\t The employee code is not in the employee management system."<<std::endl;
	}

	for(auto it=records.begin(); it!=records.end(); it++)
    {

        Employee &e = *it;
        if(e.empCode == code)
        {
            std::cout<<"\t \t Delete record failed or duplicate employee code is present"<<std::endl;

        }
    }
			SaveRecordinjson();

return result;
}

/*
filename : DeleteRecord
created on : 25th May 2022
Description: It asks user to enter the empcode of an employee and calls the DeleteRecordInp function.
return true on success, return false in case of failure.
*/
bool Config::DeleteRecord()
{
	std::string code;

    std::cout<<"Enter the empCode of the employee"<<std::endl;
    std::cin>>code;

	DeleteRecordInp(code);
return true;

}

/*
filename : GetPayrollDetailsInp
created on : 25th May 2022
Description: It takes the details from user and calculates the payroll details and calls the PrintPaySlip function to display all the payroll details. 
return true on success, return false in case of failure.
*/

bool Config::GetPayrollDetailsInp(std::string code)
{
	int INCOME_TAX = 0;
	int PROVISION_FUND =0;
	int INSURANCE = 0;
	int NET_PAY = 0;
	int salary = 0;
	bool result = false;
	for(auto it=records.begin(); it!=records.end(); it++)
	{
		Employee &e = *it;
		if(e.empCode == code)
		{
			 salary = e.salary;
			 
			 if(salary < 21000)
			 {
					INCOME_TAX = IT_LessThan21K;
			 }
			 else if(salary > 21000 && salary <42000)
			 {
				 INCOME_TAX = IT_21KTo42K * salary;
			 }
			 else if(salary > 42000 && salary < 84000)
			 {
				 INCOME_TAX = IT_42KTo84K * salary;
			 }
			 else if(salary > 84000)
			 {
				 INCOME_TAX = IT_GreaterThan84K * salary;
			 }
			 else
			 {
				 std::cout<<"edit the salary. salary is defined wrong"<<std::endl;
			 }
			 PROVISION_FUND = PF_Percentage * salary;

			 INSURANCE = Insurance_Percentage * salary;
		NET_PAY = salary - (INSURANCE + PROVISION_FUND + INCOME_TAX);
		result = true;
		PrintPaySlip(salary,INCOME_TAX,PROVISION_FUND,INSURANCE,NET_PAY);
		}
	}
	return result;
}

/*
filename : GetPayrollDetails
created on : 25th May 2022
Description: It asks user to enter the empcode and calls the GetPayrollDetailsInp function.
return true on success, return false in case of failure.
*/

bool Config::GetPayrollDetails()
{
	std::string code; 

    std::cout<<"Enter the empCode of the employee"<<std::endl;
    std::cin>>code;
	
	GetPayrollDetailsInp(code);
return true;

}

/*
filename : PrintPaySlip
created on : 25th May 2022
Description: Prints all the payrolldetails based on the values given from GetPayrollDetailsInp function.
*/

bool Config::PrintPaySlip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY)
{

		std::cout << " \t The base salary of the employee: \t" << salary << std::endl;
		std::cout << " \t The income tax of  the employee:  \t" << INCOME_TAX << std::endl;
		std::cout << " \t The provision fund the employee:  \t" << PROVISION_FUND << std::endl;
		std::cout << " \t The insurance of the employee:  \t" << INSURANCE << std::endl;
		std::cout << " \t The net salary the employee receives is: \t" << NET_PAY << std::endl;
return true;
}

Config::Config()
{
	std::cout<<"\n \t *** Welcome to Employee Management System *** "<<std::endl;
}
Config::~Config()
{
	std::cout<<"\n \t *** Thank you for using Employee Management System *** "<<std::endl;
}
