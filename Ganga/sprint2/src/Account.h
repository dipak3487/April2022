#ifndef __bankmanagement_h
#define __bankmanagement_h

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Bank.h"
class Account
{
//FUNCTION DECLARATION 
public:
    void opennewaccount();
    void depositeamout();
    void withdrawtheamount();
    void balanceenquiry();
    void closingaccount();
    void modifyingaccount();
   // void issue();
    void showall();
    //void loan();
    void Exit();
};
#endif
