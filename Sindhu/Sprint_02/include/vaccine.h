#ifndef _VACCINE_H
#define _VACCINE_H
#include <sqlite3.h>

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
};

#endif
