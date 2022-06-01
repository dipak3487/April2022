#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "employee.h"

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
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.SearchRecordInp(str),true);
	}
    void rainytestsearchRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str1="R3267";
		CPPUNIT_ASSERT_EQUAL(config1.SearchRecordInp(str1),false);
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

		CPPUNIT_ASSERT_EQUAL(config1.CreateRecordInp(newcode,newname,newsalary,newtitle),false);
	}


    void sunnytesteditRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str1="E1003";
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

		CPPUNIT_ASSERT_EQUAL(config1.EditRecordInp(str1,name,salary,title),false);
	}
    void sunnytestdeleteRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.DeleteRecordInp(str),true);
	}
    void rainytestdeleteRecord()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="Z2312";
		CPPUNIT_ASSERT_EQUAL(config1.DeleteRecordInp(str),false);
	}
    void sunnygetpayrolldetails()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="E1003";
		CPPUNIT_ASSERT_EQUAL(config1.GetPayrollDetailsInp(str),true);
	}
    void rainygetpayrolldetails()
    {
		Config config1;
		config1.SetFilePath("../InputFiles/employeeRecords.json");
		config1.ReadConfig();
		config1.ReadRecords();
		std::string str="x1023";
		CPPUNIT_ASSERT_EQUAL(config1.GetPayrollDetailsInp(str),false);
	}

	CPPUNIT_TEST_SUITE(EmployeeTest);
    CPPUNIT_TEST(sunnytestsearchRecord);
    CPPUNIT_TEST(rainytestsearchRecord);
    CPPUNIT_TEST(sunnytestdeleteRecord);
    CPPUNIT_TEST(rainytestdeleteRecord);
    CPPUNIT_TEST(sunnytestcreateRecord);
    CPPUNIT_TEST(rainytestcreateRecord);
	CPPUNIT_TEST(sunnytesteditRecord);
	CPPUNIT_TEST(rainytesteditRecord);
	CPPUNIT_TEST(sunnygetpayrolldetails);
	CPPUNIT_TEST(rainygetpayrolldetails);
    CPPUNIT_TEST_SUITE_END();
};


