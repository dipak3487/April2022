#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Room.h"
class RoomTest: public CppUnit::TestFixture{
public:
                void AddRoomData()
                {
                        Room rm;
                      int  room_no=3;
                   string roomtype="A";
                     string comfort="D";
                       string capacity="S";
                          int status=0;
                           int rent_per_day=500;
                        CPPUNIT_ASSERT_EQUAL(save(rm),true);
                }
/*
  void RoomData()
                {
                        Room rm;
                      int  room_no=3;
                   string roomtype="A";
                     string comfort="D";
                       string capacity="S";
                          int status=0;
                           int rent_per_day=500;
                        CPPUNIT_ASSERT_FAIL(Save(rm),true);
                }
   void ModifyRoomData()
                {
                        Room rm1;
                      int  room_no=3;
                   string roomtype="A";
                     string comfort="D";
                       string capacity="b";
                          int status=1;
                           int rent_per_day=600;
                        CPPUNIT_ASSERT_EQUAL(ModifyRoom(rm1),true);
                }


*/
   CPPUNIT_TEST_SUITE(RoomTest);
                CPPUNIT_TEST(AddRoomData);
              //  CPPUNIT_TEST(ModifyRoomData);
                //CPPUNIT_TEST(RoomData);
               // CPPUNIT_TEST_SUITE_END();

};
