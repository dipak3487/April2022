#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/Room.h"
#include "../include/HotelManager.h"

using namespace std;

class RoomTest : public CppUnit::TestFixture
{
        public:
                void TestConstructor ()
                {
                        Room r3("D","A","S",0,100);
                        CPPUNIT_ASSERT(r3.getType() == std::string("D"));
                        CPPUNIT_ASSERT(r3.getComfort() == std::string("A"));
                        CPPUNIT_ASSERT(r3.getCapacity() == std::string("S"));
                        CPPUNIT_ASSERT_EQUAL(r3.getStatus(),0);
                        CPPUNIT_ASSERT_EQUAL(r3.getRent(),100);



                }
  void TestCount()
                 {
                   Room r4;
                   CPPUNIT_ASSERT_EQUAL(r4.getAvailableRoomsCount(),1);
                 }



                CPPUNIT_TEST_SUITE(RoomTest);
               // CPPUNIT_TEST_SUITE(TestAddRoom);
                CPPUNIT_TEST(TestConstructor);
                CPPUNIT_TEST(TestCount);
                CPPUNIT_TEST_SUITE_END();
};