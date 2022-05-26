#include<stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <set>
using namespace std;



class Vaccine
{
	int age;
	int temperature;
	int bloodPressure;
	int date_of_dose1[100];
	int date_of_dose2[100];
	char aadhar_no[100];
	char gender;
	char name[100];
	char mobileNumber[100];
	char vaccine[100];
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
    gets(name);
	if(name.strlen==0){
        cout<<"Name cannot be blank"<<endl;}

    cout<<"\n\t\t Enter Aadhaar no :-  ";
    gets(aadhar_no);
	if(aadhar_no.strlen==0){
        cout<<"Aadhaar Number cannot be blank"<<endl;}

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
    gets(mobileNumber);

    cout<<"\n\t\t Enter the vaccine injected :- ";
    gets(vaccine);
	if(vaccine.strlen==0){
        cout<<"Vaccine injected cannot be blank"<<endl;}

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

int main()
{
	int choice = -1;
	do
	{
		cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    
    B:
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t----------------------------------------------------------------------------------------------\n";
	}while(choice!=0);
	return 0;
}
