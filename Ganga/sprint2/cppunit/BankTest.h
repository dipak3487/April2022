#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Account.h"


using namespace std;

class AccountTest : public CppUnit::TestFixture
{
	public:
		void Create_Account ()
		{
			int acno=7762;
			char name="Rushi";
			int deposit=2000;
			Account ac(acno,name,deposit);
			int b1 =ac.Withdraw(100);
CPPUNIT_ASSERT_EQUAL(b1,1900);

		}
		
		CPPUNIT_TEST_SUITE(AccountTest);
		CPPUNIT_TEST(Create_Account);
		CPPUNIT_TEST_SUITE_END();
};
