#include "Student.h"

STUDENT::STUDENT() 
{
	//Default constructor
}

STUDENT::STUDENT(string ID, string fullName, double GPA, string phoneNumber,
	string emailAddress, DATE DOB, string homeAddress)
{
	this->_ID = ID;
	this->_fullName = fullName;
	this->_GPA = GPA;
	this->_phoneNumber = phoneNumber;
	this->_emailAddress = emailAddress;
	this->_DOB = DOB;
	this->_homeAddress = homeAddress;
}

void STUDENT::setStudentDOB(DATE DOB)
{
	this->_DOB.day = DOB.day;
	this->_DOB.month = DOB.month;
	this->_DOB.year = DOB.year;
}

double getStudentsAverageGPA(vector<STUDENT> data)
{
	double sum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		sum = sum + data[i].getStudentGPA();
	}
	double result = sum / (1.0 * data.size());
	return result;
}
