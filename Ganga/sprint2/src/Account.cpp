#include <cstring>
#include "Account.h"
using namespace std;

void Account ::Create_Account()
{
   int acno;
          char name[50];
	         int deposit; 
	cout<<"\n\t\t\tEnter The  Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";

}
//		function to show specific record from file
void Account::Show_Account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

//		function to display modify record 
void Account::Modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}

//function to accept amount and add to balance amount
void Account::Deposit(int x)
{
	deposit+=x;
}
//function to accept amount and subtract from balance amount
void Account::Withdraw(int x)
{
	deposit-=x;
}
//function to show data in tabular format
void Account::Report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(20)<<" "<<deposit<<endl;
}
//function to return account number
int Account::Retacno() const
{
	return acno;
}
//function to return balance amount
int Account::Retdeposit() const
{
	return deposit;
}

//		function to write in file
void Account::Write_Account()
{
	Account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	ac.Create_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
	outFile.close();
}
//		function to read specific record from file
void Account::Display(int n)
{
	Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))//Dyanamic memory allocation & convert input of binary format to string
	{
		if(ac.Retacno()==n)
		{
			ac.Show_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist!!!";
}


//      function to modify record of file
void Account:: Modify_Account(int n)
{
	bool found=false;
	Account ac;
	fstream File;
    File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
		if(ac.Retacno()==n)
		{
			ac.Show_Account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.Modify();
			int pos=(-1)*static_cast<int>(sizeof(Account));
			File.seekp(pos,ios::cur); 
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
		    cout<<"\n\n\t\t\tRecords Updated!!";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tAccount number does not exist!!! ";
}


//		function to delete record of file
void Account::Delete_Account(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))//Dyanamic memory allocation & convert input of binary format to string
	{
		if(ac.Retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
		}
	}
    inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\nRecord Deleted ..";
}
//		function to display all accounts deposit list
void Account::Display_All()
   {
	Account ac;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=======================================================\n";
	cout<<"A/c no.             NAME                  Balance\n";
	cout<<"=======================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))//Dyanamic memory allocation & convert input of binary format to string
	{
		ac.Report();
	}
	inFile.close();
}

//		function to deposit and withdraw amounts
void Account::Deposit_Withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Account ac;
	fstream File;
    File.open("account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
		if(ac.Retacno()==n)
		{
			ac.Show_Account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.Deposit(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.Retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.Withdraw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));//Dyanamic memory allocation & convert input of binary format to string
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tAccount number does not exist!!! ";
}


