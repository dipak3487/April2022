#include <iostream>
#include <fstream>
#include <regex>
#include <typeinfo>
#include "json/json.h"
#include "CppConsoleTable.hpp"
using namespace std;

using tableFormat::ConsoleTable;

Json::Value getStudentReport() {
	Json::Value root;
	std::ifstream file("reports.json");
    file >> root;

	file.close();
	return root;
}


void setStudentReport(Json::Value root) {
	// Write the output to a file
	std::ofstream outFile;
	outFile.open("reports.json");
	outFile << root;
	outFile.close();    
}


string getName() {
	string str;
	cout << "Enter Student's Name: ";
	getline(cin, str);

	if(str == "") {
		cout << "Enter a name!" << endl;
		getName();
	}
	return str;
}

// the student report options
int reportOptions() {
	cout << "1. Add New Report"<< endl;
	cout << "2. Show Student Report"<< endl;
	cout << "3. Modify Report"<< endl;
	cout << "4. Remove Report"<< endl;
	cout << "5. Show All Reports"<< endl;
	cout << "0. Exit"<< endl;
	cout << "--- Choose any one option ---" << endl;
	cout << "Enter one option: ";

	int selectedOption = 0;
	cin >> selectedOption;
	cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 

	return selectedOption;
}
// this is to show student individual report

void checkReport() {
	string cls; int roll;

	cout << "--- Check Student Report ---" << endl;

	cout << "Student's Class: ";
	cin >> cls;
	cout << "Student's Roll No: ";
	cin >> roll;

	Json::Value list = getStudentReport();
	int len = list.size();

	for ( int i = 0; i < len; i++ )
    {
		string studentClass = list[i]["Student"]["class"].asString();
		int studentRollNum = list[i]["Student"]["roll_number"].asInt();

		if (cls == studentClass && roll == studentRollNum) {
			string studentName = list[i]["Student"]["name"].asString();
			int eng = list[i]["marks"]["english"].asInt();
			int math = list[i]["marks"]["math"].asInt();
			int science = list[i]["marks"]["science"].asInt();
			int social = list[i]["marks"]["social"].asInt();
			int history = list[i]["marks"]["history"].asInt();

			string grade = list[i]["grade"].asString();

			cout << "Student Name: " << studentName << endl;
			cout << "English: " << eng << endl;
			cout << "Math: " << math << endl;
			cout << "Science: " << science << endl;
			cout << "Social: " << social << endl;
			cout << "History: " << history << endl;
			cout << "Grade: " << grade << endl;
			return;
		}

    }

	cout << "Report Not Found." << endl;
}

int calculateTotal(int *arr, int size) {
	int sum = 0, i;
	for (i = 0; i < size; i++) {
    	sum += arr[i];
   	}

	return sum;
}

string figureGrade(int totalMarks, int size) {
	if (totalMarks / size >= 90) {
		return "A";
	} else if (totalMarks / size >= 70) {
		return "B";
	} else if (totalMarks / size >= 50) {
		return "C";
	} else {
		return "F";
	}
	return "null";
}
//using class
class Student {
	string name, cls; 
	int rollNumber;
	int eng, science , history , math ,social;
	string grade;

};


void addReport() {
	string name,cls;
	string grade;
	int rollNumber;
	int id, total;
	int eng, science, history, math, social = 0;

	Json::Value records = getStudentReport();

	// generate random number
	std::srand(static_cast<unsigned int>(std::time(nullptr))); 
	id = std::rand();

	cout << endl << "--- Provide Student Report Details ---" << endl;
	name = getName();
	cout << "Roll No: ";
	cin >> rollNumber;
	cout << "Student Class: ";
	cin >> cls;
	cout << "----- Student's Marks -----" << endl;
	cout << "English: ";
	cin >> eng;
	cout << "Math: ";
	cin >> math;
	cout << "Science: ";
	cin >> science;
	cout << "Social Studies: ";
	cin >> social;
	cout << "History: ";
	cin >> history;
	
	int marks[5] = { eng, math, history, science, social };
	total = calculateTotal(marks, 5);
	grade = figureGrade(total, 5);

	Json::Value record;
	record["id"] = id;
	record["Student"]["name"] = name;
	record["Student"]["roll_number"] = rollNumber;	
	record["Student"]["class"] = cls;	

	record["marks"]["english"] = eng;
	record["marks"]["math"] = math;
	record["marks"]["science"] = science;
	record["marks"]["history"] = history;
	record["marks"]["social"] = social;

	record["total_marks"] = total;
	record["grade"] = grade;

	records.append(record);
	setStudentReport(records);
	
   	cout << name << " Report added. " << endl;
   	cout << "Grade: " << grade << endl; 
}


