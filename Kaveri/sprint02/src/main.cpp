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
#include<cstdio>
#include "employee.h"
#include <pthread.h>
#include<fcntl.h>

using namespace std;

Config config;

/*
	function name: parsecommandline
	created on: 25th May 2022
	Description: takes argument 1 (argv[1]) as input and calls the function to parse the input file.

*/

int ParseCommandLine(int argc,char* argv[])
{
	if(argc !=2)
	{
		cout<<"the employee data is not given"<<endl;
		exit(0);
	}
	if(argv[1]!= NULL)
	{
		config.SetFilePath(argv[1]);
	}
	return 0;
}

int change = 0;
pthread_t pthread1;


void* userPreferenceThread(void *arg) {
    char *input = (char *)arg;

    while(true) {
        
        if (access("/tmp/change", F_OK) == 0)
        {
			change = Config::SetUserPreference(1); //nice menu
        }
        else
        {
           change = Config::SetUserPreference(0); //normal menu
        }

        sleep(1);
    }
    return arg;
}

void createUserPreferenceThread() {
    static char *thread_input1 = "User preference thread";
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int flag = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
    if(flag != 0) {
        cout<<" thread can not be created, error number = %d\n"<< flag<<endl;
        exit(0);
    }
}

int main(int argc,char* argv[])
{
	int choice=0;
	ParseCommandLine(argc, argv);

	config.ReadConfig();
	config.ReadRecords();
	
/*
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
	*/
	createUserPreferenceThread();
	cout<<"change value : "<<change<<endl;

	while(1)
	{
			cout<<"1.Create new Employee details"<<endl;
			cout<<"2.Edit Employee details"<<endl;
			cout<<"3.Delete Employee details"<<endl;
			cout<<"4.Search Employee details"<<endl;
			cout<<"5.Get Payroll details and Display details for employee"<<endl;
			cout<<"6.EXIT"<<endl;
	try{
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		if(choice<0)
		{
			throw choice;
		}
	 }
	 catch(int x)
	 {
		 cout<<"enter positive integers only"<<endl;
	 }
		switch(choice)
        {
			case 1:
				if(change == 1)
				{
					config.CreateRecord();
				}
				break;
			case 2:
				if(change == 1)
				{
					config.EditRecord();
				}
				break;
			case 3:
				if(change == 1)
				{
					config.DeleteRecord();
				}
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
		}
	}
	
	return 0;
}
