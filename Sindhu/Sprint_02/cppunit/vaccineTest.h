#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/vaccine.h"


class VaccineTest : public CppUnit::TestFixture
{
	private:
	public:
		void setup()
		{
		}
		void tearDown()
		{
		}

		void sunnytest()
		{	
			Vaccine vac;
			vac.countRecords();
			CPPUNIT_ASSERT_EQUAL(vac.countRecords(),15);

		}
		/*
		   void rainytestSearchCitizenRecord()
		   {
		   Vaccine vac;
		   vac.search_name();
		   std::string str="test/";
		   CPPUNIT_ASSERT_EQUAL(vac.search_name(str),false);

		   }
		 */
		CPPUNIT_TEST_SUITE(VaccineTest);
		CPPUNIT_TEST(sunnytest);
//		CPPUNIT_TEST(rainytestSearchCitizenRecord);

};


