#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/TestCaller.h>

#include<iostream>
#include<fstream>
#include "employeeTest.h"
#include "../include/employee.h"

using namespace std;


int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

    runner.addTest(EmployeeTest::suite());
	runner.run();
	return 0;
}
