#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include "Vehicle.h"
#include "Truck.h"

int main() {

    // Variables
    int size;

    // Creating a new 'Test' Vehicle
    Truck *test = new Truck;

    cout << " " << endl;

    cout << "This is a program to test the Truck.h file." << endl;
    cout << "This function uses get and set functions and incoporates functions from the Vehicle.h file, which will be demonstrated by your input." << endl;

    cout << " " << endl;

    cout << "Please input the following and the system will then output your input." << endl;

    // Prompt input to user
    cout << "A truck size (a number): ";
    cin >> size;

    // Setting user input to variable 'type' using function from Truck.h file
    test->set_size(size);

    // Outputting user input using function from Truck.h file
    cout << "Your input was: ";
    cout << test->get_size() << endl;

    cout << " " << endl;

    cout << "For testing purposes, the system has prepared a default truck to test the display_details function which will be displayed below." << endl;

    cout << " " << endl;

    // Set default truck values
    int selected_size = 1;
    test->set_status(true);

    // Calling the function display_details
    test[selected_size-1].display_details(selected_size-1,test);

    cout << " " << endl;

    return 0;


}