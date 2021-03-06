/*FILENAME	:	car.cpp
 *
 *DESCRIPTION	:	This main.cpp file display all the details about a aprticular car using car ID.
 			It also allows users to add new car, enables user to change the car cost per day.
 *
 *
 *                      CHANGES MADE BY TEAM NARMADA
 *
 *
 *
 *
 *
 */


#include <iostream>
#include <sqlite3.h>
#include "car.h"
#include "date.h"

Car::Car() {  
	carID = -1;
	regNo = "N/A";
	company = "N/A";
	model = "N/A";
	isRented = false;
	doa = todayDate;
	costPerDay = 0;
}

int Car::returnSQLData() {
	return carID;
}

Car::Car(const Car &car2) {
	carID = car2.carID;
	regNo = car2.regNo;
	company = car2.company;
	model = car2.model;
	isRented = car2.isRented;
	doa = car2.doa;
	costPerDay = car2.costPerDay;
}

Car::Car(std::string _regNo, std::string _company, std::string _model, double _costPerDay) {
	carID = car_id;
	regNo = _regNo;
	company = _company;
	model = _model;
	isRented = false;
	doa = todayDate;
	costPerDay = _costPerDay;
}

int Car::getNoOfCars() {
	return car_id;
}

double Car::getCost() {
	return costPerDay;
}

std::ostream& operator<< (std::ostream& os, const Car& car) {
	os << "\t\t\t\tCar ID: " << car.carID << std::endl;
	os << "\n\t\tRegistration No: " << car.regNo << std::endl;
	os << "\n\t\tCompany and Model: " << car.company << " " << car.model << std::endl;
	os << "\n\t\tIs Rented: " << car.isRented << std::endl;
	os << "\n\t\tCost Per Day: " << car.costPerDay << std::endl;
	os << "\n\t\tDate of Addition: " << car.doa;

	return os;
}

void Car::carAdded() {
	car_id = getCurrentCarID();
}

//sqlite2 query to store/add cars in database
/*FUNCTION NAME : void save()
 *
 * DESCRIPTION  : This function is used to insert values in cars table when user add
 * 		  any new car.Whene you add a new car it will ask you for registration number, company name, model name, cost per day.
 * 		  And also it will generate car ID. And after that it will save these details in the database.
 * 		  We have you used sqlite3_open to connect the database.
 * 		  After successfully save the details in database we use sqlite3_close to close the database.
 * 		  
 */

bool save(Car c) {
	sqlite3 *DB;
	std::string sql = "INSERT INTO cars VALUES (" + std::to_string(c.carID) +  ", \"" +  c.regNo + "\", \"" + c.company + "\", \"" + c.model + "\", " + std::to_string(c.isRented) + ", \"" + c.doa.returnSQLDate() + "\", " + std::to_string(c.costPerDay) + ");";
	int connection = 0;
	//we have used sqlite3 for making connection with database
	connection = sqlite3_open("database.db", &DB);
	char *errMsg;
	connection = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);
	if (connection != SQLITE_OK) {
		std::cerr << "Error Inserting Record" << std::endl;
		std::cerr << errMsg << std::endl;
		sqlite3_free(errMsg);
		return false;
	} else {
		std::cout << "Record Save Successful" << std::endl;
	}
	c.carAdded();
	sqlite3_close(DB);
	return true;
}

Car getCar(int c_id) {
	sqlite3 *DB;
	int connection = 0;
	connection = sqlite3_open("database.db", &DB);
	char *errMsg;
	//it will ask for car ID to display the car details like registration number, company name, model, cost per day, and it's rental date.
	//sqlite3 query to see the car data details so we use sqlite3_open to connect the database.
	sqlite3_stmt* statement;
	std::string sql = "SELECT * FROM cars";
	if (c_id != 0) {
		sql += " WHERE car_id = " + std::to_string(c_id) + ";";
	}
	sqlite3_prepare(DB, sql.c_str(), -1, &statement, 0);
	Car c;

	while (sqlite3_step(statement) != SQLITE_DONE) {
		c.carID = sqlite3_column_int(statement, 0);
		c.regNo = (char *) sqlite3_column_text(statement, 1);
		c.company = (char *) sqlite3_column_text(statement, 2);
		c.model = (char *) sqlite3_column_text(statement, 3);
		c.isRented = sqlite3_column_int(statement, 4);
		c.doa = strToDate((char *) sqlite3_column_text(statement, 5));
		c.costPerDay = sqlite3_column_double(statement, 6);
	}

	sqlite3_close(DB);

	return c;
}
/*FUNCTION NAME  :  displayAllCars()
 *
 * DESCRIPTION  :	This function displays all details of all car present in database like car ID, registration number
 * 			company name, model number, cost per day and aslo it will show is rented or not.
 *			 We have you used sqlite3_open to connect the database.
 *			 After successfully save the details in database we use sqlite3_close to close the database.
 * 		   
 *
 */

