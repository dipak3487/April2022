#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/TestCaller.h>
#include<iostream>
#include<fstream>
#include "vaccineTest.h"
#include "../include/vaccine.h"

//using namespace std;


int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

    runner.addTest(VaccineTest::suite());
	runner.run();
	return 0;
}
