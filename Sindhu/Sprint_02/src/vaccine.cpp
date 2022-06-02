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


//Get Citizen Data from the user with numeric constraint validation for mobile number and aadhar card number
//

void Vaccine::getData(){
	//Input Details of the Citizens administered with the vaccines from the authorised user
	cout<<"\t\t\t\t\t\t ENTER THE GIVEN DETAILS";
	cout<<"-----------------------------------------------------------------------";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	cout<<"\n\t\t Enter Name :-  ";

	std::getline (std::cin,name);


	cout<<"\n\t\t Enter Aadhaar no :-  "; std::getline(std::cin, aadhar_no);
	while((aadhar_no).length() < 12 || (aadhar_no).length() > 12)
	{
		std::cout<<"Aadhaar Card Number can't be lessor more than 12 numbers. Please enter the again"<<std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"\n\t\t Enter Aadhaar no :- ";
		std::getline(std::cin,aadhar_no);
	}

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

	while((mobileNumber).length() < 10|| (mobileNumber).length()> 10)
	{
		std::cout<<"Mobile Number can't be less or more than 10 numbers. Please enter the again"<<std::endl;
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


//
//View Vaccine method definition
//Vaccine operations sub menu to add new record, view the datatable 


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


}
//callback method definition
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

//
//Search Citizen sub menu to choose the search parameter - name, aadhar card number, mobile number
//
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

//
//
//search by name function, user can enter a name to search(case sensitive)
//
void Vaccine::search_name()
{
	string name,data;
	sqlite3* db;

	int rc;

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


	sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_close(db);
}	
//
//
//Implementing search by Aadhar functionality
//Search by aadhar number of the citizen, user can enter an aadhar number to get the required datarecord

void Vaccine::search_aadhar()
{
	string aadhar_no;
	sqlite3* db;

	int rc;
	//
	// Database connection
	//
	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	std::string command;

	//  
	//condition to return the status of the Database Connection
	//
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

	sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_close(db);
}	


//
//
//Implementaion of Search Citizen Records By Mobile Number, user can enter 10 digit mobile number to search
//
void Vaccine::search_mobile()
{
	string mobile_no;
	sqlite3* db;

	int rc;

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


	sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_close(db);
}	

void Vaccine::get_VaccineData()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	cout<<"\n\t\t Enter Vaccine Brand Name :-  ";
	std::getline (std::cin,v_name);


	cout<<"\n\t\t Enter Brand Description  :-  ";
	getline (std::cin,desc);


	cout<<"\n\t\t Enter the Expiry Year :-  ";
	cin>>date;

	cout<<"\n\t\t Enter the  BATCH Number:- ";
	cin>>bno;

	cout<<"\n\t\t Enter the Number of Units :-  ";
	cin>>units;

	cout<<"\n\t\t Enter Backup Stock number if available:-  ";
	cin>>backup;

	cout<<"\n\t\t Enter total Cost:-  ";
	cin>>cost;

}

//
//Implementing Add New Vaccine Funtionality, to add new vaccine records, user/admin can enter in the database any new vaccine added into the vaccine storage
//
//
void Vaccine::addNew_Vaccine()
{

	sqlite3* db;
	char* zErrMsg=0;
	int rc;

	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	std::string command;


	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

	get_VaccineData();  
	temp << "INSERT INTO VACCINE_INVENTORY VALUES ('"<< v_name <<"','" << desc <<"', "<< date <<"," << bno <<","<< units <<","<<backup<<","<<cost<<")";

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
//Implemeting View All Citizen Rocord
void Vaccine:: view_all()
{

	sqlite3* db;

	int rc;
	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	std::string command;

	string query = "SELECT * FROM CITIZEN_RECORDS;";
	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	} else {
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
	sqlite3_close(db);

}
//
//Implemeting View Vaccine Record, will display all the vaccine records from the VACCINE_INVENTORY table
//
//
void Vaccine:: view_Vac()
{

	sqlite3* db;

	int rc;

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
//
//Implementing Add New Citizen Record, user can add new citizen records who are administered with vaccines
//
void Vaccine::addNewCitizen()
{
	sqlite3* db;
	char* zErrMsg=0;
	int rc;

	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	std::string command;


	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

	getData();
	temp << "INSERT INTO CITIZEN_RECORDS VALUES ('"<< name <<"', "<< aadhar_no <<",'"<< gender <<"', "<< age <<"," << bloodPressure <<","<< temperature <<",'"<<Medical_conditions<<"',"<<mobileNumber<<",'"<< vaccine <<"')";

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

// counting datarecords for VACCINE_INVENTORY
int countRecords()
{

	sqlite3* db;
	char* zErrMsg=0;
	int rc;
	int count = 0;


	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	std::string command;


	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

	rc = sqlite3_exec(db, "select count(*) from VACCINE_INVENTORY", callback, &count, &zErrMsg);


	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Records created successfully\n");    
	}
	sqlite3_close(db);
	return 0;

}


//
//
//Implementing showData() to Display Citizen record after the user enters on the command prompt
//

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
	cout<<"\t\t vaccine injected : "<<vaccine<<endl;

}
