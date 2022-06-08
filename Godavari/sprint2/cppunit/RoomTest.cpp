#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
<<<<<<< HEAD
#include "../src/Room.h"
#include "../src/Customer.h"
#include "RoomTest.h"
=======
#include "RoomTest.h"

>>>>>>> 88fe6df5b1d4fcfbf861b3832ced064ae855c97e
using namespace std;
int main(int argc,char* argv[])
{
        CppUnit::TextUi::TestRunner runner;
        runner.addTest(RoomTest::suite());
        runner.run();
        return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 88fe6df5b1d4fcfbf861b3832ced064ae855c97e
