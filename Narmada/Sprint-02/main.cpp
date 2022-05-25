#include <iostream>

using namespace std;



void printMenu()
{
	cout << "=====================================================================================" << endl;
	cout << " PRANG-V " << endl;
	cout << "=================================== Rental System ===================================\n\n \
		\t\t\t\t1. New Car\n \
		\t\t\t\t2. New Customer\n \
		\t\t\t\t3. Create Rental\n \
		\t\t\t\t4. Modify Customer Details\n \
		\t\t\t\t5. Display Details of a Car\n \
		\t\t\t\t6. Display Details of all Cars\n \
		\t\t\t\t7. Display Details of a Customer\n \
		\t\t\t\t8. Modify Car Detials\n \
		\t\t\t\t9. Get Rental Data\n \
		\t\t\t\t10. Print Rental Bill\n \
		\t\t\t\t11. Logout\n \
		\t\t\t\t12. Exit\n\n";
	cout << "====================================================================================\n" << endl;
}

int main()
{
	int opt =-1;
	do
	{
		printMenu();
		if (opt == 1)
		{
			cout << "=========================== Add New Car ===========================\n" << endl;
			cout << "===================================================================" << endl;
		}

		else if (opt == 2)
		{
			cout << "=========================== New Customer ===========================\n" << endl;
			cout << "====================================================================" << endl;
		}

		else if (opt == 3)
		{
			cout << "============================ New Rental ============================\n" << endl;
			cout << "====================================================================" << endl;
		}

		else if (opt == 4)
		{
			cout << "========================= Modify Customer =========================\n" << endl;
		}

		else if (opt == 5)
		{
			cout << "=========================== Get Car Details ===========================\n" << endl;
			cout << "=======================================================================" << endl;
		}

		else if (opt == 6)
		{
			cout << "======================= Display All Car Details ========================\n" << endl;
		}

		else if (opt == 7)
		{

			cout << "=========================== Get Customer Details ===========================\n" << endl;
			cout << "============================================================================" << endl;
		}

		else if (opt == 8)
		{
			cout << "=========================== Modify Car Details ===========================\n" << endl;
		}

		else if (opt == 9)
		{
			cout << "=========================== Get Rental Details ===========================\n" << endl;
			cout << "=================================================================================" << endl;
		}
		else if (opt == 10)
		{
			cout << "=========================== Calculate Rental Bill ===========================\n" << endl;
			cout << "\n=========================================================================\n" << endl;

		}
		else if (opt == 11)
		{
			cout << "=========================== Current User ===========================\n" << endl;
			cout << "\n=========================================================================\n" << endl;
		}

		else if (opt == 12)
		{

			break;
		}
	} while(opt != 12);

	cout << "==================================== Thank You ====================================\n" << endl;
	return 0;
}
