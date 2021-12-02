#include "Student.h"

Student::Student(string ID, string fullName, double GPA, string phoneNumber,
	string emailAddress, string DOB, string homeAddress)
{
	_ID = ID;
	_fullName = fullName;
	_GPA = GPA;
	_phoneNumber = phoneNumber;
	_emailAddress = emailAddress;
	_DOB = DOB;
	_homeAddress = homeAddress;
}