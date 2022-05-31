/*FILENAME	:	rentals.cpp
 *
 * DESCRIPTION	:	This file hasuser-defined functions for calculating Rental bill for the user, how many
 * 			times a car is rented, display payment details. Using sqlite3 queries in this file
 * 			we also store rental_id, cust_id, car_id, date of rent and return etc. details
 * 			in the database. We can get rental data also from this file using getRental function.
 *
 *
 * 			CHANGES MADE BY TEAM NARMADA
 *
 */ 				

#include <iostream>
#include <sqlite3.h>
#include "../include/rentals.h"

int getCurrentRentalID() {    //this function returns the rental id for a customer who rents a car.
	//establishing connection with database
	//After displaying rental id it will close the connection to DB unless/until user wants to see rental id
	sqlite3 *DB;
	int conn = 0;
	conn = sqlite3_open("database.db", &DB);
	sqlite3_stmt *statement;
	std::string sql = "SELECT rental_id FROM rental;";
	sqlite3_prepare(DB, sql.c_str(), -1, &statement, 0);
	int id = 0;

	while(sqlite3_step(statement) != SQLITE_DONE) {
		id = sqlite3_column_int(statement, 0);
	}
	sqlite3_close(DB);
	return id + 1;
}

Rental::Rental() {     //Scope resolution operator used here
	               //'rental' constructor is declared here for rental class
		       //If user gives incorrect rental id, then it will return rentDate = 01 01 2000, returnDate = 0 0 0, costPaid = 0 & rent paid as 'FALSE' 	
        rentalID = -1;
	rentDate = Date(1, 1, 2000);
	returnDate = Date(0,0,0);
	Customer c;
	cust = c;
	Car cr;
	car = cr;
	costPaid = 0;
	isPaid = false;
}

Rental::Rental(const Rental& rental2) {    //Scope reolution operator used here
	                                   //Parameterised cosntructor 'rental' used here with rental& rental2 as arguments
	rentalID = rental2.rentalID;
	rentDate = rental2.rentDate;
	returnDate = rental2.returnDate;
	cust = rental2.cust;
	car = rental2.car;
	costPaid = rental2.costPaid;
	isPaid = false;
}

Rental::Rental(Date _rentDate, Customer _cust, Car _car) {
	rentalID = rental_id;
	rentDate = _rentDate;
	returnDate = Date(0,0,0);
	cust = _cust;
	car = _car;
	costPaid = 0;
	isPaid = false;
}

bool Rental::chkPaid() {    //If cost paid then return boolean value (0,1) - if true -> 1 & if false -> 0
	if (isPaid) {
		return true;
	}
	return false;
} 

