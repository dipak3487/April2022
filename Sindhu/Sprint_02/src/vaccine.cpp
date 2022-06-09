#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstring>
#include <sqlite3.h>
#include <memory>
#include <bits/stdc++.h>
#include <regex>
#include <memory>
#include <bits/stdc++.h>
#include "Vaccine.h"

using namespace std;

bool Vaccine::searchByName()
{
    bool status = false;

    string aadhar_no;
    sqlite3 *db;
    Vaccine vc;
    int rc = vc.isConnectedToDB();

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter the  name to search:- ";
        std::getline(std::cin, name);

        temp << "SELECT * FROM CITIZEN_RECORDS WHERE Name = '" << name << "' ;";

        command = temp.str();

        sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
        sqlite3_close(db);
        status = true;
    }
    return status;
}
bool Vaccine::seachByMobile()
{
    bool st = false;
    string mobile_no;
    sqlite3 *db;
    Vaccine vc;
    int rc = vc.isConnectedToDB();
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter the  Mobile Number to search:- ";
        cin >> mobile_no;
        temp << "SELECT * FROM CITIZEN_RECORDS WHERE Mobile_No = '" << mobile_no << "' ;";

        command = temp.str();

        sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
        sqlite3_close(db);
        st = true;
    }

    return st;
}
bool Vaccine::seachByAdhar()
{
    bool stat = false;
    string aadhar_no;
    sqlite3 *db;
    Vaccine vc;

    int rc = vc.isConnectedToDB();

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter the  name to search:- ";
        std::getline(std::cin, name);

        temp << "SELECT * FROM CITIZEN_RECORDS WHERE Name = '" << name << "' ;";

        command = temp.str();

        sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
        sqlite3_close(db);

        stat = true;
    }
    return stat;
}
bool Vaccine::searchCitizen()
{
    bool res = false;

    Vaccine vc;
    vc.searchMenu();

    cin >> ch;

    if (ch < 0 && ch > 4)
    {
        cout << "Invalid Input";
    }
    else
    {
        switch (ch)
        {
        case 1:

            searchByName();

            break;
        case 2:
            searchUsingAadhar();

            break;
        case 3:
            searchUsingMobile();

            break;

        default:

            cout << "\nEnter valid option " << endl;
            // continue;
            break;
        }
    }

    return res;
}
void Vaccine::searchMenu()
{
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\tSEARCH HERE";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "\n\t\t1.Search By Name ";
    cout << "\n\t\t2.Search By Aadhar Card Number";
    cout << "\n\t\t3.Search By Mobile Number";
    cout << "\n\t\t4.Back" << endl;
}

bool Vaccine::getVaccineData()
{
    bool isCaptured = false;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n\t\t Enter Vaccine Brand Name :-  ";
    std::getline(std::cin, v_name);

    cout << "\n\t\t Enter Brand Description  :-  ";
    getline(std::cin, desc);

    cout << "\n\t\t Enter the Expiry Date :-  ";
    cin >> date;

    cout << "\n\t\t Enter the  BATCH Number:- ";
    cin >> bno;

    cout << "\n\t\t Enter the Number of Units :-  ";
    cin >> units;

    cout << "\n\t\t Enter Backup Stock number if available:-  ";
    cin >> backup;

    cout << "\n\t\t Enter total Cost:-  ";
    cin >> cost;

    isCaptured = true;

    return isCaptured;
}
bool Vaccine::addNewVaccine()
{
    bool response;
    if (isConnectedToDB())
    {
        responese = false;
    }
    else
    {
        getVaccineData();

        temp << "INSERT INTO VACCINE_INVENTORY VALUES ('" << v_name << "','" << desc << "', " << date << "," << bno << "," << units << "," << backup << "," << cost << ")";

        command = temp.str();
        rc = sqlite3_exec(db, command.c_str(), callback, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            response = false;
            // fprintf(stderr, "SQL error: %s\n", zErrMsg);
            // sqlite3_free(zErrMsg);
        }
        else
        {
            response = true;
            // fprintf(stdout, "Records created successfully\n");
        }
        sqlite3_close(db);
    }
    return response;
}

