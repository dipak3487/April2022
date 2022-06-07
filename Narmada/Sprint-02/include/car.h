/* FILENAME	:	car.h
 *
 * DESCRIPTION	:	This file contains all the functions declarations of car.cpp
 *
 *
 * CHANGES MADE BY TEAM NARMADA
 *
 *
 */
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "date.h"

int getCurrentCarID();

static int car_id = getCurrentCarID();

class Car {
    private:
        int carID;
    protected:
        std::string  regNo, company, model;
        bool isRented;
        Date doa;
        double costPerDay;
    public:
        Car();
        Car(const Car &car2);
        Car(std::string, std::string, std::string, double);
        int returnSQLData();
        static int getNoOfCars();
        static void deleteCar();
        static void carAdded();
        int getCarID();
        double getCost();
        friend bool save(Car c);
		//int save(std:: string reg_no,std::string company1,std::string model1,std::string cost_per_day);
		//int displayAllCars(int option1);
		//int getCar(int car_id);
        friend Car getCar(int);
        friend void displayAllCars();
		//int modify(int car_id,double cost_per_day);
        friend std::ostream& operator<< (std::ostream& os, const Car& car);
        ~Car();
};

Car getCarDetails();
Car getCar(int);
void displayAllCars();

bool modify(int, double);

#endif
