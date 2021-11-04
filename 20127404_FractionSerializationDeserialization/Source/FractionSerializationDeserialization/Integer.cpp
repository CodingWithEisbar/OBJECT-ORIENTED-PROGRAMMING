#include "Integer.h"

long long Integer::gcd(int a, int b)
{
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
} 

//Integer - To - String function definition
bool IntegerToStringUIConverter::isValidInteger(string value)
{
	const string patterns = "\\b\\d+\\b";
	regex digitsPattern(patterns);

	bool result = regex_match(value, digitsPattern);
	return result;

};

string IntegerToStringUIConverter::convert(int number) {
	stringstream builder;
	builder << number;
	string result = builder.str();
	return result;
};

bool IntegerToStringUIConverter::tryConvertBack(string buffer, int& number) {
	bool result = true;
	bool isValid = isValidInteger(buffer);

	if (isValid) {
		number = stoi(buffer);
	}
	else {
		result = false;
	}

	return result;
};

tuple<bool, int, string, int> IntegerToStringUIConverter::convertBack(string buffer) {
	bool succeeded = true;
	int error_code = 0;
	string message = "";
	int data = 0;

	bool isValid = isValidInteger(buffer);

	int number = 0;
	if (isValid) {
		succeeded = true;
		data = stoi(buffer);
	}
	else {
		succeeded = false;
		error_code = 1;
		message = "Invalid number format exception";
	}

	auto result = make_tuple(succeeded, error_code, message, data);
	return result;
};