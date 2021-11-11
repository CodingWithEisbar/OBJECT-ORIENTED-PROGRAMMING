#include "IntegerToThousandSeparatedUIConverter.h"

bool IntegerToThousandSeparatedUIConverter::isValidFormat(string value)
{
	bool result = true;
	string pattern = "\\b[0-9]{1,3}(\\.[0-9]{3})*";
	regex thousandSeperatedPattern(pattern);
	result = regex_match(value, thousandSeperatedPattern);
	return result;
}

string IntegerToThousandSeparatedUIConverter::convert(const int& value) 
{
	stringstream ss;
	ss << value;
	string result = ss.str();
	int resultLength = result.length();
	if (resultLength <= 3) {
		return result;
	}
	int index = resultLength - 3;
	while (index > 0) {
		result.insert(index, _thousandSeparator);
		index -= 3;
	}
	return result;
}

tuple<bool, int, string, int> IntegerToThousandSeparatedUIConverter::convertBack(string my_string)
{
	bool succeeded = true;
	int error_code = 0;
	string error_message = "";
	int result = 0;

	bool isValid = isValidFormat(my_string);
	if (isValid) {
		//Xóa các dấu phân cách
		my_string.erase(remove(my_string.begin(), my_string.end(), _thousandSeparator[0]), my_string.end());
		//Chuyển đổi lại dạng int
		stringstream ss;
		ss << my_string;
		ss >> result;
	}
	else {
		succeeded = false;
		error_code = 2;
		error_message = "Invalid input format";
	}

	auto convert_result = make_tuple(succeeded, error_code, error_message, result);
	return convert_result;
}


