<<<<<<< HEAD
#include<iostream>
#include<fstream>
#ifndef __bankmanagement_h
#define __bankmanagement_h
#include<cctype>
#include<iomanip>
#include<stdlib.h>
//#include"Bank.h"
using namespace std;
class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};
#endif
=======
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
>>>>>>> be69e9a4a58b0ccd115f1d60730408f582209c0f
