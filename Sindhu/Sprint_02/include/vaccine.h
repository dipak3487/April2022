#ifndef _VACCINE_H
#define _VACCINE_H
#include <iostream>

<<<<<<< HEAD
=======
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
    void searchMenu();
    bool searchCitizen();
    bool viewVaccineStatics();
    void vaccineStaticsMenu();
    bool isConnectedToDB();
    bool saveCitizenRecordsInDB();
    bool viewAllCitizenRecord();
    bool getCitizenData();
    bool getVaccineData();
    bool addNewCitizen();
    bool addNewVaccine();
    bool isLogin();
    void displayMainMenu();
    bool createUserPreferenceThread();
    void *userPreferenceThread(void *arg);
>>>>>>> 897cced007e38e6cc6fe08f5706242f31ef5f399

    // Searching Operation
    bool searchByName();
    bool seachByAdhar();
    bool seachByMobile();

<<<<<<< HEAD
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
		
=======
    void callback(void *NotUsed, int argc, char **argv, char **azColName);
>>>>>>> 897cced007e38e6cc6fe08f5706242f31ef5f399
};
#endif
