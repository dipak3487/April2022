#ifndef _VACCINE_H
#define _VACCINE_H

#include <sqlite3.h>

class Vaccine
{
	private:
		int age;
		int temperature;
		int bloodPressure;
		int date;
		int bno;
		int units;
		int backup;
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
		void getData();//takes data from the user
		void addNew();//data is added to the  database
		void addNew_Vaccine();
		void showData();//display data
		void view_all();//view the entire Citizen database
		void view_Vac();
		void view_Vaccine();//operations on the vaccine inventory
};

#endif
