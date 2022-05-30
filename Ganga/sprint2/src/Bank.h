#ifndef __Bank_h
#define __Bank_h   
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

/*CLASS BANK*/
class bank
{
    private:
        string name;
        int age;
        string address;
        int pin;
        int mobileno;
        int deposite;
        long balance=0;
        long amount=0;
        long accountno;
        int choice1;
      
    public:
        void opennewaccount(); //FUNCTION TO CREATE NEW ACCOUNT
        void depositeamout(); //FUNCTION TO DEPOSITE AMOUNT IN ACCOUNT
        void withdrawtheamount(); //FUNCTION TO WITHDRAW AMOUNT FROM THE ACCOUNT
        void balanceenquiry(); //FUNCTION FOR BALANCE ENQUIRY
        void closingaccount();  //FUNCTION TO CLOSE THE ACCOUNT
        void modifyingaccount();  //FUNCTION TO MODIFY THE USER DATA
       // void issue(); //FUNCTIONS IF USER HAVE ANY ISSUE REGARDING BANKS AND WANT TO COMPLAINT ABOUT IT
        //void loan(); //FUNCTIONS TO APPLY FOR LOAN
        void showall();//FUNCTIONS TO SHOW ALL ACCOUNTS 
		void Exit(); //FUNCTION TO EXIT
        
};
#endif