void Vaccine::vaccineStaticsMenu()
{
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t\t\t\tVACCINE STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "\n\t\t1.Add Vaccine";
    cout << "\n\t\t2.View Current Vaccine Stock";
    cout << "\n\t\t3.Back" << endl;
}
bool Vaccine::viewVaccineStatics()
{
    bool isShow = false;
    int ch;
    vaccineStaticsMenu()
        Vaccine vc;
    if (vc.callback())
    {
        fprintf(stderr, "Can't connect database: %s\n", sqlite3_errmsg(db));
        isShow = false;
    }
    else
    {
        fprintf(stderr, "Connected to Database...\n");

        // Fetching vaccine details from database
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter the  Mobile Number to search:- ";
        cin >> mobile_no;
        temp << "SELECT * FROM CITIZEN_RECORDS WHERE Mobile_No = '" << mobile_no << "' ;";

        command = temp.str();

        sqlite3_exec(db, command.c_str(), callback, NULL, NULL);
        sqlite3_close(db);
        isShow = true;
    }

    return isShow;
}
bool Vaccine::saveCitizenRecordsInDB()
{
    bool isSaved;
    ////if require please get user details agein....
    temp << "INSERT INTO CITIZEN_RECORDS VALUES ('" << name << "', " << aadhar_no << ",'" << gender << "', " << age << "," << bloodPressure << "," << temperature << ",'" << Medical_conditions << "'," << mobileNumber << ",'" << vaccine << "')";

    command = temp.str();
    rc = sqlite3_exec(db, command.c_str(), callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        // fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // sqlite3_free(zErrMsg);
        isSaved = false;
    }
    else
    {
        isSaved = true;
        // fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);

    return isSaved;
}
bool Vaccine::isConnectedToDB()
{
    bool connection = false;
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("../config/example.db", &db);
    std::ostringstream temp;
    std::string command;

    if (rc)
    {
        connection = false;
    }
    else
    {
        connection = true;
    }

    return connection;
}
bool Vaccine::viewAllCitizenRecord()
{
    bool resp = false;
    sqlite3 *db;

    int rc;
    rc = sqlite3_open("../config/example.db", &db);
    std::ostringstream temp;
    std::string command;
    == == == =
                 sqlite3 * db;

    int rc;
    rc = sqlite3_open("example.db", &db);
    std::ostringstream temp;
    std::string command;

    string query = "SELECT * FROM CITIZEN_RECORDS;";
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
    sqlite3_close(db);

    string query = "SELECT * FROM CITIZEN_RECORDS;";
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Connected to Database Successfully...\n");
    }

    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
    sqlite3_close(db);

    resp = true;

    return resp;
}

