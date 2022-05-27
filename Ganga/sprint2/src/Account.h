#ifndef __bankmanagement_h
#define __bankmanagement_h

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Bank.h"
using namespace std;



class Account
{
	int accountNumber;
	char name[50];
	int balance;
	char type;
public:
	bool createAccount();
	bool showAccount() const;
	bool modify();
	bool deposit(int);
	bool draw(int);
	bool report() const;
	int getAccountNumber() const;
	int getBalance() const;
	char getType() const;
};

#endif