void displayAllCars() {
	sqlite3 *DB;
	int connection = 0;
	connection = sqlite3_open("database.db", &DB);
	char *errMsg;
	sqlite3_stmt* statement;
	std::string sql = "SELECT * FROM cars;";
	sqlite3_prepare(DB, sql.c_str(), -1, &statement, 0);
	Car c;

	while (sqlite3_step(statement) != SQLITE_DONE) {
		c.carID = sqlite3_column_int(statement, 0);
		c.regNo = std::string((char *) sqlite3_column_text(statement, 1));
		c.company = std::string((char *) sqlite3_column_text(statement, 2));
		c.model = std::string((char *) sqlite3_column_text(statement, 3));
		c.isRented = sqlite3_column_int(statement, 4);
		c.doa = strToDate((char *) sqlite3_column_text(statement, 5));
		c.costPerDay = sqlite3_column_double(statement, 6);

		std::cout << c << '\n' << std::endl;
	}

	sqlite3_close(DB);
}
/*Function name : getCurrentCarID()
 *
 * Description  :	In this function it will ask you to enter the car ID and it will shows the details 
 * 			of that particuler car like car ID, registration number
 * 			company name, model number, cost per day and aslo it will show is rented or not.
 * 			We have you used sqlite3_open to connect the database.
 * 			After successfully save the details in database we use sqlite3_close to close the database.
 *
 */
int getCurrentCarID() {
	sqlite3 *DB;
	int connection = 0;
	connection = sqlite3_open("database.db", &DB);
	sqlite3_stmt* statement;
	std::string sql = "SELECT car_id FROM cars;";
	int id = 0;
	sqlite3_prepare(DB, sql.c_str(), -1, &statement, 0); // 
	while(sqlite3_step(statement) != SQLITE_DONE) {
		id = sqlite3_column_int(statement, 0);
	}

	sqlite3_close(DB);
	return id + 1;
}

int Car::getCarID() {   //getcarID() returns the car ID
	return carID;
}

void Car::deleteCar() {
	car_id = getCurrentCarID();
}

Car::~Car() {

}

Car getCarDetails() {
	std::string rNo, comp, mod;
	double cost;
	std::cout << "\t\t\t\tCar ID: " << Car::getNoOfCars() << std::endl;
	std::cout << "\n\t\t\tEnter Registration Number: ";
	std::getline(std::cin, rNo);
	std::cout << "\n\t\t\tEnter Company: ";
	std::getline(std::cin, comp);
	std::cout << "\n\t\t\tEnter Model: ";
	std::getline(std::cin, mod);
	std::cout << "\n\t\t\tEnter Rent Cost per Day: ";
	std::cin >> cost;
	std::cin.ignore();
	Car c(rNo, comp, mod, cost);
	return c;
}
/*Function Name  :  modify()
 *
 * Description :	In this function first it will ask car ID and then 
 * 			it will ask you to enter new cost per day.
 * 			To update this record in the cars table first you nedd to connect with database using sqlite3_open.
 * 			Now you just run the query and update record according the car ID selected.
 * 			If updation is successfull it will display the record save successfully.
 * 			And if the updation is not successfull it will display the error in record.
 *
 */

bool modify(int car_id, double newCost) {
	std::string sql = "UPDATE cars SET cost_per_day = " + std::to_string(newCost) + " WHERE car_id = " + std::to_string(car_id) + ";";
	sqlite3 *Database;
	int connection = 0;
	connection = sqlite3_open("database.db", &Database);
	char *errMsg;
	connection = sqlite3_exec(Database, sql.c_str(), NULL, 0, &errMsg);
	if (connection != SQLITE_OK) {
		std::cerr << "\t\t\t\tError Updating Record" << std::endl;
		std::cerr << "\t\t\t\t" << errMsg << std::endl;
		sqlite3_free(errMsg);
		return false;
	} else {
		std::cout << "\t\t\t\tUpdation Successful" << std::endl;
	}
	sqlite3_close(Database);
	return true;
}
