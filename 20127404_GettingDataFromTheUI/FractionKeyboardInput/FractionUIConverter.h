#pragma once
#include <iomanip>
#include <sstream>
#include <string>
#include <tuple>
#include "Fraction.h"
//Chuyển đổi Phân số thành dạng Thập phân 
class FractionToDecimalUIConverter {
private:
    int _precision;
    bool _isFixed;
public:
    FractionToDecimalUIConverter(int precision, bool isFixed);
public:
    string convert(const Fraction& frac);
};


//Chuyển đổi Phân số thành dạng Phần trăm
class FractionToPercentageConverter {
public:
    int _precision;
    bool _isFixed;
public:
    FractionToPercentageConverter(); //Do nothing
public:
    FractionToPercentageConverter(int precision, bool isFixed);
public:
    string convert(const Fraction& f);
};

//Chuyển đổi Phân Số thành dạng Chuỗi
class FractionToStringDataConverter {
public:
    string convert(const Fraction& f);

    // Can throw an exception when parse
    tuple<bool, int, string, Fraction> convertBack(string value);

    // Will return true if parsing successfully
    // Return false if cannot parse
    // The output Fraction will be stored through reference 
    bool tryConvertBack(string value, Fraction& f);

    // Check if you can parse a string into a fraction
    bool isValidFormat(string value);
};


//Đưa ra dạng tối giản của phân số
class FractionToLowestTermUIConverter {
public:
    string convert(const Fraction& frac);
};