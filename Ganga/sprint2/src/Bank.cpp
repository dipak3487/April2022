#include "Bank.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Account.h"
using namespace std;

bool modify_Account(int n)
{
	bool found=false;
	fstream File;
    File.open("Account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
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



bool delete_Account(int n)
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("Account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
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
	remove("Account.txt");
	rename("Temp.txt","Account.txt");
	cout<<"\n\nRecord Deleted ..";
	return true;
}


bool display_all()
{
//	system("clear");
	ifstream inFile;
	inFile.open("Account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
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


bool deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	fstream File;
    File.open("Account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
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




