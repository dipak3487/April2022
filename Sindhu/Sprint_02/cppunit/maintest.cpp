#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/TestCaller.h>
#include<iostream>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>
#include<fstream>
#include "vaccineTest.h"
#include "vaccine.h"

using namespace std;




int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
        runner.addTest(VaccineTest::suite());
	runner.run();
	return 0;
}
