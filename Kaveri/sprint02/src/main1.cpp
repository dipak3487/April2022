/*

    Filename : main.cpp
    Created On : 25th May 2022
    Description : This file takes the input file and calls the functions the user wants to implement. 

*/
#include<iostream>
#include <unistd.h>
#include<fstream>
#include<stdlib.h>
#include <cstring>
//#include <conio.h>
//#include <curses.h>
#include<cstdio>
#include "../include/employee.h"

using namespace std;

Config config;

/*
	function name: parsecommandline
	created on: 25th May 2022
	Description: takes argument 1 (argv[1]) as input and calls the function to parse the input file.

*/

int parsecommandline(int argc,char* argv[])
{
	config.SetFilePath(argv[1]);
	return 0;
}
int main(int argc,char* argv[])
{
	int choice=0;
	parsecommandline(argc, argv);

	config.ReadConfig();
	config.ReadRecords();


	 cout<<"Enter Admin Login Credentials:"<<endl;
	std::string adminid = "ADMIN";
    std::string user;
    std::cout<<"Enter username:"<<std::endl;
    std::cin>>user;
	if(adminid == user)
	{
     const char *mypass="vista";
     char *password=getpass("Enter password: "); 

     if(strcmp(password,mypass)==0) 
	 {
	 	cout <<"Correct password! \n";
	 }
     else
	 {
		cout <<"Invalid password!\n";
	 	exit(0);
	 }
	}
	else
	{
		cout<<"Invalid user"<<endl;
		exit(0);
	}

	while(1)
	{
		cout<<"1.Create new Employee details"<<endl;
		cout<<"2.Edit Employee details"<<endl;
		cout<<"3.Delete Employee details"<<endl;
		cout<<"4.Search Employee details"<<endl;
		cout<<"5.Get Payroll details and Display details for employee"<<endl;
		cout<<"6.EXIT"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		switch(choice)
        {
			case 1:
				config.CreateRecord();
				break;
			case 2:
				config.EditRecord();
				break;
			case 3:
				config.DeleteRecord();
				break;
			case 4:
				config.SearchRecord();
				break;
			case 5:
				config.GetPayrollDetails();
				break;
			case 6:
				exit(0);
			default:
				cout<<"Please enter 1/2/3/4/5/6 only "<<endl;
		//		exit(0);
		}
	}
	return 0;
}
