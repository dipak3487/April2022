#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "employee.h"

class EmployeeTest : public CppUnit::TestFixture
{
	 public:
    void sunnytestsearchRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1004";
		CPPUNIT_ASSERT_EQUAL(config1.SearchRecordInp(str),true);
	}
    void rainytestsearchRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str1="R3267";
		CPPUNIT_ASSERT_EQUAL(config1.SearchRecordInp(str1),true);
	}
    void sunnytestcreateRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string newcode="E8234";
		std::string newname="hardik pandya";
		int newsalary=20000;
		std::string newtitle="analyst";

		CPPUNIT_ASSERT_EQUAL(config1.CreateRecordInp(newname,newcode,newsalary,newtitle),true);
	}
    void rainytestcreateRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string newcode="E18";
		std::string newname="shikar dhawan";
		int newsalary=-1234;
		std::string newtitle="a4";

		CPPUNIT_ASSERT_EQUAL(config1.CreateRecordInp(newcode,newname,newsalary,newtitle),true);
	}
    void sunnytesteditRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str1="E1004";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.EditRecordInp(str1,name,salary,title),true);
	}
    void rainytesteditRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str1="P1023";
		std::string name="raghu ram";
		int salary=22000;
		std::string title="assistant";

		CPPUNIT_ASSERT_EQUAL(config1.EditRecordInp(str1,name,salary,title),true);
	}
    void sunnytestdeleteRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1004";
		CPPUNIT_ASSERT_EQUAL(config1.DeleteRecordInp(str),true);
	}
    void rainytestdeleteRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="Z2312";
		CPPUNIT_ASSERT_EQUAL(config1.DeleteRecordInp(str),true);
	}
    void sunnygetpayrolldetails()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1004";
		CPPUNIT_ASSERT_EQUAL(config1.GetPayrollDetailsInp(str),true);
	}
    void rainygetpayrolldetails()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="x1023";
		CPPUNIT_ASSERT_EQUAL(config1.GetPayrollDetailsInp(str),true);
	}

	CPPUNIT_TEST_SUITE(EmployeeTest);
    CPPUNIT_TEST(sunnytestsearchRecord);
    CPPUNIT_TEST_FAIL(rainytestsearchRecord);
    CPPUNIT_TEST(sunnytestdeleteRecord);
    CPPUNIT_TEST_FAIL(rainytestdeleteRecord);
    CPPUNIT_TEST(sunnytestcreateRecord);
    CPPUNIT_TEST_FAIL(rainytestcreateRecord);
	CPPUNIT_TEST(sunnytesteditRecord);
	CPPUNIT_TEST_FAIL(rainytesteditRecord);
	CPPUNIT_TEST(sunnygetpayrolldetails);
	CPPUNIT_TEST_FAIL(rainygetpayrolldetails);
    CPPUNIT_TEST_SUITE_END();
};


