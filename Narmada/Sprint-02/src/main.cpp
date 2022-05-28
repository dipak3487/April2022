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
#include "../src/date.h"
#include "../src/customer.h"
#include "../src/car.h"
#include "../src/rentals.h"

using namespace std;

Date todayDate;

std::string currentUser;

void printMenu() 
{
    cout << "=====================================================================================" << endl;
    cout << "Today\'s Date: " << todayDate << endl;
    cout << "=================================== Rental System ===================================\n\n \
	\t1. New Car\n \
	\t2. New Customer\n \
	\t3. Create Rental\n \
	\t4. Modify Customer Details\n \
	\t5. Display Details of a Car\n \
	\t6. Display Details of all Cars\n \
	\t7. Display Details of a Customer\n \
	\t8. Modify Car Detials\n \
	\t9. Get Rental Data\n \
	\t10. Print Rental Bill\n \
	\t11. Exit\n\n";
    cout << "====================================================================================\n" << endl;
}

void waitForKeyPress() 
{
    cout << "Press any key to Continue...";
    cin.ignore();
    cin.get();
}

void clear() 
{
    system("cls");
    system("clear");    
}

int getInput() 
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

void carModify() 
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

void custModify() 
{ 
    cout << "========================= Customer Modification Menu =========================" << endl;
    cout << "\t\t\t\tEnter Customer ID: ";
    int cust_id;
    cin >> cust_id;
    cin.ignore();
    string mn =  "\t\t\t\t1. Modify Name\n\t\t\t\t2. Modify Email\n\t\t\t\t3. Modify Phone Number\n\t\t\t\t4. Modify Residential Address\n\t\t\t\t5. Back\n";
    int inp = -1;
    do 
    {
        cout << mn;
        inp = getInput();
        if (inp == 1) 
	{
            cout << "\t\t\t\tEnter New Name: ";
            string name;
            getline(cin, name);
            modify(cust_id, name, "", "", "");
            waitForKeyPress();
            clear();
        } 
	else if (inp == 2) 
	{
            cout << "\t\t\t\tEnter New Email: ";
            string eml;
            getline(cin, eml);
            modify(cust_id, "", eml, "", "");
            waitForKeyPress();
            clear();
        } 
	else if (inp == 3) 
	{
            cout << "\t\t\t\tEnter New Phone Number: ";
            string pNo;
            getline(cin, pNo);
            modify(cust_id, "", "", pNo, "");
            waitForKeyPress();
            clear();
        } 
	else if (inp == 4) 
	{
            cout << "\t\t\t\tEnter New Address: ";
            string rAdd;
            getline(cin, rAdd);
            modify(cust_id, "", "", "", rAdd);
            waitForKeyPress();
            clear();
        } 
	else if (inp == 5) 
	{
            break;
        }
    } while(inp != 5);
}

int main() 
{
    cout << "Enter Today\'s Date: ";
    todayDate = getDate();
    int opt = -1;
    do 
    {
        clear();
        printMenu();
        opt = getInput();
        if (opt == 1) 
	{
            clear();
            cout << "=========================== Add New Car ===========================\n" << endl;
            Car c = getCarDetails();
            save(c);
            cout << "===================================================================" << endl;
            waitForKeyPress();
            clear();
        } 
	
	else if (opt == 2) 
	{
            clear();
            cout << "=========================== New Customer ===========================\n" << endl;
            Customer cust = registerCustomer();
            save(cust);
            cout << "====================================================================" << endl;
            waitForKeyPress();
            clear();
        } 
	
	else if (opt == 3) 
	{
            cout << "============================ New Rental ============================\n" << endl;
            Rental rent = newRental();
            save(rent);
            cout << "====================================================================" << endl;
            waitForKeyPress();
            clear();
        } 
	
	else if (opt == 4) 
	{
            custModify();
        } 
	
	else if (opt == 5) 
	{
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
        } 
	
	else if (opt == 6) 
	{
            displayAllCars();
            waitForKeyPress();
            clear();
        } 
	
	else if (opt == 7) 
	{
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
        } 
	
	else if (opt == 8) 
	{
            carModify();
        } 
	
	else if (opt == 9) 
	{
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
        } 
	
	else if (opt == 10) 
	{
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
        } 
	
	else if (opt == 11) 
	{
            break;
        } 
    } while(opt != 11);
    
    clear();
    cout << "==================================== Thank You ====================================\n" << endl;
    waitForKeyPress();
    return 0;
}
