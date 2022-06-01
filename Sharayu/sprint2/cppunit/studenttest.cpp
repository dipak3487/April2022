#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/TestCaller.h>

#include<iostream>
#include<fstream>
#include "studenttest.h"

using namespace std;


int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;

    runner.addTest(StudentTest::suite());
	runner.run();
	return 0;
}
