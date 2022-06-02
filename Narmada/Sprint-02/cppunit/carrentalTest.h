#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "car.h"
//#include "rentals.h"
//#include "customer.h"
#include "date.h"

using namespace std;

class CarTest : public CppUnit::TestFixture
{
	public:
		void TestCarData()
		{
			string reg_no="BR29EZ7762";
			string company1="Hyundai";
			string model1="2017";
			double cost_per_day=1500;
			Car car1(reg_no,company1,model1,cost_per_day);
			CPPUNIT_ASSERT_EQUAL(save(car1),true);
		}

		CPPUNIT_TEST_SUITE(CarTest);
		CPPUNIT_TEST(TestCarData);
		CPPUNIT_TEST_SUITE_END();
};


