#include "FractionUIConverter.h"
#include "Integer.h"

//Fraction - To - Decimal
FractionToDecimalUIConverter::FractionToDecimalUIConverter(int precision, bool isFixed)
{
    this->_precision = precision;
    this->_isFixed = isFixed;
}

string FractionToDecimalUIConverter::convert(const Fraction& frac) {
    stringstream builder;
    float value = frac.getNum() * 1.0 / frac.getDen();
    builder << setprecision(_precision);
    if (_isFixed) {
        builder << fixed;
    }
    builder << value;

    string result = builder.str();
    return result;
}

//Fraction - To - Percentage
FractionToPercentageConverter::FractionToPercentageConverter(int precision, bool isFixed) {
    _precision = precision;
    _isFixed = isFixed;
}

string FractionToPercentageConverter::convert(const Fraction& frac)
{
    stringstream builder;
    float value = frac.getNum() * 100.0 / frac.getDen();

    builder << setprecision(_precision);
    if (_isFixed) {
        builder << fixed;
    }
    builder << value << "%";

    string result = builder.str();
    return result;
}

//Fraction - To - LowestTerm
string FractionToLowestTermUIConverter::convert(const Fraction& frac)
{
    stringstream builder;

    long long  gcd = Integer::gcd(frac.getNum(), frac.getDen());
    long long  num = frac.getNum() / gcd;
    long long  den = frac.getDen() / gcd;

    if (num > den) { // 9/2   8/2  
        long long fullNumber = num / den; // 4
        builder << fullNumber << " ";
        num = num % den; // 1
    }

    if (num > 0) {
        builder << num;

        if (den != 1) {
            builder << "/" << den;
        }
    }

    string result = builder.str();
    return result;
}


//Fraction - To - String:
string FractionToStringDataConverter::convert(const Fraction& f) {
    stringstream builder;
    builder << f.getNum()<<"/"<<f.getDen();

    string result = builder.str();
    return result;
}

tuple<bool, int, string, Fraction> FractionToStringDataConverter::convertBack(string value) {
    bool succeeded = true;
    int error_code = 0;
    string message = "";
    Fraction frac;

    bool isValid = isValidFormat(value);
    if (isValid) {
        succeeded = true;
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(0, slashIndex);
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
        message = "Invalid Fraction Format. ";
    }
    auto result = make_tuple(succeeded, error_code, message, frac);
    return result;
};

bool FractionToStringDataConverter::tryConvertBack(string value, Fraction& f) 
{
    bool result = true;
    bool isValid = isValidFormat(value);
    if (isValid) {
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(0, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
        IntegerToStringUIConverter converter;
        long long num = get<3>(converter.convertBack(numString));
        long long den = get<3>(converter.convertBack(denString));
        f.setNum(num);
        f.setDen(den);
    }
    else {
        result = false;
    }
    return result;
}

bool FractionToStringDataConverter::isValidFormat(string value) {
    bool res = true;
    string pattern = "\\b\\d+\\/[1-9][0-9]*\\b";
    regex fractionPattern(pattern);
    res = regex_match(value, fractionPattern);
    return res;
}
