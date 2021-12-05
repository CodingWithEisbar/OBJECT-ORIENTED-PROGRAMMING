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
		message = "Invalid input value!";
	}
	auto result = make_tuple(succeeded, error_code_value, message, convert_date);
	return result;
}