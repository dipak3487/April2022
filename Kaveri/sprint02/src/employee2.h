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

    Employee emp;
    std::vector<Employee> records;

    private:

    public:
    bool ReadConfig();
    Config(std::string configFilePath);
	Config();
    bool SetFilePath(std::string path);
    bool ReadRecords();
    bool ReadOneRecord();
	bool EditRecordInp(std::string code,std::string name,int salary,std::string title);
	bool EditRecord();//will update vector record
	bool CreateRecordInp(std::string newname, std::string newCode, int newsalary, std::string newtitle);
	bool CreateRecord();
	bool SearchRecord();
	bool SearchRecordInp(std::string str);
	bool DeleteRecord();
	bool DeleteRecordInp(std::string code);
	bool GetPayrollDetails();
	bool GetPayrollDetailsInp(std::string code);
	bool SaveRecordinjson();
	bool printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY);
  //  std::string getLogfilePath();

};

#endif
