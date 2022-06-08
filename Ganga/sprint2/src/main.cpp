/*FILENAME	:	main.cpp
 *  
 *   
 *     DESCRIPTION	:	This is the main file which contains all th information about the program.
 *      			It provides the menus to the user for different task. There are 08 menus for 
 *       			different operations. All the related files(.cpp and .h) used here that is 
 *        			declared/defined in other files.
 *        
 *          			CHANGES MADE BY TEAM Ganga
 *          
 */
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Account.h"
#include <fcntl.h> 
#include <unistd.h>
 int up=0;


pthread_t pthread1;

void* userPreferenceThread(void *arg)
{
	char *input = (char *)arg;
	printf("Started: %s\n", input);
	while(true)
	{
		if (access("/tmp/nice", F_OK) == 0)
		{
			up =1;
		}
		else
		{
			up=0;
		}	

		sleep(1);
	}
	return arg;
}

void createUserPreferenceThread()
{
	 const char *thread_input1 = "User preference thread";
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int rc = pthread_create(&pthread1, &attr, userPreferenceThread, (void *)thread_input1);
	if(rc != 0) 
	{
		printf("Error occurred, thread could not be created, errno = %d\n", rc);
		exit(0);
	}
}
/*
void Write_Account();//function to write record in binary file
void Display(int);//function to display account details given by user
void Modify_Account(int);//function to modify record of file
void Delete_Account(int);//function to delete record of file
void Display_All();//function to display all account details
void Deposit_Withdraw(int, int); // function to desposit/withdraw amount for given account
*/
int main()
{
        Account ac;
	char ch;
	int num;
createUserPreferenceThread();	
	do
	{
    cout<<"userprefernce: "<< up << endl;
	if(up==1){
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
}
else
{
       	cout<<"\n\n\t\t\t\t*~*~*~*~*~*~*~*~*~*~*~\n";
         cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	 cout<<"\n\t\t\t\t*~*~*~*~*~*~*~*~*~*~*~\n";

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
	}

		switch(ch)
		{
		case '1':
			system("clear");
			ac.Write_Account();
			break;
		case '2':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			ac.Deposit_Withdraw(num, 1);
			break;
		case '3':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			ac.Deposit_Withdraw(num, 2);
			break;
		case '4':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			ac.Display(num);
			break;
		case '5':
			ac.Display_All();
			break;
		case '6':
			system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			ac.Delete_Account(num);
			break;
		 case '7':
		 	system("clear");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			ac.Modify_Account(num);
			break;
		 case '8':
		 	system("clear");
			cout<<"\n\n\t\t\tThank You For Using Bank Management System";
			break;
		 default :cout<<"\n\n\t\t\tInvalid Choice!!!!";
		}
		cout<<"\n\n\t\t\tPress Enter to Continue...";
		cin.ignore();
		cin.get();
    }
	while(ch!='8');
	return 0;
}


