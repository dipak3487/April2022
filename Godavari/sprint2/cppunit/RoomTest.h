#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
<<<<<<< HEAD
#include "Room.h"
class RoomTest: public CppUnit::TestFixture{
public:
                void AddRoomData()
                {
                        Room rm;
                      int  room_no=3;
                   string RoomType="A";
                     string Comfort="D";
                       string Capacity="S";
                          int Status=0;
                           int Rent_Per_Day=500;
                        CPPUNIT_ASSERT_EQUAL(save(rm),true);
                }
/*
  void RoomData()
                {
                        Room rm;
                      int  room_no=3;
                   string RoomType="A";
                     string Comfort="D";
                       string Capacity="S";
                          int Status=0;
                           int Rent_Per_Day=500;
                        CPPUNIT_ASSERT_FAIL(Save(rm),true);
                }
   void   ModifyRoomData()
                {
                        Room rm1;
                      int  room_no=3;
                   string RoomType="A";
                     string Comfort="D";
                       string Capacity="b";
                          int Status=1;
                           int Rent_Per_Day=600;
                        CPPUNIT_ASSERT_EQUAL(  ModifyRoom(rm1),true);
                }


*/
   CPPUNIT_TEST_SUITE(RoomTest);
                CPPUNIT_TEST(AddRoomData);
              //  CPPUNIT_TEST(  ModifyRoomData);
                //CPPUNIT_TEST(RoomData);
               // CPPUNIT_TEST_SUITE_END();

};
=======
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

>>>>>>> 88fe6df5b1d4fcfbf861b3832ced064ae855c97e
