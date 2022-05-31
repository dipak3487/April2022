#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/car.h"
#include "../include/rentals.h"
#include "../include/customer.h"
#include "../include/date.h"
#include "carrentalTest.h"
using namespace std;
int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(CarTest::suite());
	runner.run();
	return 0;
}
