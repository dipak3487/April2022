/*FILENAME	:	main.cpp
 *
 *
 * DESCRIPTION	:	This is the main file which contains all th information about the program.
 * 			It provides the menus to the user for different task. There are 11 menus for 
 * 			different operations. All the related files(.cpp and .h) used here that is 
 * 			declared/defined in other files.
 *
 * 			CHANGES MADE BY TEAM NARMADA
 *
 */



#include <iostream>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include "date.h"
#include "customer.h"
#include "car.h"
#include "rentals.h"

using namespace std;

Date todayDate;
int up = 0;
pthread_t pthread1;


void* userPreferenceThread(void *arg) {
	char *input = (char *)arg;
	printf("Started: %s\n", input);

	while(true) {

		//if /tmp/nice file exists
		if (access("/tmp/nice", F_OK) == 0)
		{
			// Config::SetUserPreference(1); //nice menu
			up = 1;
		}
		else
		{
			//Config::SetUserPreference(0); //normal menu
			up = 0;
		}

		sleep(10);
	}
	//pthread_exit(arg);
	return arg;
}

void createUserPreferenceThread() {
	const char *thread_input1 = "User preference thread";
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
	//int rc = pthread_create(&pthread1, NULL, userPreferenceThread, (void *)thread_input1);
	if(rc != 0) {
		printf("Error occurred, thread could not be created, errno = %d\n", rc);
		exit(0);
	}
}
//std::string currentUser;
/*Function Name  :  printMenu()
 *
 * Description  :  This functions returns the menus for the user.
 *
 */
void printMenu() 
{
	if(up == 0)
	{
		cout<<"Checking Multithreading"<<endl;
	}
	else{
		cout << "=====================================================================================" << endl;
		cout << "Today\'s Date: " << todayDate << endl;
		cout << "===================================Welcome to Narmada Car Rental Services ===================================\n\n \
			\t1. Add New Car\n \
			\t2. Add New Customer\n \
			\t3. Rent a Car\n \
			\t4. Modify Customer Details\n \
			\t5. Display Details of a Car\n \
			\t6. Display Details of all Cars\n \
			\t7. Display Details of a Customer\n \
			\t8. Modify Car Details\n \
			\t9. Print Rental Data\n \
			\t10. Print Rental Bill\n \
			\t11. Exit\n\n";
		cout << "====================================================================================\n" << endl;
		std::string currentUser;
	}
}

void waitForKeyPress() 
{
	cout << "Press any key to Continue...";
	//cin.ignore();
	cin.get();
}

void clear()   //This function clear the screen 
{
	//system("cls");
	system("clear");    
}

int getInput() //This function take the user input as a menu option.
{
	int option = -1;
	do 
	{
		cout << "\t\t\t\tChoose: ";
		cin >> option;
		cin.ignore();
	} while(option < 1 || option > 12);
	return option;
}

void carModify() //This function changes the car cost per day.
{
	cout << "\t\t\t\tChange Cost per Day of a Car" << endl;
	int c_id;
	cout << "\t\t\t\tEnter Car ID: ";
	cin >> c_id;
	cin.ignore();
	double nCost;
	cout << "\t\t\t\tEnter New Cost per Day: ";
	cin >> nCost;
	cin.ignore();
	modify(c_id, nCost);
	waitForKeyPress();
	clear();
}

void custModify() //this will modify the customer details.
{ 
	cout << "========================= Customer Modification Menu =========================" << endl;
	cout << "\t\t\t\tEnter Customer ID: ";
	int cust_id;
	cin >> cust_id;
	cin.ignore();
	string mn =  "\t\t\t\t1. Modify Name\n\t\t\t\t2. Modify Email\n\t\t\t\t3. Modify Phone Number\n\t\t\t\t4. Modify Residential Address\n\t\t\t\t5. Back\n";
	int inp = -1;
	while(1)
	{
		cout << mn;
		inp = getInput();
		switch(inp) 
		{
			case 1:{
				cout << "\t\t\t\tEnter New Name: ";
				string name;

				getline(cin, name);
				modify(cust_id, name, "", "", "");
				waitForKeyPress();
				clear();
				break;
			}

			case 2:{
				cout << "\t\t\t\tEnter New Email: ";
				string eml;
				getline(cin, eml);
				modify(cust_id, "", eml, "", "");
				waitForKeyPress();
				clear();
				break;
			}

			case 3:{
				cout << "\t\t\t\tEnter New Phone Number: ";
				string pNo;
				getline(cin, pNo);
				modify(cust_id, "", "", pNo, "");
				waitForKeyPress();
				clear();
				break;
			}

			case 4:{
				cout << "\t\t\t\tEnter New Address: ";
				string rAdd;
				getline(cin, rAdd);
				modify(cust_id, "", "", "", rAdd);
				waitForKeyPress();
				clear();
				break;
			}

			case 5:
				return printMenu();
		}
	}
}
/*  main () Description 
 *
 *  All user-defined function implemented here in main. It will show the menus to the user, provide different options 
 *  for different operations.
 */ 
