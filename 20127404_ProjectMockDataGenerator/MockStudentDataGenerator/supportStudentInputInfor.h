#ifndef _STUDENTINPUTINFORMATION_H_
#define _STUDENTINPUTINFORMATION_H_

#include <sstream>
#include <regex>
#include <tuple>

#include "Student.h"
using namespace std;

//Stuff
int maxDayDeterminator(DATE date);


class InputStudentInformation {
public:
	bool isValidStudentID(string);
	bool isValidStudentPhoneNumber(string);
	bool isValidStudentEmail(string);
	bool isValidDOBFormat(string);
	bool isValidDateString(string);
public:
	//input student DOB support
	string DOBToString(DATE DOB);
	tuple<bool, int, string, DATE> stringToDOBCovertBack(string);

	//input DOB support
	tuple<bool, int, string, float> stringToFloat(string);

};




#endif