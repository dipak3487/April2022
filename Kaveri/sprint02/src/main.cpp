#include<iostream>
#include<fstream>

#include "employee.h"

using namespace std;

Config config;

int parsecommandline(int argc,char* argv[])
{
	config.setFilePath(argv[1]);
	return 0;
}
int main(int argc,char* argv[])
{
	int choice=0;
	parsecommandline(argc, argv);

	config.readConfig();
	config.readRecords();

	while(1)
	{
		cout<<"1.create new employee details"<<endl;
		cout<<"2.edit employee details"<<endl;
		cout<<"3.delete employee details"<<endl;
		cout<<"4.search employee details"<<endl;
		cout<<"5.edit payroll records for employee"<<endl;
		cout<<"6.Display the complete payslip of an employee"<<endl;
		cout<<"7.EXIT"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
        {
			case 1:
				config.createRecord();
				break;
			case 2:
				config.editRecord();
				break;
			case 3:
				config.deleteRecord();
				break;
			case 4:
				config.searchRecord();
				break;
			case 5:
				config.editpayroll();
				break;
			case 6:
				config.printpayslip();
				break;
			case 7:
				exit(0);
		}
	}
	return 0;
}
