#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

#include"Vehicle.h"

int main() {

    // Variables
    string model;
    string company;
    string colour;
    bool stat;

    // Creating a new 'Test' Vehicle
    Vehicle *Test = new Vehicle;

    cout << " " << endl;

    cout << "This is a program to test the Vehicle.h file." << endl;
    cout << "This function purely uses get and set functions, which will be demonstrated by your input." << endl;
    cout << "The first three inputs are supposed string inputs, please input the following: " << endl;

    cout << " " << endl;

    // Prompt input to user
    cout << "A car model: ";
    getline(cin, model);

    // Setting user input to variable 'model' using function from Vehicle.h file
    Test->set_model(model);

    // Outputting user input using function from Vehicle.h file
    cout << "Your input was: ";
    cout << Test->get_model() << endl;


    cout << " " << endl;


    // Prompt input to user
    cout << "A car company: ";
    getline(cin, company);

    // Setting user input to variable 'company' using function from Vehicle.h file
    Test->set_maker(company);

    // Outputting user input using function from Vehicle.h file
    cout << "Your input was: ";
    cout << Test->get_maker() << endl;


    cout << " " << endl;


    // Prompt input to user
    cout << "A car color: ";
    getline(cin, colour);

    // Setting user input to variable 'colour' using function from Vehicle.h file
    Test->set_color(colour);

    // Outputting user input using function from Vehicle.h file
    cout << "Your input was: ";
    cout << Test->get_color() << endl;


    cout << " " << endl;


    cout << "Now we will be testing the status function which is a boolean type." << endl;
    cout << "If user inputs true, the machine will output 1 and if the user inputs" << endl;
    cout << "false or anything else, the machine will output 0." << endl;

    cout << " " << endl;

    // Prompt user for input
    cout << "Please input either true or false: ";
    cin >> boolalpha;
    cin >> stat;

    // Setting user input to variable 'stat' using function from Vehicle.h file
    Test->set_status(stat);

    // Outputting user input using function from Vehicle.h file
    cout << "Your input was: ";
    cout << Test->get_status() << endl;


}
