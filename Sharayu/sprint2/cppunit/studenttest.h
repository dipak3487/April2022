#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class StudentTest : public CppUnit::TestFixture
{
	
	 public:
	void setup(){
	}		
	void tearDown(){
	}

	void TestaddReport()
	{
	//add report testing
	}
	 void TestupdateReport()
	{
	//
	}
	 void TestremoveReport()
	{

	//

	}

	void TestshowReports()
	{

	//

	}
	void Testactions()
	{

	//

	}
	CPPUNIT_TEST_SUITE(StudentTest);		
	CPPUNIT_TEST(TestaddReport);
	CPPUNIT_TEST(TestupdateReport);
	CPPUNIT_TEST(TestremoveReport);
	CPPUNIT_TEST(TestshowReports);
	CPPUNIT_TEST(Testactions);
	CPPUNIT_TEST_SUITE_END();
};
