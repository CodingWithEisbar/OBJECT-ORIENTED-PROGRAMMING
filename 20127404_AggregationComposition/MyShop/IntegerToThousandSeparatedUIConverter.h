#pragma once
#include <string>
#include <tuple>
#include <regex>
#include <string>
#include <sstream>
using namespace std;

class IntegerToThousandSeparatedUIConverter {
private:
    string _thousandSeparator = ".";
public:
    bool isValidFormat(string);
    string convert(const int&);
    tuple<bool, int, string, int> convertBack(string);
};