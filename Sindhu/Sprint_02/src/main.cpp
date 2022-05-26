#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;



class Vaccine
{
	int age;
	int temperature;
	int bloodPressure;
	int date_of_dose1[100];
	int date_of_dose2[100];
	char citizenship_number;
	char gender;
	char name[100];
	char mobileNumber[100];
	char vaccine[100];

	public:
		void getData();
		void addNew_Record();
		void showData();
		void showList();
		void search_Data();
		void search_by_citizenship_no();
    	void search_by_vaccine();
    	void view_all();
		void view_vaccine();
};
	


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
