<<<<<<< HEAD
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
//#include "Bank.h"
#include "Account.h"

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

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
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}

=======
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Bank.h"
#include "Account.h"

using namespace std;
<<<<<<< HEAD
// Program starts here.
=======
//program start here//
>>>>>>> b27779f89d3721aa59c96f02b1e1287407736bc1
int main()
{
Account a;
	char ch;
	int num,accountnum;
	char name[50];
	Bank bank;

	do
	// this will print main menu//	
	{
             // This will print main menu.
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
			//system("clear");
		//	cout<<"\n\n\t\t\tEnter Name :- ";cin>>name;
		//	cout<<"\n\n\t\t\tEnter Accout Number:- ", cin>>accountnum;

    		 a.createAccount();
			break;
		case '2':
		//	system("clear");
		cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
	//	a.deposit(int);
			break;
		case '3':
			//system("clear");
		cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void depositwithdraw(int num);
			break;
		case '4':
		//	system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void displaysp(int num);
			break;
		case '5':
			void displayall();
			break;
		case '6':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void delete_Account(int num);
			break;
		 case '7':
		 	system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void modify_Account(int num);
			break;
		 case '8':
		 	system("clear");
			cout<<"\n\n\t\t\tThank You For Using Bank Management System";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}






>>>>>>> be69e9a4a58b0ccd115f1d60730408f582209c0f
