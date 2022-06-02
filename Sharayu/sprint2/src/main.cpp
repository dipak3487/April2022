//Student Management system
#include <iostream>
#include <fstream>
#include <regex>
#include <typeinfo>
#include "json/json.h"
#include "CppConsoleTable.hpp"
#include "student.h"

int main () {
	cout << "*** WELCOME ***";
	string yesOrNo;
	
	while(true) {
		cout << endl << "--- Student Report Management System ---" << endl;
		home();
		cout << endl << "Continue? (y/n) :";
		cin >> yesOrNo;
		if(yesOrNo != "y") break;
	}

	cout << "Good Bye!" << endl;
}
