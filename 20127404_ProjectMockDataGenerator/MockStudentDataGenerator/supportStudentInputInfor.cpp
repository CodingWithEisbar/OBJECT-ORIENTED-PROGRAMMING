#include "supportStudentInputInfor.h"


//Stuff
int maxDayDeterminator(DATE date)
{
	int maxDay = 31;

	if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		maxDay = 30;
	}
	if (date.month == 2)
	{
		if (date.year % 400 == 0 && date.year % 100 == 0 || date.year % 4 == 0 && date.year % 100 != 0)
		{
			maxDay = 29;
		}
		else
		{
			maxDay = 28;
		}
	}
	return maxDay;
}



bool InputStudentInformation::isValidDOBFormat(string value)
{
	string DOB_pattern = "\\b\\d+\\/\\d+\\/\\d+\\b";
	regex datePattern(DOB_pattern);
	bool checkDOB = regex_match(value, datePattern);
	return checkDOB;
}


bool InputStudentInformation::isValidDateString(string value)
{
	bool checkFormat = isValidDOBFormat(value);
	if (checkFormat)
	{
		stringstream ss;
		string day_str, month_str, year_str;
		getline(ss, day_str, '/');
		getline(ss, month_str, '/');
		getline(ss, year_str);
		DATE date_int;
		date_int.day = stoi(day_str);
		date_int.month = stoi(month_str);
		date_int.year = stoi(year_str);
		if (date_int.year > 1900)
		{
			if (date_int.month <= 12)
			{
				int maxDay = maxDayDeterminator(date_int);
				if (date_int.day >= 1 && date_int.day <= maxDay) return true;
			}
			else {
				return false;
			}
		}
		else return false;
	}
}

bool InputStudentInformation::isValidStudentID(string ID)
{
	string ID_pattern = "\\b[0-9]\\d+\\b";
	regex datePattern(ID_pattern);
	bool checkDOB = regex_match(ID, datePattern);
	return checkDOB;
}

bool InputStudentInformation::isValidStudentGPA(string GPA)
{
	string GPA_pattern = "[-+]?([0-9]*[.])?[0-9]+([eE][-+]?\\d+)?";
	regex studentGPAPattern(GPA_pattern);
	bool result = regex_match(GPA, studentGPAPattern);
	return result;
}

bool InputStudentInformation::isValidStudentEmail(string email)
{
	string email_pattern = "\\b\\w+@student.hcmus.edu.vn\\b";
	regex studentEmailPattern(email_pattern);
	bool result = regex_match(email, studentEmailPattern);
	return result;
}

bool InputStudentInformation::isValidStudentPhoneNumber(string phoneNumber)
{
	string phone_pattern = "0\\d{3}(\\d{3}){2}";
	regex studentPhoneNumber(phone_pattern);
	bool result = regex_match(phoneNumber, studentPhoneNumber);
	return result;
}


string InputStudentInformation::DOBToString(DATE sample)
{
	stringstream builder;
	builder << sample.day << "/" << sample.month << "/" << sample.year;
	string result = builder.str();
	return result;
}

tuple<bool, int, string, DATE> InputStudentInformation::stringToDOBCovertBack(string buffer)
{
	bool succeeded = true;
	int error_code_value = 0;
	string message = "";
	DATE convert_date;
	bool check = isValidDateString(buffer);
	if (check)
	{
		stringstream ss;
		string day_str, month_str, year_str;
		getline(ss, day_str, '/');
		getline(ss, month_str, '/');
		getline(ss, year_str);
		convert_date.day = stoi(day_str);
		convert_date.month = stoi(month_str);
		convert_date.year = stoi(year_str);
	}
	else {
		succeeded = false;
		error_code_value = 1;
		message = "Invalid number format exception";
	}
	auto result = make_tuple(succeeded, error_code_value, message, convert_date);
	return result;
}

tuple<bool, int, string, double> InputStudentInformation::stringToGPA(string buffer)
{
	bool succeeded = true;
	int error_code_value = 0;
	string message = "";
	double GPA = 0;
	bool checkGPA = isValidStudentGPA(buffer);
	if (checkGPA)
	{
		GPA = stod(buffer);
	}
	else
	{
		succeeded = false;
		error_code_value = 1;
		message = "Invalid number format exception";
	}
	auto result = make_tuple(succeeded, error_code_value, message, GPA);
	return result;
}