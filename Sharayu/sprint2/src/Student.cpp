#include "Student.h"

string Student::getName()
{
	return name;
}

void Student::setName(string n)
{
	name = n;
}

string Student::getClass()
{
	return cls;
}

void Student::setClass(string c)
{
	cls = c;
}

int Student::getRollNumber()
{
	return rollNumber;
}

void Student::setRollNumber(int r)
{
	rollNumber = r;
}

void Student::setMarks(int english, int sc, int h, int m, int sst)
{
	eng = english;
	science = sc;
	history = h;
	math = m;
	social = sst;
}

string Student::figureGrade()
{
	if(total == 0)
	{
		calculateTotal();
	}

	if (total / 5 >= 90) {
		grade= "A";
	} else if (total / 5 >= 70) {
		grade= "B";
	} else if (total / 5 >= 50) {
		grade= "C";
	} else {
		grade= "F";
	}

	return grade;
}

int Student::calculateTotal()
{
	total = eng + science + history + math + social;

	return total;
}

/*
void showReport()
{
	std::cout <<"Not implemented" << std::endl;

}

*/
