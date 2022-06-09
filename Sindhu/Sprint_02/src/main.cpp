#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cstring>
#include <sqlite3.h>
#include <memory>
#include <bits/stdc++.h>
#include "vaccine.h"
using namespace std;

int up;
pthread_t pthread1;

int main(int argc, char **argv)
{

    int ch;
    Vaccine vaccine;
    bool upstat = vaccine.createUserPreferenceThread();

    if (upstat)
    {
        printf("Error occurred, thread could not be created, errno = \n");

        exit(0);
    }
    cout << "+++++++++++UserPrefrences Thread Created+++++++++++";

    bool isValid = vaccine.isLogin();
    if (isValid)
    {
        void displayMainMenu();
        cout << "\n\t\n\tPlease Enter your inputs: \n";
        cin >> ch;
        if (ch > 0 && ch < 6)
        {
            switch (ch)
            {
            case 1:
                if (vaccine.addNewCitizen())
			//bool isSaved;
                    //isSaved = (vaccine.saveCitizenRecordsInDB()) ? true : false;
                if (vaccine.saveCitizenRecordsInDB())
                {
                    fprintf(stderr, "Successfully Connected To   Database...\n\n\n");
                    cout << "Citizen's Details added Successfully!!!\n";
                }
                else
                {
                    cout << "Failed to Save citizen's details in DataBase\n";
			//sqlite3 *db;
                    fprintf(stderr, "Can't open database: %s\n");//, sqlite3_errmsg(db));
                }

                break;

            case 2:
                vaccine.vaccineStaticsMenu();
                int ch;
                cout << "Please Enter Your Choice...\n";
                cin >> ch;
                if (ch < 0 || ch > 3)
                {
                    cout << "Invalid Input...\n";
                }
                else
                {
                    switch (ch)
                    {
                    case 1:
               		//bool stat = vaccine.addNewVaccine() ? true : false;
                        if (vaccine.addNewVaccine())
                        {
                            cout << "Vaccine Added Successfully into Database...\n";
                        }
			else{
                            cout<<"Cannot connet to Database!!!\n";
                            fprintf(stderr, "Can't open database: %s\n");//, sqlite3_errmsg(db));
                        }

                        break;
                    case 2:
                        //bool isShown = vaccine.viewVaccineStatics() ? true : false;

                        if (!vaccine.viewVaccineStatics())
                        {
                            cout << "Check LineNumber 82 in bussiness Logic\n";
                        }

                        break;

                    default:

                        //sqlite3_close(db);
                        break;
                    }
                }

                break;
            case 3:
                //bool stat = vaccine.viewAllCitizenRecord() ? true : false;
                if (!vaccine.viewAllCitizenRecord())
                {
                    cout << "Database Operation Failed...\n";
                }

                break;
            case 4:
                //bool stat = vaccine.searchCitizen() ? true : false;
                if (!vaccine.searchCitizen())
                {
                    cout << "Sorry Database txn failes...\n";
                }

                break;

            default:
                cout << "Invalid Input...";
                exit(0);
                // break;
            }
        }
    }
    else
    {
        cout << "Invalid Username or password!!!";
        exit(0);
    }
    return 0;
}
