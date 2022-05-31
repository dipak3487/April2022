/*FILENAME	:	customer.h
 *
 * DESCRIPTION	:	This file contains all the declarations of functions that is used in customer.cpp
 *
 *
 */ 


#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "../include/date.h"

int getCurrentCustomerID();
static int customer_id = getCurrentCustomerID();

class Customer {
    private:
        int customerID;
    protected:
        std::string name, phoneNumber, eMail, resAddress, idProofNo;
        Date dor;
    public:
        Customer();
        Customer(std::string, std::string, std::string, std::string, std::string);
        Customer(const Customer &c2);
        friend bool save(Customer);
        friend Customer getCustomer(int);
        friend void displayAllCustomers();
		//int save(std::string name1,std::string phone_no,std::string email,std::string res_addr,std::string id_proof);
		//int modify(std::string name1,std::string phone_no,std::string email,std::string res_addr,std::string id_proof);
		//int getCustomer(int cust_id);

        static int getNoCustomers();
        static void customerRegisterd();
        static void customerDeleted();
        int getCustID();
        friend std::ostream& operator<< (std::ostream& os, const Customer& cust);
        ~Customer();

};

Customer registerCustomer();
bool save(Customer);
Customer getCustomer(int);
void displayAllCustomers();
bool modify(int, std::string, std::string, std::string, std::string);

#endif
