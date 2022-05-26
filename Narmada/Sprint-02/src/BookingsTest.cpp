#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include"Bookings.h"

int main() {

    // Variables
    int info_booking;
    Bookings list[1];
    string lan;
    string firstname;
    string lastname;
    int date;
    int month;
    int end;
    int emonth;

    // Creating a test booking
    Bookings *Test = new Bookings;

    cout << " " << endl;

    cout << "This is a program to test the Booking.h file." << endl;
    cout << "This function purely uses get and set functions, which will be demonstrated by your input." << endl;
    cout << "The first three inputs are supposed string inputs, please input the following: " << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "Your first name : ";
    getline(cin, firstname);

    // Setting user input to variable 'firstname' using function from Bookings.h file
    Test->set_firstname(firstname);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_firstname() << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "Your last name : ";
    getline(cin, lastname);

    // Setting user input to variable 'lastname' using function from Bookings.h file
    Test->set_lastname(lastname);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_lastname() << endl;

    cout << "The next four inputs are supposed int inputs, please input the following: " << endl;
    
    cout << " " << endl;

    // Prompt input to user
    cout << "Your booking starting date : ";
    cin >> date;

    // Setting user input to variable 'date' using function from Bookings.h file
    Test->set_sdate(date);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_sdate() << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "Your booking starting month : ";
    cin >> month;

    // Setting user input to variable 'month' using function from Bookings.h file
    Test->set_smonth(month);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_smonth() << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "Your booking ending date : ";
    cin >> end;

    // Setting user input to variable 'edate' using function from Bookings.h file
    Test->set_edate(end);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_edate() << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "Your booking starting month : ";
    cin >> emonth;

    // Setting user input to variable 'emonth' using function from Bookings.h file
    Test->set_emonth(emonth);

    // Outputting user input using function from Bookings.h file
    cout << "Your input was: ";
    cout << Test->get_emonth() << endl;
}
