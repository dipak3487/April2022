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
		//	system("clear");
			bank.write_Account();
			break;
		case '2':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			delete_Account(num);
			break;
		 case '7':
		 	system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			modify_Account(num);
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






