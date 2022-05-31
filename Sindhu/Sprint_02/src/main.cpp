/*
    Filename : main.cpp
    Created On : 25th May 2022
    Description : This file takes the input file and calls the functions the user wants to implement. 
*/

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



static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

/*
void menu()
{
    
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t MAIN MENU";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\n\t\t01: Add New Record"<<endl;
    cout<<"\n\t\t02: View VACCINE Inventory"<<endl;
    cout<<"\n\t\t03: View All Citizen Data"<<endl;
    cout<<"\n\t\t04: Exit"<<endl;
}
*/


int main(int argc, char** argv)
{

     Vaccine vaccineDB;
     int k=3;

     int ch;
      do{

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
                break;
          
          case 4:  
		   vaccineDB.Search_Citizen_Records();
		break;
	case 5:
		exit(0);
		break;
<<<<<<< HEAD
=======

         case 0:  
                    exit(0);
	
>>>>>>> f3ee2194e090b1d1a4bc21f34d9b23747bc4d546
         default: 
                  cout<<"\n\n\n\t\t\tTHANK YOU!!";
                  cout<<"\n\n\t\t****HAVE A NICE DAY*****";
                  exit(0);
       }
      }while(ch!=0);
      return 0;
}
