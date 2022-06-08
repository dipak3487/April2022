/*FILENAME	:	rentals.h
 *
 *
 * DESCRIPTION	:	This file contains all the user-defined functions declarations.
 *
 */

#ifndef RENTALS_H
#define RENTALS_H

#include <iostream>
#include "date.h"
#include "car.h"
#include "customer.h"

int getCurrentRentalID();
static int rental_id = getCurrentRentalID();

class Rental {
	public:
		Rental();
		Rental(const Rental&);
		Rental(Date, Customer, Car);
		double calculateBill();
		bool chkPaid();
		//int chkPaid(int rental_id);
		//int getRental(int rental_id);
		//int save(int cust_id,int car_id,Date rent_date);

		friend bool save(Rental);
		friend Rental getRental(int);
		friend std::ostream& operator<< (std::ostream&, const Rental&);

	private:
		int rentalID;
		Date rentDate, returnDate;
		Customer cust;
		Car car;
		double costPaid;
		bool isPaid;
};

Rental newRental();
bool save(Rental);
Rental getRental(int);

#endif
