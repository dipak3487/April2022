#include<iostream>
#include<fstream>
#ifndef __bankmanagement_h
#define __bankmanagement_h
#include<cctype>
#include<iomanip>
#include<stdlib.h>

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
