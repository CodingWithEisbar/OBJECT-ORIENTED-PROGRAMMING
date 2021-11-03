//Nguyen Trung Nguyen
//20127404
//20CLC07

#include <iostream>
#include <string>
#include <string.h>
#include <regex>
#include <sstream>
#include <tuple>
using namespace std;

class Fraction {
private:
	long long _num, _den;
public:
	long long getNum() const { return _num; }
	long long getDen() const { return _den; }
public:
	void setNum(long long value) { _num = value; }
	void setDen(long long value) { _den = value; }
public:
	Fraction() {
		_num = 0;
		_den = 0;
	}
	Fraction(long long num, long long den) {
		_num = num;
		_den = den;
	}
	Fraction(const Fraction& other)
	{
		_num = other._num;
		_den = other._den;
	}
};

class IntegerToStringUIConverter {
public:
	bool isValidInteger(string value);
	string convert(int);
	bool tryConvertBack(string, int&);
	tuple<bool, int, string, int> convertBack(string buffer);
};

//Integer -> String function definition
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


//------------------------------------------------------------------------------------------------------
class FractionToStringUIConverter {
public:
	string convert(const Fraction& f);
	bool isValidFormat(string value);
	tuple<bool, int, string, Fraction> convertBack(string value);
};

//Fraction -> String Function definition
string FractionToStringUIConverter::convert(const Fraction& f) {
	stringstream builder;
	builder << f.getNum() << "/" << f.getDen();
	string result = builder.str();
	return result;
};

bool FractionToStringUIConverter::isValidFormat(string value)
{
	bool res = true;
	string pattern = "\\b\\d+\\/[1-9][0-9]*\\b";
	regex fractionPattern(pattern); //Điều kiện của mẫu số phải != 0
	res = regex_match(value, fractionPattern);
	return res;
};

tuple<bool, int, string, Fraction> FractionToStringUIConverter::convertBack(string value)
{
	bool succeeded = true;
	int error_code = 0;
	string message = "";
	Fraction frac;

	bool isValid = isValidFormat(value);
	if (isValid) {
		succeeded = true;
		size_t slashIndex = value.find_first_of("/");
		string numString = value.substr(0,slashIndex);
		string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
		IntegerToStringUIConverter converter;
		long long num = get<3>(converter.convertBack(numString));
		long long den = get<3>(converter.convertBack(denString));
		frac.setNum(num);
		frac.setDen(den);
	}
	else
	{
		succeeded = false;
		error_code = 1;
		message = "Invalid Fraction Format";
	}
	auto result = make_tuple(succeeded, error_code, message, frac);
	return result;
};


int main() {
	string a = "2/3";
	string b = "3kkd///d2";
	FractionToStringUIConverter converter;
	tuple<bool, int, string, Fraction> tup_01, tup_02;
	tup_01 = converter.convertBack(a);
	tup_02 = converter.convertBack(b);
	
	if (get<0>(tup_01)) {
		Fraction frac = get<3>(tup_01);
		cout << frac.getNum() << "/" << frac.getDen() << endl;
	}
	else {
		cout << get<2>(tup_01)<<endl;
	}

	if (get<0>(tup_02)) {
		Fraction frac = get<3>(tup_02);
		cout << frac.getNum() << "/" << frac.getDen() << endl;
	}
	else {
		cout << get<2>(tup_02) << endl;
	}

	cin.get();
	return 0;
}
