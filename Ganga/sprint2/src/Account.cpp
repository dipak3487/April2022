#include "Account.h"

using namespace std;

void Account::createAccount()
{
//	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>accountNumber;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>balance;
	cout<<"\n\n\t\t\tAccount Created..";
}

void Account::showAccount() const
{
	cout<<"\n\t\t\tAccount No. : "<<accountNumber;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<balance;
}


void Account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<accountNumber;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>balance;
}


void Account::deposit(int x)
{
	balance+=x;
}

void Account::draw(int x)
{
	balance-=x;
}

void Account::report() const
{
	cout<<accountNumber<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<balance<<endl;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

int Account::getBalance() const
{
	return balance;
}

char Account::getType() const
{
	return type;
}


