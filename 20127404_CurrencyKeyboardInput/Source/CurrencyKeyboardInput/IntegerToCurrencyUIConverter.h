#pragma once

#include <tuple>
#include <string>
#include <regex>
#include <sstream>
using namespace std;


class IntegerToCurrencyUIConverter {
private:
    string _thousandSeparator = ".";
    string _currency = "d";
public:
    bool isValidFormat(string);
    string convert(const int&);
    tuple<bool, int, string, int> convertBack(string);
};
