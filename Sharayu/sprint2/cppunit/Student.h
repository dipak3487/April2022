#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<string>

using namespace std;

//using class
class Student {
	string name, cls; 
	int rollNumber;
	int eng, science , history , math ,social;
	int total;
	string grade;

public:
	string getName();
	void setName(string n);
	
	string getClass();
	void setClass(string c);

	int getRollNumber();
	void setRollNumber(int r);

	void setMarks(int english, int sc, int h, int m, int sst);

	int calculateTotal();

	string figureGrade();

	void showReport();
};


#endif
