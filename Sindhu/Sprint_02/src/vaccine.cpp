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


void Vaccine::menu()
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




void Vaccine::getData(){
	cout<<"\t\t\t\t\t\t ENTER THE GIVEN DETAILS";
	cout<<"-----------------------------------------------------------------------";
	 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"\n\t\t Enter Name :-  ";

    std::getline (std::cin,name);
	

    cout<<"\n\t\t Enter Aadhaar no :-  "; std::getline(std::cin, aadhar_no);
    while((aadhar_no).length() <= 15)
				{
					std::cout<<"Aadhaar Card Number can't be less than 16 numbers. Please enter the again"<<std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout<<"\n\t\t Enter Aadhaar no :- ";
					std::getline(std::cin,aadhar_no);
				}
   // getline (std::cin,aadhar_no);
	

    cout<<"\n\t\t Enter the gender (M|F) :-  ";
    cin>>gender;

    cout<<"\n\t\t Enter the  age:- ";
    cin>>age;
        
    cout<<"\n\t\t Enter the  B.P. :-  ";
    cin>>bloodPressure;

    cout<<"\n\t\t Enter the Body temperature:-  ";
    cin>>temperature;
        
    cout<<"\n\t\t Enter Medical Conditions if any :-  ";
    cin>>Medical_conditions;

    cout<<"\n\t\t Enter the  Mobile number :-  "; 
    cin>>mobileNumber;

    while((mobileNumber).length() < 10)
				{
					std::cout<<"Mobile Number can't be less than 10 numbers. Please enter the again"<<std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout<<"\n\t\t Enter Mobile number :- ";
					std::getline(std::cin,mobileNumber);
				}


    cout<<"\n\t\t Enter the vaccine injected :- ";
    cin>>vaccine;

while((vaccine).length() <= 0)
				{
					std::cout<<"Please enter the Vaccine Injected"<<std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    					cout<<"\n\t\t Enter the vaccine injected :- ";
					std::getline(std::cin,vaccine);
				}


}

