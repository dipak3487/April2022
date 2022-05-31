/*
	Filename : employee.h
    Created On : 25th May 2022
    Description : creates the classes and functions and define which files/variable can be accesssed from outside the file  

*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include<jsoncpp/json/json.h>

class Employee
{
public:
    std::string name;
	std::string empCode;
    int salary;
    std::string title;

    Employee() : name(""), empCode(""), salary(0), title("")  {}
    Employee(std::string n, std::string ec, int s, std::string t) : name(n), empCode(ec), salary(s), title(t)  {}
};

class Config
{
    private:
    std::string filePath;
    Json::Value configRoot;
    Json::Value oneEmp;
	//int change;
    Employee emp;
    std::vector<Employee> records;

    private:

    public:
    bool readConfig();
    Config(std::string configFilePath);
	Config();
    bool setFilePath(std::string path);
    bool readRecords();
	//static void SetUserPreference(int f) {change = f; }
    bool readOneRecord();
	bool editRecordInp(std::string code,std::string name,int salary,std::string title);
	bool editRecord();//will update vector record
	bool createRecordInp(std::string newname, std::string newCode, int newsalary, std::string newtitle);
	bool createRecord();
	bool searchRecord();
	bool searchRecordInp(std::string str);
	bool deleteRecord();
	bool deleteRecordInp(std::string code);
	bool getpayrolldetails();
	bool getpayrolldetailsInp(std::string code);
	bool saverecordinjson();
	bool printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY);
  //  std::string getLogfilePath();

};

#endif
