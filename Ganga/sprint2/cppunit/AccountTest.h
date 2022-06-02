#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Account.h"


using namespace std;

class AccountTest : public CppUnit::TestFixture
{
	public:
		void TransactionTest ()
		{
			int acno=7762;
			char name[]="Rushi";
			int deposit=2000;
			Account ac(acno,name,deposit);
			ac.Withdraw(100);
			CPPUNIT_ASSERT_EQUAL(ac.Retdeposit(),1900);
			ac.Deposit(200);
			CPPUNIT_ASSERT_EQUAL(ac.Retdeposit(),2100);


		}
		
		CPPUNIT_TEST_SUITE(AccountTest);
		CPPUNIT_TEST(TransactionTest);
		CPPUNIT_TEST_SUITE_END();
};
