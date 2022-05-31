#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/employee.h"

class EmployeeTest : public CppUnit::TestFixture
{
	private:
	 public:
    void setup()
    {
	}
    void tearDown()
    {
	}
    void sunnytestsearchRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.searchRecordInp(str),true);
	}
    void rainytestsearchRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str1="R3267";
		CPPUNIT_ASSERT_EQUAL(config1.searchRecordInp(str1),false);
	}
    void sunnytestcreateRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string newcode="E1896";
		std::string newname="shikar dhawan";
		int newsalary=25000;
		std::string newtitle="analyst";

		CPPUNIT_ASSERT_EQUAL(config1.createRecordInp(newcode,newname,newsalary,newtitle),true);
	}
    void sunnytesteditRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str1="E1003";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.editRecordInp(str1,name,salary,title),true);
	}
    void rainytesteditRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str1="P1023";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.editRecordInp(str1,name,salary,title),false);
	}
    void sunnytestdeleteRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.deleteRecordInp(str),true);
	}
    void rainytestdeleteRecord()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str="Z2312";
		CPPUNIT_ASSERT_EQUAL(config1.deleteRecordInp(str),false);
	}
    void sunnygetpayrolldetails()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.getpayrolldetailsInp(str),true);
	}
    void rainygetpayrolldetails()
    {
		Config config1;
		config1.setFilePath("../config/employeeRecords.json");
		config1.readConfig();
		config1.readRecords();
		std::string str="x1023";
		CPPUNIT_ASSERT_EQUAL(config1.getpayrolldetailsInp(str),false);
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
	CPPUNIT_TEST(rainygetpayrolldetails);
    CPPUNIT_TEST_SUITE_END();
};


