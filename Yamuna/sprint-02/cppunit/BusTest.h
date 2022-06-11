#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Bus.h"
#include "json.h"


using namespace std;

class BusTest : public CppUnit::TestFixture
{
public:
	void BusDbTest()
	{
		readJsonFile("BusTest.json");
		int busCount = busses.size();
		CPPUNIT_ASSERT_EQUAL(busCount, 0);
	}

	CPPUNIT_TEST_SUITE(BusTest);
	CPPUNIT_TEST(BusDbTest);
	CPPUNIT_TEST_SUITE_END();
};
