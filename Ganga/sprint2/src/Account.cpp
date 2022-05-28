#include "Account.h"

using namespace std;
//this function will get the details for creating account// 
bool Account::createAccount()
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
	return true;
}
// this function will display the created account//
bool Account::showAccount() const
{
	cout<<"\n\t\t\tAccount No. : "<<accountNumber;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<balance;
	return true;
}


//this function will modify the account data//
bool Account::modify()
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
	return true;
}

// this function will display balance//
bool Account::deposit(int x)
{
	balance+=x;
	return true;
}
// this function is use to withdraw money//
bool Account::draw(int x)
{
	balance-=x;
	return true;
}
// to display all the records//
bool Account::report() const
{
	cout<<accountNumber<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<balance<<endl;
return true;
}

// to get account number//
int Account::getAccountNumber() const
{
	return accountNumber;
}
// to get balance//
int Account::getBalance() const
{
	return balance;
}
// to get type of account//
char Account::getType() const
{
	return type;
}


