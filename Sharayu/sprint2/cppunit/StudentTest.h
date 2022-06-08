#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Student.h"


using namespace std;

class StudentTest : public CppUnit::TestFixture
{
	public:
		void testaddReport ()
		{
			int English = 40;
			 int Math = 45;
			 int Science = 50;
			 int Social = 60;
			 int History = 70;
			
			Student newStudent;
			newStudent.setMarks(English,Math,Science,Social,History);
			
			CPPUNIT_ASSERT_EQUAL(newStudent.calculateTotal(),265);


		}
		
		CPPUNIT_TEST_SUITE(StudentTest);
		CPPUNIT_TEST(testaddReport);
		CPPUNIT_TEST_SUITE_END();
};