int password()
{
    char cname[30],pass[20];
    int  i=0,cap=0,capt=0;
    string password;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    cin>>cname;
    //getline(std::cin,cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    cin>>password;
    
    /*while((ch=cin) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }*/
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\tCAPTURE:-> "<<cap<<endl;
    cout<<" Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(cname,"admin")==0) && (strcmp(pass,"Sindhu_06")==0) && cap==capt)
        return 1;
    else
        return 0;
}
void Vaccine::view_Vaccine()
{

int ch;
cout<<"\n\t\t\t*****************************************\n";
cout<<"\t\t\t\t\t\t\t\tVACCINE STATISTICS";
cout<<"\n\t\t\t*****************************************\n\n";
cout<<"\n\t\t1.Add Data ";      
cout<<"\n\t\t2.Current Stock Status"; 
cout<<"\n\t\t3.Back"<<endl;
cin>>ch;

 switch(ch)
    {
    case 1:
        addNew_Vaccine();
        view_Vaccine();
        break;
    case 2:
    	view_Vac();
    	view_Vaccine();
        break;
    case 3:
	menu();
    default:

        cout<<"\nEnter valid option "<<endl;
        menu();
    }

    //getc();
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void Vaccine::Search_Citizen_Records()
{

int ch;
cout<<"\n\t\t\t*****************************************\n";
cout<<"\t\t\t\tSEARCH HERE";
cout<<"\n\t\t\t*****************************************\n\n";
cout<<"\n\t\t1.Search By Name ";      
cout<<"\n\t\t2.Search By Aadhar Card Number"; 
cout<<"\n\t\t3.Search By Mobile Number"; 
cout<<"\n\t\t4.Back"<<endl;
cin>>ch;

 switch(ch)
    {
    case 1:
        
        search_name();
        Search_Citizen_Records();
        break;
    case 2:
    	search_aadhar();
        Search_Citizen_Records();
        break;
    case 3:
	search_mobile();
        Search_Citizen_Records();
    case 4:
    	menu();
    default:

        cout<<"\nEnter valid option "<<endl;
        menu();
    }


}

void Vaccine::search_name()
{
string name,data;
sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"\n\t\t Enter the  name to search:- ";
    std::getline(std::cin, name);
       
    temp << "SELECT * FROM CITIZEN_RECORDS WHERE Name = '"<<name<<"' ;";

    command=temp.str();
    //rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
  
   sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
   sqlite3_close(db);
}	


void Vaccine::search_aadhar()
{
string aadhar_no;
sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"\n\t\t Enter the  Aadhar Number to search:- ";
    cin>>aadhar_no;
    temp << "SELECT * FROM CITIZEN_RECORDS WHERE Aadhar_No = '"<<aadhar_no<<"' ;";

    command=temp.str();
    //rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
  
   sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
   sqlite3_close(db);
}	



void Vaccine::search_mobile()
{
    string mobile_no;
    sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"\n\t\t Enter the  Mobile Number to search:- ";
    cin>>mobile_no;
    temp << "SELECT * FROM CITIZEN_RECORDS WHERE Mobile_No = '"<<mobile_no<<"' ;";

    command=temp.str();
    //rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
  
   sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
   sqlite3_close(db);
}	



		
		
void Vaccine::addNew_Vaccine()
{

sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout<<"\n\t\t Enter Vaccine Brand Name :-  ";
    std::getline (std::cin,v_name);
	

    cout<<"\n\t\t Enter Brand Description  :-  ";
    getline (std::cin,desc);
	

    cout<<"\n\t\t Enter the Expiry Date :-  ";
    cin>>date;

    cout<<"\n\t\t Enter the  BATCH Number:- ";
    cin>>bno;
        
    cout<<"\n\t\t Enter the Number of Units :-  ";
    cin>>units;

    cout<<"\n\t\t Enter Backup Stock number if available:-  ";
    cin>>backup;
        
temp << "INSERT INTO VACCINE_INVENTORY VALUES ('"<< v_name <<"','" << desc <<"', "<< date <<"," << bno <<","<< units <<","<<backup<<")";

command=temp.str();
 rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");    
   }
   sqlite3_close(db);



}
void Vaccine:: view_all()
{

sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    
    string query = "SELECT * FROM CITIZEN_RECORDS;";
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      //return 0;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
sqlite3_close(db);

}


void Vaccine:: view_Vac()
{

sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    
    string query = "SELECT * FROM VACCINE_INVENTORY;";
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      //return 0;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
sqlite3_close(db);

}

void Vaccine::addNew()
{
 sqlite3* db;
    char* zErrMsg=0;
    int rc;
    char *sql;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;
    
    //string query = "SELECT * FROM CITIZEN_RECORDS;";
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      //return 0;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

getData();
temp << "INSERT INTO CITIZEN_RECORDS VALUES ('"<< name <<"', "<< aadhar_no <<",'" << gender <<"', "<< age <<"," << bloodPressure <<","<< temperature <<",'"<<Medical_conditions<<"',"<<mobileNumber<<",'"<< vaccine <<"')";

command=temp.str();
 rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");    
   }
   sqlite3_close(db);

}



void Vaccine::showData()
{

    cout<<"\t\t\t\t DETAILS  ";
    cout<<"\n\t\t\t---------------------------------------------------------------------\n\n";
    cout<<"\t\t Name is: "<<name<<endl;
    cout<<"\t\t Aadhar number is: "<<aadhar_no<<endl;
    cout<<"\t\t Age is "<<age<<endl;
    cout<<"\t\t Gender is : "<<gender<<endl;
    cout<<"\t\t Blood pressure is :"<<bloodPressure<<endl;
    cout<<"\t\t Body temperature is : "<<temperature<<endl;
    cout<<"\t\t Medical Conditions is/are "<<Medical_conditions<<endl;
    cout<<"\t\t Mobile number is: "<<mobileNumber<<endl;
    cout<<"\n\t\t vaccine injected : "<<vaccine<<endl;
    
}
