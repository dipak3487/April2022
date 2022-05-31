#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/car.h"
#include "../include/rentals.h"
#include "../include/customer.h"
#include "../include/date.h"

using namespace std;

class CarTest : public CppUnit::TestFixture
{
	public:
		void CarDataAdd()
		{
			Car car1;
			string reg_no="BR29EZ7762";
			string company1="Hyundai";
			string model1="2017";
			double cost_per_day=1500;
			CPPUNIT_ASSERT_EQUAL(save(car1),true);
		}
		void AddCustomer()
		{
			Customer customer1;
			string name1="Sonu";
			string phone_no="9523813908";
			string email="pks19023@gmail.com";
			string res_addr="Pune";
			string id_proof="123456";
			CPPUNIT_ASSERT_EQUAL(save(name1,phone_no,email,res_addr,id_proof),true);
		}

		void RentalCreate()
		{
			Rental rental1;
			int cust_id=1;
			int car_id=2;
			Date rent_date;
			CPPUNIT_ASSERT_EQUAL(save(rental1),true);
		}

		void CustomerModify()
		{
			Customer customer1;
			string name1="Aishwarya";
			string phone_no="9523813456";
			string email="aish@gmail.com";
			string res_addr="Pune";
			string id_proof="12345678";
			CPPUNIT_ASSERT_EQUAL(modify(customer1),true);
		}

		void SingleCardetails()
		{
			Car car2;
			int car_id=1;
			CPPUNIT_ASSERT_EQUAL(car2.getCar(car_id),true);
		}

		void DisplayAllCars()
		{
			Car car3;
			int option1=6;
			CPPUNIT_ASSERT_EQUAL(car3.displayAllCars(option1),true);
		}

		void DisplayCustomerDetails()
		{
			Customer customer2;
			int cust_id=1;
			CPPUNIT_ASSERT_EQUAL(customer2.getCustomer(cust_id),true);
		}

		void CarCostModify()
		{
			Car car4;
			int car_id=1;
			double cost_per_day=1500;
			CPPUNIT_ASSERT_EQUAL(modify(car4),true);
		}

		void DisplayRentalData()
		{
			Rental rental2;
			int rental_id=1;
			CPPUNIT_ASSERT_EQUAL(rental2.getRental(rental_id),true);
		}

		void RentalBill()
		{
			Rental rental3;
			int rental_id=1;
			CPPUNIT_ASSERT_EQUAL(chkPaid(rental3),true);
		}

		CPPUNIT_TEST_SUITE(CarTest);
		CPPUNIT_TEST(CarDataAdd);
		CPPUNIT_TEST(AddCustomer);
		CPPUNIT_TEST(RentalCreate);
		CPPUNIT_TEST(CustomerModify);
		CPPUNIT_TEST(SingleCardetails);
		CPPUNIT_TEST(DisplayAllCars);
		CPPUNIT_TEST(DisplayCustomerDetails);
		CPPUNIT_TEST(CarCostModify);
		CPPUNIT_TEST(DisplayRentalData);
		CPPUNIT_TEST(RentalBill);
		CPPUNIT_TEST_SUITE_END();
};