bool Vaccine::addNewCitizen()
{
    bool isAdded = false;
    bool status = getCitizenData();
    if (status)
    {
        Vaccine vc;
        if (vc.isConnectedToDB())
        {
            if (vc.saveCitizenRecordsInDB())
            {
                isAdded = true;
            }
        }
    }
    else
    {
        isAdded = false;
    }
    return isAdded;
}
bool Vaccine::getCitizenData()
{
    bool isCaptured = false;

    // Input Details of the Citizens administered with the vaccines from the authorised user
    cout << "\t\t\t ENTER THE GIVEN DETAILS";
    cout << "-----------------------------------------------------------------------";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n\t\t Enter Name :-  ";

    std::getline(std::cin, name);

    cout << "\n\t\t Enter Aadhaar no :-  ";
    std::getline(std::cin, aadhar_no);
    const regex pattern("^[2-9]{1}[0-9]{3}\\s[0-9]{4}\\s[0-9]{4}$");
    if (regex_match(mobileNumber, pattern))
    {
        while ((aadhar_no).length() < 12 || (aadhar_no).length() > 12)
        {
            std::cout << "Aadhaar Card Number can't be lessor more than 12 numbers. Please enter the again" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\t\t Enter Aadhaar no :- ";
            std::getline(std::cin, aadhar_no);
        }
    }

    else
    {
        cout << "Not valid, Please enter again";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter Aadhar number :- ";
        std::getline(std::cin, mobileNumber);
    }

    cout << "\n\t\t Enter the gender (M|F) :-  ";
    cin >> gender;

    cout << "\n\t\t Enter the  age:- ";
    cin >> age;

    cout << "\n\t\t Enter the  Blood Pressure. :-  ";
    cin >> bloodPressure;

    cout << "\n\t\t Enter the Body temperature:-  ";
    cin >> temperature;

    cout << "\n\t\t Enter Medical Conditions if any :-  ";
    cin >> Medical_conditions;

    cout << "\n\t\t Enter the  Mobile number :-  ";
    cin >> mobileNumber;
    const regex pattern1("(0|91)?[7-9][0-9]{9}");
    if (regex_match(mobileNumber, pattern1))
    {
        while ((((mobileNumber).length() < 10 || (mobileNumber).length() > 10)))
        {
            std::cout << "Mobile Number should be 10 digit, valid number. Please enter the again" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\t\t Enter Mobile number :- ";
            std::getline(std::cin, mobileNumber);
        }
    }
    else
    {
        cout << "Not valid, Please enter again";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter Mobile number :- ";
        std::getline(std::cin, mobileNumber);
    }

    cout << "\n\t\t Enter the vaccine injected :- ";
    cin >> vaccine;

    while ((vaccine).length() <= 0)
    {
        std::cout << "Please enter the Vaccine Injected" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\t Enter the vaccine injected :- ";
        std::getline(std::cin, vaccine);
    }
    isCaptured = true;
    return isCaptured;
}

void Vaccine::displayMainMenu()
{
    int up;
    if (up == 1)
    {
        cout << "\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"
             << endl;
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t             MAIN MENU";
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\t1: Add New Citizen Record" << endl;
        cout << "\n\t\t\t\t2: View VACCINE Inventory" << endl;
        cout << "\n\t\t\t\t3: View All Citizen Details" << endl;
        cout << "\n\t\t\t\t4: Search Citizen" << endl;
        cout << "\n\t\t\t\t5: Exit" << endl;
    }
    else
    {
        cout << "\t\t\t\t	W	E	L	C	O	M	E	" << endl;
        cout << "\n\n\t\t\t VACCINE MANAGEMENT SYSTEM  \n\n"
             << endl;
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t        M A I N  M E N U ";
        cout << "\n\t\t\t------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\t1: Add New Citizen Record" << endl;
        cout << "\n\t\t\t\t2: View VACCINE Inventory" << endl;
        cout << "\n\t\t\t\t3: View All Citizen Details" << endl;
        cout << "\n\t\t\t\t4: Search Citizen" << endl;
        cout << "\n\t\t\t\t5: Exit" << endl;
    }
}

bool Vaccine::isLogin()
{
    bool isValid = false;

    cout << "\t\t\tAdmin Login" << endl;
    std::string adminid = "admin";
    std::string user;
    std::cout << "Enter username:" << std::endl;
    std::cin >> user;

    // verifying userid
    //
    if (adminid == user)
    {
        const char *mypass = "sindhu";
        //
        // Hiding Password
        char *password = getpass("Enter password: ");

        if (strcmp(password, mypass) == 0)
        {
            // cout << "Correct password! \n";
            isValid = true;
        }
        else
        {
            isValid = false;
        }
    }
    else
    {
        // cout << "Invalid user" << endl;
        isValid = false;
    }
    return isValid;
}

void Vaccine::*userPreferenceThread(void *arg)
{
    char *input = (char *)arg;
    printf("Started: %s\n", input);

    while (true)
    {

        // if /tmp/nice file exists
        if (access("/tmp/nice", F_OK) == 0)
        {
            // Config::SetUserPreference(1); //nice menu
            up = 1;
        }
        else
        {
            // Config::SetUserPreference(0); //normal menu
            up = 0;
        }

        sleep(1);
    }
    // pthread_exit(arg);
    return arg;
}
// Creating userPrefrence
bool Vaccine::createUserPreferenceThread()
{
    bool status = false;
    static char *thread_input1 = "User preference thread";
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
    if (rc != 0)
    {
        status = true;
    }
    return status;
}

// Callback
static int
Vaccine::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

