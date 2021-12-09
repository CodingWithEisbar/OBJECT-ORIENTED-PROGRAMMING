#include "stringToShapeValueConverter.h"
 
stringToShapeValueConverter::stringToShapeValueConverter()
{
	//Default constructor
}

stringToShapeValueConverter::stringToShapeValueConverter(string shapeValue)
{
	this->_shapeValue = shapeValue;
}

bool stringToShapeValueConverter::isValidShapeValue(string sample)
{
	string pattern = "[-+]?([-+]?\\d+)([0-9]*[.])?[0-9]+([eE][-+]?\\d+)?";
	regex shapePattern(pattern);
	bool result = regex_match(sample, shapePattern);
	return result;
}

string stringToShapeValueConverter::convertBack(double value)
{
	stringstream ss;
	ss << value;
	string result = ss.str();
	return result;
}

tuple <bool, int, string, double> stringToShapeValueConverter::convert(string sample)
{
	bool succeeded = true;
	int errorCode = 0;
	string message = "";
	double value;
	bool check = isValidShapeValue(sample);
	if (check) {
		value = stod(sample);
	}
	else {
		succeeded = false;
		errorCode = 1;
		message = "Invalid number format exception";

	}
	auto result = make_tuple(succeeded, errorCode, message, value);
	return result;
}