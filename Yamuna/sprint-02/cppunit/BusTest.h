#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Bus.h"
#include "json.h"


using namespace std;

class BusTest : public CppUnit::TestFixture
{
	public:
		void TransactionTest ()
		{
			Bus ac(acno,name,deposit);
			ac.Withdraw(100);
			CPPUNIT_ASSERT_EQUAL(ac.Retdeposit(),1900);
			ac.Deposit(200);
			CPPUNIT_ASSERT_EQUAL(ac.Retdeposit(),2100);


		}
		
		CPPUNIT_TEST_SUITE(BusTest);
		CPPUNIT_TEST(TransactionTest);
		CPPUNIT_TEST_SUITE_END();
};
