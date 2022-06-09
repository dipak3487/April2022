#ifndef _VACCINE_H
#define _VACCINE_H
#include <sqlite3.h>


//Creating Vaccine class
class Vaccine
{
	private:
		int age;
		float temperature;
		int bloodPressure;
		int date;
		int bno;
		int units;
		int backup;
		int cost;
		std::string aadhar_no;
		char gender;
		std::string name;
		std::string v_name;
		std::string desc;
		std::string mobileNumber;
		std::string vaccine;
		char Medical_conditions[100];

	public:
		void Menu();//displayed on the command prompt for the user
		void GetData();//takes Citizen data from the user
		void AddNewCitizen();//data is added to the  database
		void AddNew_Vaccine();//data is added to the  database
		void Get_VaccineData();//takes Vaccine Data from the user
		void ShowData();//display data
		void View_all();//view the entire Citizen records
		void View_Vac();//view the entire vaccine records
		void Search_Citizen_Records();//main menu to access the search options for Citizen table
		void Search_name();//search using name datafield
		void Search_aadhar();//search using the aadhar card number
		void Search_mobile(); //search using mobile number
		void SreateUserPreferenceThread();// function for multithreading
		void View_Vaccine();//operations on the vaccine inventory
		int CountRecords();// count the total records in vaccine table of records
		
};

#endif