int main() 
{
	createUserPreferenceThread();
	cout << "Enter Today\'s Date: ";
	todayDate = getDate();
	int opt = -1;
	while(1)
	{
		clear();
		cout<<"Userpreference"<<up<<endl;
		printMenu();
		opt = getInput();
		switch(opt) 
		{
			case 1:{
				clear();
				cout << "=========================== Add New Car ===========================\n" << endl;
				Car c = getCarDetails();
				save(c);
				cout << "===================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}

			case 2:{
				clear();
				cout << "=========================== New Customer ===========================\n" << endl;
				Customer cust = registerCustomer();
				save(cust);
				cout << "====================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}


			case 3:{
				cout << "============================ New Rental ============================\n" << endl;
				Rental rent = newRental();
				save(rent);
				cout << "====================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}

			case 4:{
				custModify();
				break;
			}

			case 5:{
				int c_id;
				clear();
				cout << "=========================== Get Car Details ===========================\n" << endl;
				cout << "\t\t\tEnter Car ID to search: ";
				cin >> c_id;
				cin.ignore();
				clear();
				Car c = getCar(c_id);
				cout << "=======================================================================" << endl;
				cout << c << endl;
				cout << "\n=======================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}

			case 6:{
				displayAllCars();
				waitForKeyPress();
				clear();
				break;
			}

			case 7:{
				int cus_id;
				clear();
				cout << "=========================== Get Customer Details ===========================\n" << endl;
				cout << "\t\t\tEnter Customer ID to search: ";
				cin >> cus_id;
				cin.ignore();
				Customer c = getCustomer(cus_id);
				clear();
				cout << "============================================================================" << endl;
				cout << c << endl;
				cout << "\n==========================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}

			case 8:{
				carModify();
				break;
			}

			case 9:{
				int r_id;
				clear();
				cout << "=========================== Get Rental Details ===========================\n" << endl;
				cout << "\t\t\tEnter Rental ID to search: ";
				cin >> r_id;
				cin.ignore();
				Rental r = getRental(r_id);
				clear();
				cout << "=================================================================================" << endl;
				cout << r << endl;
				cout << "\n=============================================================================" << endl;
				waitForKeyPress();
				clear();
				break;
			}


			case 10:{
				int r_id;
				clear();    
				cout << "=========================== Calculate Rental Bill ===========================\n" << endl;
				cout << "\t\t\t\tEnter Rental ID: ";
				cin >> r_id;
				cin.ignore();
				Rental r = getRental(r_id);
				if (!r.chkPaid()) 
				{
					double cst = r.calculateBill();
					clear();
					cout << "============================= Bill ===================================\n" << endl;
					r = getRental(r_id);
					cout << r << endl;
					cout << "======================================================================" << endl;
					cout << "\t\t\tCost to Pay: " << cst << "\t\t" << endl;
					cout << "\n====================================================================\n" << endl;
					double cp;
					do {
						cout << "\t\t\t\tEnter Cost Paid: ";
						cin >> cp;
						cin.ignore();
						if (cp < cst) {
							cout << "\t\t\t\tInsufficient Amount" << endl;
						}
					} while (cp < cst);

					if (cp > cst) 
					{
						cout << "\t\t\t\tChange: " << (cp - cst) << endl;
					}
					cout << "\n======================================================================\n" << endl;
				} 
				else 
				{
					cout << "\t\t\t\tBill is already Paid" << endl;
				}
				waitForKeyPress();
				clear();
				break;
			}

			case 11:{
				exit(0);
			}
		}
	}

	clear();
	cout << "==================================== Thank You ====================================\n" << endl;
	waitForKeyPress();
	return 0;
	cout << "Press any key to Continue...";
	//cin.ignore();
	cin.get();
}

