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
#include <pthread.h>
#include<fcntl.h>

using namespace std;

Config config;

/*
	function name: parsecommandline
	created on: 25th May 2022
	Description: takes argument 1 (argv[1]) as input and calls the function to parse the input file.

*/

int parsecommandline(int argc,char* argv[])
{
	config.setFilePath(argv[1]);
	return 0;
}

int change = 0;
pthread_t pthread1;


void* userPreferenceThread(void *arg) {
    char *input = (char *)arg;
	cout<<"Started: %s\n"<< input;

    while(true) {
        
		//if /tmp/nice file exists
        if (access("/tmp/nice", F_OK) == 0)
        {
			// Config::SetUserPreference(1); //nice menu
		   change = 1;
        }
        else
        {
           // Config::SetUserPreference(0); //normal menu
			change = 0;
        }

        sleep(1);
    }
    //pthread_exit(arg);
    return arg;
}

void createUserPreferenceThread() {
    static char *thread_input1 = "User preference thread";
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
    //int rc = pthread_create(&pthread1, NULL, userPreferenceThread, (void *)thread_input1);
    if(rc != 0) {
        printf("Error occurred, thread could not be created, errno = %d\n", rc);
        exit(0);
    }
}

int main(int argc,char* argv[])
{
	int choice=0;
	parsecommandline(argc, argv);

	config.readConfig();
	config.readRecords();
	

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
	
	createUserPreferenceThread();

	while(1)
	{
		cout<<"userpreference"<<change<<endl;
		if(change==1)
		{
			cout<<"1.Create new Employee details"<<endl;
			cout<<"2.Edit Employee details"<<endl;
			cout<<"3.Delete Employee details"<<endl;
		}
		else
		{
			cout<<"4.Search Employee details"<<endl;
			cout<<"5.Get Payroll details and Display details for employee"<<endl;
		}
		cout<<"6.EXIT"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		switch(choice)
        {
			case 1:
				config.createRecord();
				break;
			case 2:
				config.editRecord();
				break;
			case 3:
				config.deleteRecord();
				break;
			case 4:
				config.searchRecord();
				break;
			case 5:
				config.getpayrolldetails();
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