double Rental::calculateBill() {    //calculatebill returns the amount to be paid by the customer for rented car
	                            //Establish an connection to DB for updation of values - If unable to establish connection with DB then print "errMssg"
	                            //Update the rentals table fields - amount paid or not (with Value)
				    //closes the connection to DB when set of operations are performed on the tables
	returnDate = todayDate;
	int noOfdays = getDifference(rentDate, returnDate);
	costPaid = car.getCost()*noOfdays;
	std::string sql = "UPDATE rental SET dateOfReturn = \"" + returnDate.returnSQLDate() + "\", cost = " + std::to_string(costPaid) + ", isPaid = true WHERE rental_id = " + std::to_string(rentalID) + ";";
	sqlite3 *DB;
	int connection = 0;
	connection = sqlite3_open("database.db", &DB);
	char *errMsg;
	connection = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
	if (connection != SQLITE_OK) {
		std::cerr << "DB Error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	sql = "UPDATE cars SET isRented = false WHERE car_id = " + std::to_string(car.getCarID()) + ";";
	connection = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
	if (connection != SQLITE_OK) {
		std::cerr << "DB Error: " << errMsg << std::endl;
		sqlite3_free(errMsg);
	}
	sqlite3_close(DB);
	return costPaid;
}

std::ostream& operator<< (std::ostream& os, const Rental& rental) {
	os << "\t\t\t\tRental ID: " << rental.rentalID << std::endl;
	os << "\nRent Date: " << rental.rentDate << "\t\t\t\t";
	os << "Return Date: " << rental.returnDate << std::endl;
	// if ((Date) rental.returnDate != Date(0, 0, 0)) {
	//     os << rental.returnDate << std::endl;
	// } else {
	//     os << "N/A" << std::endl;
	// }
	os << "\n================================ Customer Details ===============================\n" << std::endl;
	os << rental.cust << std::endl;
	os << "\n================================ Car Detials ==================================\n" << std::endl;
	os << rental.car;

	if (rental.isPaid) {
		os << std::endl;
		os << "\n============================= Payment Detials ===============================\n" << std::endl;
		os << "Rent Paid: YES\t\t\t\tCost Paid: " << rental.costPaid;
	}

	return os;
}
//this save() function will save the rental information to the rental table in database.
//Inserting values into rental table
//Establish connection to DB for updating set of records in rental table - If unable to establish connection print error message "Error inserting records" else print "Record save successfully"
//Closes connection to DB when set of operations to be performed are done
bool save(Rental r) {
	std::string sql = "INSERT INTO rental(rental_id, cust_id, car_id, dateOfRent, dateOfReturn, cost, isPaid) VALUES (" + std::to_string(r.rentalID) + ", " + std::to_string(r.cust.getCustID()) + ", " + std::to_string(r.car.getCarID()) + ", \"" + r.rentDate.returnSQLDate() + "\", NULL, " + std::to_string(r.costPaid) + ", false);";
	sqlite3 *DB;
	int conn = 0;
	conn = sqlite3_open("database.db", &DB);
	char *errMsg;
	conn = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
	if (conn != SQLITE_OK) {
		std::cerr << "Error Inserting Record" << std::endl;
		std::cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
	} else {
		sql = "UPDATE cars SET isRented = true WHERE car_id = " + std::to_string(r.car.getCarID()) + ";";
		conn = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
		if (conn != SQLITE_OK) {
			std::cerr << "Error Inserting Record" << std::endl;
			std::cerr << errMsg << std::endl;
			sqlite3_free(errMsg);
			return false;
		} else {
			std::cout << "Record Save Successful" << std::endl;
		}
	}
	rental_id = getCurrentRentalID();
	sqlite3_close(DB);
	return true;
}
//this function will return all the information like rentalid, rent date, return date etc.
Rental getRental(int r_id) {
	sqlite3 *DB;
	int conn = 0;
	//establishing database connection
	conn = sqlite3_open("database.db", &DB);
	sqlite3_stmt *statement;
	std::string sql = "SELECT * FROM rental WHERE rental_id = " + std::to_string(r_id) + ";"; //fetching set of values from rental table depending upon condition used 
	sqlite3_prepare(DB, sql.c_str(), -1, &statement, 0);

	Rental r; 

	while(sqlite3_step(statement) != SQLITE_DONE) {  //Entry Controlled loop used here i.e., While loop
		r.rentalID = sqlite3_column_int(statement, 0);
		r.cust = getCustomer(sqlite3_column_int(statement, 1));
		r.car = getCar(sqlite3_column_int(statement, 2));
		r.rentDate = strToDate((char *) sqlite3_column_text(statement, 3));
		r.returnDate = strToDate((char *) sqlite3_column_text(statement, 4));
		r.costPaid = sqlite3_column_double(statement, 5);
		r.isPaid = sqlite3_column_int(statement, 6);
	} 

	sqlite3_close(DB);  //closes connection to DB when set of operations to be performed are done
	return r; 
}


Rental newRental() {
	int cust_id, car_id;  //declared two variables 'cust_id' & car_id of type int
	std::cout << "\t\t\t\tRental ID: " << rental_id << std::endl;  //fetch rental_id from user as input
	std::cout << "\t\t\t\tEnter Customer ID: ";
	std::cin >> cust_id;  //fetch cust_id from user as input 
	std::cin.ignore(); //Ignore() function used here if user provides no input
	Customer cst = getCustomer(cust_id);
	std::cout << "\t\t\t\tEnter Car ID: ";
	std::cin >> car_id; //fetch car_id from user as input
	std::cin.ignore();
	Car cr = getCar(car_id);
	std::cout << "\t\t\t\tRent Date: " << todayDate << std::endl; //fetch rent_date from user & displays it
	Rental r(todayDate, cst, cr);

	return r;
}
