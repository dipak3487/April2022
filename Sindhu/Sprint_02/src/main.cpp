/*
    Filename : main.cpp
    Created On : 25th May 2022
    Description : This file takes the input file and calls the functions the user wants to implement. 
*/
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#include<sstream>
#include <cstring>
#include <sqlite3.h>
#include<memory>
#include<bits/stdc++.h>
#include "vaccine.h"
using namespace std;

int up = 0;
pthread_t pthread1;


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

void Vaccine::menu()
{


    if(up == 0)
    {

    cout<<"\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"<<endl;
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t MAIN MENU";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";

    cout<<"\n\t\t\t\t1: Add New Record"<<endl;
    cout<<"\n\t\t\t\t2: View VACCINE Inventory"<<endl;
    cout<<"\n\t\t\t\t3: View All Citizen Data"<<endl;
    cout<<"\n\t\t\t\t4: Search"<<endl;
    cout<<"\n\t\t\t\t5: Exit"<<endl;

    }

else
{

    cout<<"\t\t\t\t	W	E	L	C	O	M	E	"<<endl;
    cout<<"\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"<<endl;
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t M	  A	I	N 	M	E	N	U";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";

    cout<<"\n\t\t\t\t1: Add New Record"<<endl;
    cout<<"\n\t\t\t\t2: View VACCINE Inventory"<<endl;
    cout<<"\n\t\t\t\t3: View All Citizen Data"<<endl;
    cout<<"\n\t\t\t\t4: Search"<<endl;
    cout<<"\n\t\t\t\t5: Exit"<<endl;
}

}




static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

 

int main(int argc, char** argv)
{
	   int ch;
           createUserPreferenceThread();

           cout<<"createUserpreferenceThread:"<<up<<endl;



	/*cout<<"\t\t\tAdmin Login"<<endl;
	std::string adminid = "admin";
    std::string user;
    std::cout<<"Enter username:"<<std::endl;
    std::cin>>user;
	if(adminid == user)
	{
     const char *mypass="sindhu";
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
//while(1)
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
	             vaccineDB.addNew();
	             vaccineDB.showData();
                 break;
         case 2: 
       	    vaccineDB.view_Vaccine();
                 break;
         case 3:
		   vaccineDB.view_all();
		   //.countRecords();
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
