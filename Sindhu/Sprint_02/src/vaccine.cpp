#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstring>
#include <sqlite3.h>
#include<memory>
#include<bits/stdc++.h>
#include <regex>
#include <memory>
#include <bits/stdc++.h>
#include "vaccine.h"

using namespace std;


//
// Define Menu functionality
//
void Vaccine::mainMenu()
{
    int up;
    if (up == 1)
    {
        cout << "\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"
             << endl;
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t             MAIN MENU";
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\t1: Add New Citizen Record" << endl;
        cout << "\n\t\t\t\t2: View VACCINE Inventory" << endl;
        cout << "\n\t\t\t\t3: View All Citizen Details" << endl;
        cout << "\n\t\t\t\t4: Search Citizen" << endl;
        cout << "\n\t\t\t\t5: Exit" << endl;
    }
    else
    {
        cout << "\t\t\t\t	W	E	L	C	O	M	E	" << endl;
        cout << "\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"
             << endl;
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t        M A I N  M E N U ";
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\t1: Add New Citizen Record" << endl;
        cout << "\n\t\t\t\t2: View VACCINE Inventory" << endl;
        cout << "\n\t\t\t\t3: View All Citizen Details" << endl;
        cout << "\n\t\t\t\t4: Search Citizen" << endl;
        cout << "\n\t\t\t\t5: Exit" << endl;
    }
}


//
// Adding New Citizen  
//Get Citizen Data from the user with numeric constraint validation for mobile number and aadhar card number
//

void Vaccine::GetData(){
	//Input Details of the Citizens administered with the vaccines from the authorised user
	cout<<"\t\t\t ENTER THE GIVEN DETAILS";
	cout<<"-----------------------------------------------------------------------";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	cout<<"\n\t\t Enter Name :-  ";

	std::getline (std::cin,name);


	cout<<"\n\t\t Enter Aadhaar no :-  "; std::getline(std::cin, aadhar_no);
	  const regex pattern("^[2-9]{1}[0-9]{3}\\s[0-9]{4}\\s[0-9]{4}$");
	 if(regex_match(mobileNumber, pattern))
	 {
	while((aadhar_no).length() < 12 || (aadhar_no).length() > 12)
	{
		std::cout<<"Aadhaar Card Number can't be lessor more than 12 numbers. Please enter the again"<<std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"\n\t\t Enter Aadhaar no :- ";
		std::getline(std::cin,aadhar_no);
	}}
	
	 else{
	 cout<<"Not valid, Please enter again";
	 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	 cout<<"\n\t\t Enter Aadhar number :- ";
	std::getline(std::cin,mobileNumber);
	 

	}
	
	cout<<"\n\t\t Enter the gender (M|F) :-  ";
	cin>>gender;

	cout<<"\n\t\t Enter the  age:- ";
	cin>>age;

	cout<<"\n\t\t Enter the  Blood Pressure. :-  ";
	cin>>bloodPressure;

	cout<<"\n\t\t Enter the Body temperature:-  ";
	cin>>temperature;

	cout<<"\n\t\t Enter Medical Conditions if any :-  ";
	cin>>Medical_conditions;

	cout<<"\n\t\t Enter the  Mobile number :-  "; 
	cin>>mobileNumber;
	const regex pattern1("(0|91)?[7-9][0-9]{9}");
	 if(regex_match(mobileNumber, pattern1))
	 {
	 while((((mobileNumber).length() < 10|| (mobileNumber).length()> 10)))
	{
		std::cout<<"Mobile Number should be 10 digit, valid number. Please enter the again"<<std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"\n\t\t Enter Mobile number :- ";
		std::getline(std::cin,mobileNumber);

	}	
	 }
	 else{
	 cout<<"Not valid, Please enter again";
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

// View Vaccine method definition
// Vaccine operations sub menu to add new record, view the datatable


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



   void Vaccine::View_Vaccine()
{

	int ch;
	cout<<"\n\t\t\t*****************************************\n";
	cout<<"\t\t\t\t\tVACCINE STATISTICS";
	cout<<"\n\t\t\t*****************************************\n\n";
	cout<<"\n\t\t1.Add Data ";      
	cout<<"\n\t\t2.Current Stock Status"; 
	cout<<"\n\t\t3.Back"<<endl;
	cin>>ch;

	switch(ch)
	{
		case 1:
			AddNew_Vaccine();
			View_Vaccine();
			break;
		case 2:
			View_Vac();
			CountRecords();
			View_Vaccine();
			break;
		case 3:
			Menu();
		default:

			cout<<"\nEnter valid option "<<endl;
			Menu();
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
void Vaccine::SearchCitizenRecords()
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

			Search_name();
			Search_Citizen_Records();
			break;
		case 2:
			Search_aadhar();
			Search_Citizen_Records();
			break;
		case 3:
			Search_mobile();
			Search_Citizen_Records();
			break;
		case 4:
			Menu();
			break;
		default:

			cout<<"\nEnter valid option "<<endl;
			Menu();
	}


}

//
//
//search by name function, user can enter a name to search(case sensitive)
//
void Vaccine::Searchname()
{
	string name,data;
	sqlite3* db;

	int rc;

	rc = sqlite3_open("example.db", &db);
	std::ostringstream temp;
	sqlite3_stmt* stmt2;
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
	//sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_prepare( db, command.c_str() , -1, &stmt2, NULL );//preparing the statement
	sqlite3_step( stmt2 );//executing the statement

	int stat = sqlite3_step(stmt2);
	if (stat == SQLITE_DONE) {
		sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
		cout<<"NAME NOT FOUND IN DATABASE"<<endl;
		
		}
	else
	{	
		sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
		cout<<"SEARCH SUCCESSFUL"<<endl;
				  }
	sqlite3_close(db);
}	
//
//
//Implementing search by Aadhar functionality
//Search by aadhar number of the citizen, user can enter an aadhar number to get the required datarecord

void Vaccine::Searchaadhar()
{
	string aadhar_no;
	sqlite3* db;
	sqlite3_stmt* stmt3;

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

	//sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_prepare( db, command.c_str() , -1, &stmt3, NULL );//preparing the statement
	sqlite3_step( stmt3 );//executing the statement

	int stat = sqlite3_step(stmt3);
	if (stat == SQLITE_DONE) {
		cout<<"AADHAR NOT FOUND IN DATABASE"<<endl;
		
		}
	else
	{	
		sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
		cout<<"SEARCH SUCCESSFUL"<<endl;
				  }
	sqlite3_close(db);
}	


//
//
//Implementaion of Search Citizen Records By Mobile Number, user can enter 10 digit mobile number to search
//
void Vaccine::Searchmobile()
{
	string mobile_no;
	sqlite3* db;
	sqlite3_stmt* stmt4;

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
	//sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
	sqlite3_prepare( db, command.c_str() , -1, &stmt4, NULL );//preparing the statement
	sqlite3_step( stmt4 );//executing the statement

	int stat = sqlite3_step(stmt4);
	if (stat == SQLITE_DONE) {
		cout<<"MOBILE NUMBER NOT FOUND IN DATABASE"<<endl;
		
		}
	else
	{	
		sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
		cout<<"SEARCH SUCCESSFUL"<<endl;
				  }
	sqlite3_close(db);
}	

void Vaccine::GetVaccineData()
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
void Vaccine::AddNewVaccine()
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

	Get_VaccineData();  
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
void Vaccine:: Viewall()
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
void Vaccine:: ViewVac()
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
void Vaccine::AddNewCitizen()
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

	GetData();
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
int Vaccine:: CountRecords()
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

void Vaccine::ShowData()
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
}
