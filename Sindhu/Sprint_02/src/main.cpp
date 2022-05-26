#include<stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;



class Vaccine
{
	int age;
	int temperature;
	int bloodPressure;
	int date_of_dose1[100];
	int date_of_dose2[100];
	char aadhar_no;
	char gender;
	char name[100];
	char mobileNumber[100];
	char vaccine[100];
	char Medical_conditions[100];

	public:
		void getData();
		void addNew_Record();
		void showData();
		void showList();
		void search_Data();
		void search_by_aadhar_no();
    	void search_by_vaccine();
    	void view_all();
		void view_vaccine();
};
	
void Vaccine::getData(){
	cout<<"\t\t\t\t\t\t ENTER THE GIVEN DETAILS";
	cout<<"-----------------------------------------------------------------------";
	cout<<"\n\t\t Enter Name :-  ";
    fgets(name);
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
int main()
{
	int choice = -1;
	do
	{
		cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    
    getch();
    B:
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t----------------------------------------------------------------------------------------------\n";

	return 0;
}
