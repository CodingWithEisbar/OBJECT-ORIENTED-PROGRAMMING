#include "IntegerToCurrencyUIConverter.h"

bool IntegerToCurrencyUIConverter::isValidFormat(string my_string)
{
	bool check = true;
	string pattern = "\\b[0-9]{1,3}(\\.[0-9]{3})*";
	regex IntegerToString(pattern);
	bool result = regex_match(my_string, IntegerToString);
	return result;
}

string IntegerToCurrencyUIConverter::convert(const int& value)
{
	stringstream ss;
	ss << value;
	string result = ss.str();
	int stringLength = result.length();
	if (stringLength <= 3) return result;
	int index = stringLength - 3;
	while (index > 0) {
		result.insert(index, _thousandSeparator);
		index -= 3;
	}
	string IntegerToCurrency = result + _currency;
	return IntegerToCurrency;
}

tuple<bool, int, string, int> IntegerToCurrencyUIConverter::convertBack(string value)
{
	bool succeeded = true;
	int error_code = 0;
	string error_message = "";
	int result = 0;

	bool isValid = isValidFormat(value);
	if (isValid) {
		// Xóa các dấu ngăn cách
		value.erase(remove(value.begin(), value.end(), _thousandSeparator[0]), value.end());
		// Xóa đơn vị tiền tệ đi kèm
		value.erase(0, 1);
		// Chuyển đổi sang kiểu dữ liệu integer
		stringstream ss;
		ss << value;
		ss >> result;
	}
	else {
		succeeded = false;
		error_code = 2;
		error_message = "Invalid input format";
	}

	auto convertResult = make_tuple(succeeded, error_code, error_message, result);
	return convertResult;
}