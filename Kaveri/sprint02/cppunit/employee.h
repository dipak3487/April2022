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
    bool readConfig();
   // Config(std::string configFilePath);
    int mymath();
	Config();
    bool setFilePath(std::string path);
    bool readRecords();
    bool readOneRecord();
	bool editRecord();//will update vector record
	bool createRecord();
	bool searchRecord(std::string str);
	bool deleteRecord();
	bool saverecordinjson();
	bool printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY);
	bool getpayrolldetails();
  //  std::string getLogfilePath();

};

class CppUnittest
{
    private:
    //std::string filePath;
    Json::Value unittest;
    Json::Value oneRecord;

    Employee cppemp;
    std::vector<Employee> cpprecords;

    public:
    bool readConfig();
   // Config(std::string configFilePath);
  //  int mymath();
	CppUnittest();
   // bool setFilePath(std::string path);
    bool readRecords();
    bool readOneRecord();
	bool editRecord(std::string code,std::string name,int salary,std::string title);//will update vector record
	bool createRecord(std::string newcode,std::string newname,int newsalary,std::string newtitle);
	bool searchRecord(std::string str);
	bool deleteRecord(std::string str);
	bool saverecordinjson();
	bool printpayslip(int salary,int INCOME_TAX,int PROVISION_FUND,int INSURANCE,int NET_PAY);
	bool getpayrolldetails(std::string code);
  //  std::string getLogfilePath();

};
#endif
