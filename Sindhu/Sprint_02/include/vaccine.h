#ifndef _VACCINE_H
#define _VACCINE_H
#include <iostream>

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

    // Searching Operation
    bool searchByName();
    bool seachByAdhar();
    bool seachByMobile();

    void callback(void *NotUsed, int argc, char **argv, char **azColName);
};
#endif
