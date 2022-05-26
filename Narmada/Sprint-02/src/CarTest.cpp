#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include "Vehicle.h"
#include "Car.h"

extern

int main() {

    // Variables
    string type;

    // Creating a new 'Test' Vehicle
    Car *test = new Car;

    cout << " " << endl;

    cout << "This is a program to test the Car.h file." << endl;
    cout << "This file uses get and set functions and incorporates functions from the Vehicle.h file, which will be demonstrated by your input." << endl;

    cout << " " << endl;

    cout << "For testing purposes, the system has prepared a default car to test the display_details function which will be displayed below." << endl;

    cout << " " << endl;

    // Set default car values
    int selected_car = 1;
    test->set_maker("Holden");
    test->set_model("Commodore");
    test->set_color("White");
    test->set_status(true);

    // Calling the function display_details
    test[selected_car-1].display_details(selected_car-1, test);

    cout << " " << endl;

    cout << "Now please input the following and the system will then output your input." << endl;

    // Prompt input to user
    cout << "A car type: ";
    getline(cin, type);

    // Setting user input to variable 'type' using function from Car.h file
    test->set_car_type(type);

    // Outputting user input using function from Car.h file
    cout << "Your input was: ";
    cout << test->get_car_type() << endl;

    cout << " " << endl;

    return 0;

};
