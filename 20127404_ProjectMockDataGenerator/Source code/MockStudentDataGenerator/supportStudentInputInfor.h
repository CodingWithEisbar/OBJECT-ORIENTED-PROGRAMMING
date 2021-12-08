#ifndef _STUDENTINPUTINFORMATION_H_
#define _STUDENTINPUTINFORMATION_H_

#include <iostream>
#include <sstream>
#include <regex>
#include <tuple>

#include "Student.h"
using namespace std;

//Stuff
int maxDayDeterminator(DATE date);
STUDENT inputStudent();


class InputStudentInformation {
public:
	bool isValidStudentID(string);
	bool isValidStudentPhoneNumber(string);
	bool isValidStudentEmail(string);
	bool isValidStudentGPA(string);
	bool isValidDOBFormat(string);
	bool isValidDateString(string);
public:
	//input student DOB support
	string DOBToString(DATE DOB);
	tuple<bool, int, string, DATE> stringToDOBConvertBack(string);
	string phoneNumberCorrectedFormat(string);
};



#endif