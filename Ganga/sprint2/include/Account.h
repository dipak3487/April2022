#include<iostream>
#include<fstream>
#ifndef __bankmanagement_h
#define __bankmanagement_h
#include<cctype>
#include<iomanip>
#include<string.h>
#include<stdlib.h>

using namespace std;
class Account
{
	int acno;
	char name[50];
	int deposit;
public:
	Account(){};
	Account(int a, char n[50], int b): acno(a),deposit(b){strncpy(name,n,50); name[49]='\0';};
	void Create_Account();//function to get data from user
	void Show_Account() const;//function to show data on screen
	void Modify();//function to add new data
	void Deposit(int);//function to accept amount and add to balance amount
	void Withdraw(int);//function to accept amount and subtract from balance amount
	void Report() const;//function to show data in tabular format
	int Retacno() const;//function to return account number
	int Retdeposit() const;//function to return balance amount
	void Write_Account();//function to write record in binary file
	void Display(int);//function to display account details given by user
	void Modify_Account(int);//function to modify record of file
	void Delete_Account(int);//function to delete record of file
	void Display_All();//function to display all account details
	void Deposit_Withdraw(int, int); // function to desposit/withdraw amount for given account

};
#endif
