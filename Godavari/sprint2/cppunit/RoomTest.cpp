#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/Room.h"
#include "../src/Customer.h"
#include "RoomTest.h"
using namespace std;
int main(int argc,char* argv[])
{
        CppUnit::TextUi::TestRunner runner;
        runner.addTest(RoomTest::suite());
        runner.run();
        return 0;
}
