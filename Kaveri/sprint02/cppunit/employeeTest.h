#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "employee.h"

class EmployeeTest : public CppUnit::TestFixture
{
	private:
    //Config *emp;
	//CppUnittest 
	 public:
    void setup()
    {
	//	emp = new Config;
//		emp->readConfig();
//		emp->readRecords();
//		parsecommandline(int argc,char* argv[]);
	}
    void tearDown()
    {
	//	delete emp;
	}
    void sunnytestsearchRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.searchRecord(str),true);
	}
    void rainytestsearchRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str1="R3267";
		CPPUNIT_ASSERT_EQUAL(config1.searchRecord(str1),false);
	}
    void sunnytestcreateRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string newcode="E1896";
		std::string newname="shikar dhawan";
		int newsalary=25000;
		std::string newtitle="analyst";

		CPPUNIT_ASSERT_EQUAL(config1.createRecord(newcode,newname,newsalary,newtitle),true);
	}
    void sunnytesteditRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str1="E1003";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.editRecord(str1,name,salary,title),true);
	}
    void rainytesteditRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str1="P1023";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.editRecord(str1,name,salary,title),false);
	}
    void sunnytestdeleteRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.deleteRecord(str),true);
	}
    void rainytestdeleteRecord()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str="Z2312";
		CPPUNIT_ASSERT_EQUAL(config1.deleteRecord(str),false);
	}
    void sunnygetpayrolldetails()
    {
		CppUnittest config1;
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.getpayrolldetails(str),true);
	}

	CPPUNIT_TEST_SUITE(EmployeeTest);
    CPPUNIT_TEST(sunnytestsearchRecord);
    CPPUNIT_TEST(rainytestsearchRecord);
    CPPUNIT_TEST(sunnytestdeleteRecord);
    CPPUNIT_TEST(rainytestdeleteRecord);
    CPPUNIT_TEST(sunnytestcreateRecord);
	CPPUNIT_TEST(sunnytesteditRecord);
	CPPUNIT_TEST(rainytesteditRecord);
	CPPUNIT_TEST(sunnygetpayrolldetails);
    //CPPUNIT_TEST(weDontWantException);
   // CPPUNIT_TEST_EXCEPTION(weWantException,std::exception);
    //CPPUNIT_TEST_EXCEPTION(weDontWantException,std::exception);
    CPPUNIT_TEST_SUITE_END();
	

};


