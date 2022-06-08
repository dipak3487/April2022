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
                   string RoomType="A";
                     string Comfort="D";
                       string Capacity="S";
                          int Status=0;
                           int Rent_Per_Day=500;
                        CPPUNIT_ASSERT_EQUAL(rm.AddRoom(rm),true);
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
                CPPUNIT_TEST_SUITE_END();

};




