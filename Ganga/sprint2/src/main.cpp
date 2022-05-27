#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include"Bank.h"
#include "Account.h"

using namespace std;

int main()
{

	char ch;
	int num;
	Bank bank;

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
			void writeAccount();
			break;
		case '2':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void deposit(int num);
			break;
		case '3':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			void depositwithdraw(int num);
			break;
		case '4':
			system("clear");
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






