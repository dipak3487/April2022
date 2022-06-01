#ifndef _VACCINE_H
#define _VACCINE_H

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
		void menu();
		void getData();//takes Citizen data from the user
		void addNew();//data is added to the  database
		void addNew_Vaccine();
		void get_VaccineData();//takes Vaccine Data from the user
		void showData();//display data
		void view_all();//view the entire Citizen database
		void view_Vac();
		void Search_Citizen_Records();
		void search_name();
		void search_aadhar();
		void search_mobile();
		void createUserPreferenceThread();
		void view_Vaccine();//operations on the vaccine inventory
		int countRecords();
		
};

#endif
