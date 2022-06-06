#ifndef _VACCINE_H
#define _VACCINE_H
#include <sqlite3.h>

<<<<<<< HEAD
// Creating class of Vaccine
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
    void mainMenu();
   // void getData(); // takes Citizen data from the user
    void addNewCitizen();  // data is added to the  database
    void addNewVaccine();
    void getVaccineDetails(); // takes Vaccine Data from the user
    void showCitizenData();        // display data
    void viewAllCitizenRecord();        // view the entire Citizen database
    void viewVaccineStatics();
    void searchCitizenRecords();
    void searchByName();
    void searchUsingAadhar();
    void searchUsingMobile();
    void createUserPreferenceThread();
    void viewVaccineDetails();
    int countRecords();
    void getData();
=======

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
		void menu();//displayed on the command prompt for the user
		void getData();//takes Citizen data from the user
		void addNewCitizen();//data is added to the  database
		void addNew_Vaccine();//data is added to the  database
		void get_VaccineData();//takes Vaccine Data from the user
		void showData();//display data
		void view_all();//view the entire Citizen records
		void view_Vac();//view the entire vaccine records
		void Search_Citizen_Records();//main menu to access the search options for Citizen table
		void search_name();//search using name datafield
		void search_aadhar();//search using the aadhar card number
		void search_mobile(); //search using mobile number
		void createUserPreferenceThread();// function for multithreading
		void view_Vaccine();//operations on the vaccine inventory
		int countRecords();// count the total records in vaccine table of records
		
>>>>>>> 501b7dfab72cb7222f4b080c3ac63d06ffc21eec
};

#endif