void updateReport() {
	string cls; int roll;
	cout << endl << "--- Update Student Report ---" << endl;

	cout << "Student's Class: ";
	cin >> cls;
	cout << "Student's Roll No: ";
	cin >> roll;

	Json::Value records = getStudentReport();
	int len = records.size();
	bool found = false;

    for ( int i = 0; i < len; i++ )
    {
		string studentClass = records[i]["Student"]["class"].asString();
		int studentRollNum = records[i]["Student"]["roll_number"].asInt();

		if (cls == studentClass && roll == studentRollNum) {
			string name, s_class, grade;
			int rollNumber, eng, math, science, social, history, total;

			cin.ignore(); 
			name = getName();

			cout << "Roll No: ";
			cin >> rollNumber;
			cout << "Student Class: ";
			cin >> s_class;
			cout << "----- Student's Marks -----" << endl;
			cout << "English: ";
			cin >> eng;
			cout << "Math: ";
			cin >> math;
			cout << "Science: ";
			cin >> science;
			cout << "Social Studies: ";
			cin >> social;
			cout << "History: ";
			cin >> history;
			
			int marks[5] = { eng, math, history, science, social };
			total = calculateTotal(marks, 5);
			grade = figureGrade(total, 5);

			records[i]["Student"]["name"] = name;
			records[i]["Student"]["roll_number"] = rollNumber;	
			records[i]["Student"]["class"] = s_class;	

			records[i]["marks"]["english"] = eng;
			records[i]["marks"]["math"] = math;
			records[i]["marks"]["science"] = science;
			records[i]["marks"]["history"] = history;
			records[i]["marks"]["social"] = social;

			records[i]["total_marks"] = total;
			records[i]["grade"] = grade;

			found = true;
			break;
		}
    }

	if (!found) {
		cout << "Report Not Found." << endl;
	} else { 
		setStudentReport(records);
		cout << "Report Updated" << endl;
	}

}


void removeReport() {
	string cls;
	int roll;
	cout << endl << "--- Remove Student Report ---" << endl;
	
	cout << "Student's Class: ";
	cin >> cls;
	cout << "Student's Roll No: ";
	cin >> roll;
	

	Json::Value records = getStudentReport();
	int len = records.size();

	Json::Value newRecords;
	bool studentReportExists = false;

    for ( int i = 0; i < len; i++ )
    {
		string studentClass = records[i]["Student"]["class"].asString();
		int studentRollNum = records[i]["Student"]["roll_number"].asInt();

		if (cls == studentClass && roll == studentRollNum) {
			studentReportExists = true;
			continue;
		}
		newRecords.append(records[i]);
    }

	if(studentReportExists) {
		setStudentReport(newRecords);
		cout << "Student Report Removed";
	} else {
		cout << "Student Report does not exist";
	}
}


void showReports() {
	cout << "--- List of Student Reports ---" << endl;

	Json::Value list = getStudentReport();
	int len = list.size();


	ConsoleTable table(1, 1, tableFormat::Alignment::centre);

	// creating class
	ConsoleTable::TableChars chars;
		// modifying characters
	chars.topLeft = '*';
	chars.topRight = '*';
	chars.downLeft = '*';
	chars.downRight = '*';

	chars.topDownSimple = '-';
	chars.leftRightSimple = '+';

	chars.leftSeparation = '*';
	chars.rightSeparation = '*';
	chars.topSeparation = '*';
	chars.downSeparation = '*';
	chars.centreSeparation = '*';

	// changing characters in table
	table.setTableChars(chars);


	table[0][0] = "Student Name";
	table[0][1] = "Class";
	table[0][2] = "Roll No.";
	table[0][3] = "Grade";
	table[0][4] = "Total Marks";

	for ( int i = 0; i < len; i++ )
    {
		string name = list[i]["Student"]["name"].asString();
		int rollNum = list[i]["Student"]["roll_number"].asInt();
		string sClass = list[i]["Student"]["class"].asString();
		string grade = list[i]["grade"].asString();
		string total = list[i]["total_marks"].asString();

		int j = i + 1;
		table[j][0] = name;
		table[j][1] = sClass;
		table[j][2] = rollNum;
		table[j][3] = grade;
		table[j][4] = total;
    }

	cout << table;
}


void actions(int& option) {
	switch(option) {
		case 1: 
			addReport();
			break;
		case 2: 
			checkReport();
			break;
		case 3: 
			updateReport();
			break;
		case 4: 
			removeReport();
			break;
		case 5: 
			showReports();
			break;
	}
}


void home () {
	int option = reportOptions();
	if (option != 0 && option <= 5) {
		actions(option);
	} else if (option > 5) {
		cout << endl << "!!! Enter Valid Option !!!" << endl;
		option = reportOptions();
	} else {
	 	exit(0);
	}
}
