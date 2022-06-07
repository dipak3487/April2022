#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/Room.h"


using namespace std;

class RoomTest : public CppUnit::TestFixture
{
        public:
                 void TestCount ()
                {
                        Room r1;
                       // int count=2;
                       CPPUNIT_ASSERT_EQUAL(r1.TotalRoomCount(),2);
                }


                

                CPPUNIT_TEST_SUITE(RoomTest);
                CPPUNIT_TEST(TestCount);
                CPPUNIT_TEST_SUITE_END();
};

