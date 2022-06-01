#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Account.h"
#include "BankTest.h"

using namespace std;
int main(int argc,char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(AccountTest::suite());
	runner.run();
	return 0;
}
