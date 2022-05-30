#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/employee.h"

class EmployeeTest : public CppUnit::TestFixture
{
	private:
    Config *emp;

	 public:
    void setup()
    {
		emp = new Config;
//		emp->readConfig();
//		emp->readRecords();
//		parsecommandline(int argc,char* argv[]);
	}
    void tearDown()
    {
	//	delete emp;
	}
    void testsearchRecord()
    {
		//config1 = new Config;
		Config config1;
		config1.readConfig();
		config1.readRecords();
		//std::string record = emp->searchRecord("E1003");
		//bool ret = record.compare("true");
		CPPUNIT_ASSERT_EQUAL(config1.searchRecord(),true);
//		CPPUNIT_ASSERT_EQUAL(emp->mymath(),2);
	}
	CPPUNIT_TEST_SUITE(EmployeeTest);
	//CPPUNIT_TEST(setup);
    CPPUNIT_TEST(testsearchRecord);
    //CPPUNIT_TEST(weDontWantException);
    //CPPUNIT_TEST_FAIL(rainyTestforPageCount);
   // CPPUNIT_TEST_EXCEPTION(weWantException,std::exception);
    //CPPUNIT_TEST_FAIL(rainyTestforPageCount);
    //CPPUNIT_TEST_EXCEPTION(weDontWantException,std::exception);
    //CPPUNIT_TEST(runTest);
    CPPUNIT_TEST_SUITE_END();
	

};


