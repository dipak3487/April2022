#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdlib.h>
#include "Bank.h"
#include "Account.h"
int main()
{
    int choice;
    bank b;



        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t******************************************************"<<endl;
        cout<<"\t\t\t\t\t\t********************WELCOME TO THE BANK***************"<<endl;
        cout<<"\t\t\t\t\t\t******************************************************"<<endl;
        cout<<"\n\n";
        RET:
        cout<<"\n\n\t\t\t\t\t\t\t\t\t***MAIN MENU***\n";
        cout<<"\t\t\t\t\t\t\t 1]  Opening a new Account\n\n";
        cout<<"\t\t\t\t\t\t\t 2]  Deposting the Amount\n\n";
        cout<<"\t\t\t\t\t\t\t 3]  Withdrawing the Amount\n\n";
        cout<<"\t\t\t\t\t\t\t 4]  Balance Enquiry\n\n";
        cout<<"\t\t\t\t\t\t\t 5]  Closing your Account\n\n";
        cout<<"\t\t\t\t\t\t\t 6]  Modifing your Current data of Aaccount\n\n";
        cout<<"\t\t\t\t\t\t\t 7]  Show All Accounts\n\n";
       // cout<<"\t\t\t\t\t\t\t 7]  If you want to apply for Loan\n\n";
        cout<<"\t\t\t\t\t\t\t 8]   EXIT\n\n";

   
    //cout<<"Here is the Main Menu\n";
    
    cout<<"\t\t\t\t\t\t\tPlease Enter Your choice.\n";
    cin>>choice;

    switch(choice)
    {
        case 1 :
            b.opennewaccount();
                break;
        case 2:
            b.depositeamout();
                break;
        case 3:
            b.withdrawtheamount();
                break;
        case 4:
            b.balanceenquiry();
                break;
        case 5:
            b.closingaccount();
                break;
        case 6:
            b.modifyingaccount();
                break;
        case 7:
            b.showall();
                break;
        case 8:
            b.Exit();
                break;
        default:
            cout<<"\n\t\t\t\t\t\tinvalide choice";

        
    }
    cout<<"\n\t\t\t\t\t\tDo you want continue press (1):-";
    int yes;
    cin>>yes;
    if(yes==1)
    {
        goto RET;
    }
   


    return 0;
}
