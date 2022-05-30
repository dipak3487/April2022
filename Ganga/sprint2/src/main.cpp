/*FILENAME	:	main.cpp
 *  
 *   
 *     DESCRIPTION	:	This is the main file which contains all th information about the program.
 *      			It provides the menus to the user for different task. There are 08 menus for 
 *       			different operations. All the related files(.cpp and .h) used here that is 
 *        			declared/defined in other files.
 *        
 *          			CHANGES MADE BY TEAM Ganga
 *          
 */
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Account.h"
//		function declaration
void write_account();//function to write record in binary file
void display_sp(int);//function to display account details given by user
void modify_account(int);//function to modify record of file
void delete_account(int);//function to delete record of file
void display_all();//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account

int main()
{

	char ch;
	int num;
	do
	{

	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			system("clear");
			write_account();
			break;
		case '2':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
		 	system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
		 	system("clear");
			cout<<"\n\n\t\t\tThank You For Using Bank Management System";
			break;
		 default :cout<<"\n\n\t\t\tInvalid Choice!!!!";
		}
		cout<<"\n\n\t\t\tPress Enter to Continue...";
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}


