/*
Filename : main.cpp
Created On : 25th May 2022
Description : This file takes the input file and calls the functions the user wants to implement. 
The VACCINE MANAGEMENT SYSTEM implements adding Citizen records, Vacccine Records to a SQLITE3 database, the user can view the data added or search from the Citizen record datatable
We have seperated functions to get the user input and insert the data into the database
	void getData();//takes Citizen data from the user
	void addNewCitizen();//data is added to the  database
	void addNew_Vaccine();//data is added to the  database
	void get_VaccineData();//takes Citizen data from the user

Functions for the user menu, showing the inserted data on the console and view data are as follows:
		void menu();
		void showData();//display data
		void view_all();//view the entire Citizen datatable
		void view_Vac();//view the entire Vaccine datatable
		
Functions to execute search, the user can search by string name, aadhar card number (primary key constraint), mobile number(unique constraint)
		void Search_Citizen_Records();//main menu function will hold options to search by name, aadhar card number, mobile number
		void search_name();
		void search_aadhar();
		void search_mobile();
		
We have also used multithreading, with the help of the function void createUserPreferenceThread(), the fucntion checks the existence of the file /temp/nice/ in bin folder
if the file is present the loop conditions present an different menu version, if not the regular menu



 */
 
 

#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstring>
#include <sqlite3.h>
#include <memory>
#include <bits/stdc++.h>
#include "vaccine.h"

using namespace std;

int up;
pthread_t pthread1;

// Implementing Thread  
void* userPreferenceThread(void *arg) {
	char *input = (char *)arg;
	printf("Started: %s\n", input);

	while(true) {

		//if /tmp/nice file exists
		if (access("/tmp/nice", F_OK) == 0)
		{
			// Config::SetUserPreference(1); //nice menu
			up = 1;
		}
		else
		{
			//Config::SetUserPreference(0); //normal menu
			up = 0;
		}

		sleep(1);
	}
	//pthread_exit(arg);
	return arg;
}

// creating UserPreference
void createUserPreferenceThread() {
	static char *thread_input1 = "User preference thread";
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
	if(rc != 0) {
		printf("Error occurred, thread could not be created, errno = %d\n", rc);
		exit(0);
	}
}

//Program Menu for user inputs
// Menu choices to display multithreading
//

void Vaccine::menu()
{


	if(up == 0)//regular menu
	{

		cout<<"\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"<<endl;
		cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
		cout<<"\t\t\t\t MAIN MENU";
		cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";

		cout<<"\n\t\t\t\t1: Add New Citizen Record"<<endl;
		cout<<"\n\t\t\t\t2: VACCINE Inventory"<<endl;
		cout<<"\n\t\t\t\t3: View the Citizen Data"<<endl;
		cout<<"\n\t\t\t\t4: Search from Citizen Records"<<endl;
		cout<<"\n\t\t\t\t5: Exit"<<endl;

	}

	else
	{
		// Second version of the menu to display the use of multithreading 
		//
		cout<<"\t\t\t\t	W	E	L	C	O	M	E	"<<endl;
		cout<<"\n\n\t\t\t\t     VACCINE              MANAGEMENT                SYSTEM  \n\n"<<endl;
		cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
		cout<<"\t\t\t\t M	  A	I	N 	M	E	N	U";
		cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";

		cout<<"\n\t\t\t\t1: Add New citizen Record"<<endl;
		cout<<"\n\t\t\t\t2: VACCINE Inventory"<<endl;
		cout<<"\n\t\t\t\t3: View the Citizen Data"<<endl;
		cout<<"\n\t\t\t\t4: Search from Citizen Records"<<endl;
		cout<<"\n\t\t\t\t5: Exit"<<endl;
	}

}



//
//creating callback

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}


//Driver code for Program
int main(int argc, char** argv)
{
	int ch;
	//Calling the createUserPreference function
	createUserPreferenceThread();

	cout<<"createUserpreferenceThread:"<<up<<endl;

	//
	// Implementation of Login 
	//
	cout<<"\t\t\tAdmin Login"<<endl;
	std::string adminid = "admin";
	std::string user;
	std::cout<<"Enter username:"<<std::endl;
	std::cin>>user;

	//verifying userid
	//
	if(adminid == user)
	{
		const char *mypass="sindhu";
		//
		//Hiding Password
		char *password=getpass("Enter password: "); 

		if(strcmp(password,mypass)==0) 
		{
			cout <<"WELCOME! \n";
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
	//
	//
	//starting of routine
	do
	{
		
     	    Vaccine vaccineDB;
     	    int ch;
            vaccineDB.menu();
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;

      switch(ch)
       {
         case 1: 
	             vaccineDB.addNewCitizen();
	             vaccineDB.showData();
                 break;
         case 2: 
       	    vaccineDB.view_Vaccine();
                 break;
         case 3:
		   vaccineDB.view_all();
                break;
          
        case 4:  
		vaccineDB.Search_Citizen_Records();
		break;
	case 5:
		exit(0);
		break;
         default: 
                  cout<<"\n\n\n\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t****HAVE A NICE DAY*****";
                  exit(0);
       }
      }while(ch!=0);
      return 0;
}
