#pragma once
#include <tuple>
#include <string>
#include <iostream>
#include <regex>
#include <sstream>
using namespace std;

class Integer {
public:
	static long long gcd(int a, int b);
};

class IntegerToStringUIConverter {
public:
	bool isValidInteger(string value);
	string convert(int);
	bool tryConvertBack(string, int&);
	tuple<bool, int, string, int> convertBack(string buffer);
};