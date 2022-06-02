#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "car.h"
//#include "rentals.h"
//#include "customer.h"
#include "date.h"
#include "carrentalTest.h"
using namespace std;
Date todayDate;
int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(CarTest::suite());
	runner.run();
	return 0;
}
