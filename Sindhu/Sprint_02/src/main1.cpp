#include<stdio.h>
#include <iostream>
#include <string.h>
#include<sstream>
#include <cstring>
#include <sqlite3.h>
using namespace std;



class Vaccine
{
	private:
		int age;
		int temperature;
		int bloodPressure;
		int date_of_dose1[100];
		int date_of_dose2[100];
		string aadhar_no;
		char gender;
		string name;
		string mobileNumber;
		string vaccine;
		char Medical_conditions[100];

	public:
		void getData();//takes data from the user
		void addNew_Record();//data is added to the  database
		void showData();//display data
		void showList();//data list returned when searched
		void search_Data();//data search function
		void search_by_aadhar_no();
		void search_by_vaccine();
		void view_all();//view the entire Citizen database
		void view_vaccine();//operations on the vaccine inventory
};

void menu()
{
    
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t MAIN MENU";
    cout<<"\n\t\t\t------------------------------------------------------------------------------------\n";
    cout<<"\n\t\t01: Add New Record"<<endl;
	cout<<"\n\t\t02: View VACCINE Inventory"<<endl;
    cout<<"\n\t\t03: Search for Citizen Records"<<endl;
	cout<<"\n\t\t04: View All Data"<<endl;
    cout<<"\n\t\t05: Exit"<<endl;
}




void Vaccine::getData(){
	cout<<"\t\t\t\t\t\t ENTER THE GIVEN DETAILS";
	cout<<"-----------------------------------------------------------------------";
	 
   
    cout<<"\n\t\t Enter Name :-  ";
    getline (std::cin,name);
	

    cout<<"\n\t\t Enter Aadhaar no :-  ";
    getline (std::cin,aadhar_no);
	

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

    cout<<"\n\t\t Enter the  Mobile number :- ";
    cin>>mobileNumber;

    cout<<"\n\t\t Enter the vaccine injected :- ";
   cin>>vaccine;



}

void Vaccine::addNew()
{

	temp << "INSERT INTO CITIZEN_RECORDS VALUES ('"<< name <<"', "<< aadhar_no <<",'" << gender <<"', "<< age <<"," << bloodPressure <<","<< temperature <<",'"<<Medical_conditions<<"',"<<mobileNumber<<",'"<< vaccine <<"')";

command=temp.str();
 rc = sqlite3_exec(db,command.c_str(), callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");


    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
  
    
   }
   sqlite3_close(db);
   return 0;
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

	Vaccine obj;
	obj.getData();

	int choice = -1, ch=1;
	do
	{
	cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t----------------------------------------------------------------------------------------------\n";
	}while(ch!=1);
	return 0;
}
