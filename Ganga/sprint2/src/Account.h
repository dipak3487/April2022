#include<iostream>
#include<fstream>
#ifndef __bankmanagement_h
#define __bankmanagement_h
#include<cctype>
#include<iomanip>
#include<stdlib.h>

using namespace std;
class Account
{
	int acno;
	char name[50];
	int deposit;
public:
//	Account(){};
//	Account(int a, char n, int b): acno(a),name(n),deposit(b){};
	void Create_Account();//function to get data from user
	void Show_Account() const;//function to show data on screen
	void Modify();//function to add new data
	void Deposit(int);//function to accept amount and add to balance amount
	void Withdraw(int);//function to accept amount and subtract from balance amount
	void Report() const;//function to show data in tabular format
	int Retacno() const;//function to return account number
	int Retdeposit() const;//function to return balance amount
	
};
#endif
