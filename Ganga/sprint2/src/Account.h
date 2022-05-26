#ifndef __bankmanagement_h
#define __bankmanagement_h

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
using namespace std;



class Account
{
	int accountNumber;
	char name[50];
	int balance;
	char type;
public:
	void createAccount();
	void showAccount() const;
	void modify();
	void deposit(int);
	void draw(int);
	void report() const;
	int getAccountNumber() const;
	int getBalance() const;
	char getType() const;
};

#endif
