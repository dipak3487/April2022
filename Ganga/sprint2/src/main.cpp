#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>

#include "Account.h"

using namespace std;

int main()
{

	char ch;
	int num;
	Bank bank;

	do
	{

	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
		//	system("clear");
			bank.write_Account();
			break;
		case '2':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			delete_Account(num);
			break;
		 case '7':
		 	system("clear");
			cout<<"\n\n\t\t\tEnter The Account No. : "; cin>>num;
			modify_Account(num);
			break;
		 case '8':
		 	system("clear");
			cout<<"\n\n\t\t\tThank You For Using Bank Management System";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}


void write_Account()
{
	ofstream outFile;
	outFile.open("Account.txt",ios::binary|ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}

void display_sp(int n)
{
	bool flag=false;
	ifstream inFile;
	inFile.open("Account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
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
}



void modify_Account(int n)
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
}



void delete_Account(int n)
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
}


void display_all()
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
}


void deposit_withdraw(int n, int option)
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
}

