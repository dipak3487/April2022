#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>
#include "vaccine.h"
#include <sqlite3.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}




class VaccineTest : public CppUnit::TestFixture
{

	public:
		void setup()
		{
		}
		void tearDown()
		{
		}

		void sunnytest()
		{	
			sqlite3* db;
			char* zErrMsg=0;
			int rc;
			int count = 0;


		rc = sqlite3_open("example.db", &db);
		std::ostringstream temp;
		std::string command;


	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	} else {
		fprintf(stderr, "Opened database successfully\n");
	}
		rc = sqlite3_exec(db, "select count(*) from VACCINE_INVENTORY", callback, &count, &zErrMsg);


			if( rc != SQLITE_OK ){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			} else {
			fprintf(stdout, "Records created successfully\n");
			}

			Vaccine vac;
			vac.CountRecords();
			CPPUNIT_ASSERT_EQUAL(vac.CountRecords(),16);
			sqlite3_close(db);


		}

		CPPUNIT_TEST_SUITE(VaccineTest);
		CPPUNIT_TEST(sunnytest);
		CPPUNIT_TEST_SUITE_END();


};


