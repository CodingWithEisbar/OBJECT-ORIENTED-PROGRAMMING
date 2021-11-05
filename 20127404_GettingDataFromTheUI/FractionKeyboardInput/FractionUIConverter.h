#pragma once
#include <iomanip>
#include <sstream>
#include <string>
#include <tuple>
#include <regex>
#include "Fraction.h"
//Fraction - To - Decimal
class FractionToDecimalUIConverter {
private:
    int _precision;
    bool _isFixed;
public:
    FractionToDecimalUIConverter(int precision, bool isFixed);
public:
    string convert(const Fraction& frac);
};


//Fraction - To - Percentage
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

//Fraction - To - String
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
    int isValidFormat(string value);
};


//Fraction - To - LowestTerm
class FractionToLowestTermUIConverter {
public:
    string convert(const Fraction& frac);
};