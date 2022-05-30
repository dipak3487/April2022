#include <cstring>
#include "Account.h"
#include "Bank.h"
using namespace std;
  
void bank :: opennewaccount()
{
	    cout<<"\n\t\t\t\t\t\tWelcome to Our bank service.\n\n"<<endl;
        //cout<<"Please fill the below information\n";
        ofstream os;  
        os.open("file.txt");  
       // cout <<"Writing to a text file:" << endl;  
        cout << "\t\t\t\t\t\tEnter your name :\n" <<endl;
        cin.ignore();
        getline(cin,name); 
	    os <<name << endl;  
        cout << "\t\t\t\t\t\tPlease Enter your age:\n";   
        cin >> age;  
        cin.ignore();  
        os << age << endl; 
        cout << "\t\t\t\t\t\tEnter your address :\n" << endl;
        cin.ignore();
        getline(cin,address); 
        os << address << endl;  
        cout << "\t\t\t\t\t\tPlease Enter your Account no:\n";   
        cin >> accountno;  
        cin.ignore();  
        os << accountno << endl;  
        cout << "\t\t\t\t\t\tPlease Enter your Pin code:\n";   
        cin >> pin;  
        cin.ignore();  
        os << pin << endl;
        cout << "\t\t\t\t\t\tPlease Enter your mobile number:\n";   
        cin >>mobileno;  
        cin.ignore();  
        os << mobileno<< endl;  
        cout << "\t\t\t\t\t\tPlease Enter the amount you want to deposite:\n";   
        cin >> balance;  
        cin.ignore();  
        os << balance<< endl; 

        os.close();  

            
}


      void bank :: depositeamout()
    {
       
        cout<<"\n\t\t\t\t\t\tDear custmore please enter your account no\n"<<endl;
        cin>>accountno;
        cout<<"\n\t\t\t\t\t\tEnter the amount you want to deposite\n"<<endl;
        cin>>amount;
        balance=balance+amount;
        cout<<"\n\t\t\t\t\t\tAmount deposited succefully!!!!!\n"<<endl;
        cout<<"\n\t\t\t\t\t\tTotal balance in the accout is "<<balance<<"rs\n"<<endl;

    }

      void bank :: withdrawtheamount()
    {
        cout<<"\n\t\t\t\t\t\tDear custmore please enter your account no\n"<<endl;
        cin>>accountno;
        cout<<"\n\t\t\t\t\t\tEnter the amount you want to withdraw\n";
        cin>>amount;
        if(amount>balance)
        {
            cout<<"\n\t\t\t\t\t\tInsuffient balance\n";
        }
        else
        {
            balance=balance-amount;
        cout<<"\n\t\t\t\t\t\tAmount withdraw succefully!!!\n";
        cout<<"\n\t\t\t\t\t\tTotal balance in the accout is:"<<balance<<"Rs\n";
        }
        
    }



     void bank :: balanceenquiry()
     {
         cout<<"\n\t\t\t\t\t\tdear customer please enter your account no\n";
         cin>>accountno;
         cout<<"\n\t\t\t\t\t\tYour current balance is "<<balance;
     }


   
    
    void bank::closingaccount()
{
int n;
	bank ac;
	ifstream inFile;
	ofstream outFile;
	cout<<"enter account no";cin>>accountno;
	inFile.open("file.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("file");
	inFile.seekg(0);
	while(inFile.read((char *) (&ac), sizeof(bank)))
	{
		if(ac.accountno!=n)
		{
			outFile.write((char *) (&ac), sizeof(bank));
		}
	}
	inFile.close();
	outFile.close();
	remove("file.txt");
	rename("Temp","file.txt");
	cout<<"\n\n\tRecord Deleted ..";
}

        /*  FILE *fp,*temp;
		  // long accountno;
	   cout<<"Enter Account Number for Remove"<<accountno;
		   cin>>accountno;
    fp = fopen("file.txt", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {

        printf("Error in file opening, Plz try again !\n");
       // printf("Press any key to continue....\n");
        return;
     }
     else
     {
         long *p; int flag = 0;
		 
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
        if(strcmp(p.accountno,accountno)==0) 
           {
                system("clear");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("clear");
            printf("No record found for %ld accountno\n",accountno);
        }
        fclose(fp);
        fclose(temp);
        remove("file.txt");
        rename("temp","file.txt");
        fflush(stdin);
       // printf("Press any key to continue....\n");

    }

    
    }*/

      void bank :: modifyingaccount()
    {   


    }


	void bank :: showall()
	{
      system("clear");
	   FILE *fp;
	   fp =fopen("file.txt","rb");
	   if(fp==NULL)
	   {
		   cout<<"\t\t\t\t\t\tError in file opening, please try again!!!!\n";
		   cout<<"\t\t\t\t\t\tPress Enter to Continue.....\n";
	   }
	   else
	   {
		struct  *p;
		cout<<"\t\t\t\t\t\tHere is all records"<<endl;
			while(fread(&p,sizeof(p),1,fp)==1)
			{
			cout<<"name:"<<name<<endl;
				cout<<"\n";
			}
		fclose(fp);
	   }
	}

      void bank :: Exit()
    {
            cout<<"\n\t\t\t\t\t\t*****Thank you! We are glad to help you!!!*****";
            cout<<"\n\t\t\t\t\t\t*****Visit us again*****";

    }
