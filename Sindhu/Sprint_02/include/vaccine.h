#ifndef _VACCINE_H
#define _VACCINE_H
#include <iostream>
#include <sqlite3.h>


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
		void AddNewVaccine();//data is added to the  database
		void GetVaccineData();//takes Vaccine Data from the user
		void ShowData();//display data
		void Viewall();//view the entire Citizen records
		void ViewVac();//view the entire vaccine records
		void SearchCitizen_Records();//main menu to access the search options for Citizen table
		void Searchname();//search using name datafield
		void Searchaadhar();//search using the aadhar card number
		void Searchmobile(); //search using mobile number
		void createUserPreferenceThread();// function for multithreading
		void ViewVaccine();//operations on the vaccine inventory
		int CountRecords();// count the total records in vaccine table of records

};

#endif
