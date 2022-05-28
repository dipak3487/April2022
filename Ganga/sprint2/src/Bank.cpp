#include "Bank.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Account.h"
#include "Bank.h"
using namespace std;
// This function will add bank account.
void createAccount()
{
	Account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}
//this function will display account information
bool displaysp(int n)
{
	Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		if(ac.getAccountNumber()==n)
		{
			ac.showAccount();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
return true;
}
// This function will modify account 
bool modifyAccount(int n)
{
	bool found=false;
	fstream File;
	Account ac;
    File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.getAccountNumber()==n)
		{
			ac.showAccount();
			cout<<"\n\n\t\t\tEnter The New Details of Account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
	return true;
}


// This function will Delete Account.
bool deleteAccount(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		if(ac.getAccountNumber()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\nRecord Deleted ..";
	return true;
}

// This function will Display All accounts.
bool displayall()
{
	system("clear");
	Account ac;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		ac.report();
	}
	inFile.close();
	return true;
}

// This function will Deposite Amount into account.
bool depositwithdraw(int n, int option)
{
	int amt;
	Account ac;
	bool found=false;
	fstream File;
    File.open("account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.getAccountNumber()==n)
		{
			ac.showAccount();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.deposit(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.getBalance()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
	return true;
}
