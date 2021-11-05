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

    int isValid = isValidFormat(value);
    if (isValid == 1) {

        //Trường hợp phân số
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(0, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
        IntegerToStringUIConverter converter;
        long long num = get<3>(converter.convertBack(numString));
        long long den = get<3>(converter.convertBack(denString));
        frac.setNum(num);
        frac.setDen(den);
    }
    else if (isValid == 2) {
        //Trường hợp hỗn số
        size_t spaceIndex = value.find_first_of(" ");
        string wholeNumString = value.substr(0, spaceIndex);
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(slashIndex - spaceIndex, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
        IntegerToStringUIConverter converter;
        long long wholeNum = get<3>(converter.convertBack(wholeNumString));
        long long num = get<3>(converter.convertBack(numString));
        long long den = get<3>(converter.convertBack(denString));

        //Chuyển đổi từ hỗn số sang phân số thường
        num = (wholeNum * den) + num;
        frac.setNum(num);
        frac.setDen(den);
    }
    else if (isValid == 3) {
        //Trường hợp số nguyên bình thường
        IntegerToStringUIConverter converter;
        long long num = get<3>(converter.convertBack(value));
        frac.setNum(num);
        frac.setDen(1);
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
    int isValid = isValidFormat(value);
    if (isValid == 1) {
       
        //Trường hợp phân số
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(0, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
        IntegerToStringUIConverter converter;
        long long num = get<3>(converter.convertBack(numString));
        long long den = get<3>(converter.convertBack(denString));
        f.setNum(num);
        f.setDen(den);
    }
    else if (isValid == 2) {
        //Trường hợp hỗn số
        size_t spaceIndex = value.find_first_of(" ");
        string wholeNumString = value.substr(0, spaceIndex);
        value = value.substr(spaceIndex + 1, value.size() - 1);
        size_t slashIndex = value.find_first_of("/");
        string numString = value.substr(0, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);
       /* string numString = value.substr(slashIndex - spaceIndex, slashIndex);
        string denString = value.substr(slashIndex + 1, value.length() - slashIndex);*/
        IntegerToStringUIConverter converter;
        long long wholeNum = get<3>(converter.convertBack(wholeNumString));
        long long num = get<3>(converter.convertBack(numString));
        long long den = get<3>(converter.convertBack(denString));

        //Chuyển đổi từ hỗn số sang phân số thường
        num = (wholeNum * den) + num;
        f.setNum(num);
        f.setDen(den);
    }
    else if (isValid == 3) {
        //Trường hợp số nguyên bình thường
        IntegerToStringUIConverter converter;
        long long num = get<3>(converter.convertBack(value));
        f.setNum(num);
        f.setDen(1);
    }
    else {
        result = false;
    }
    return result;
}

int FractionToStringDataConverter::isValidFormat(string value) {
    bool check_01, check_02, check_03;
    string pattern_01 = "\\b\\d+\\/[1-9][0-9]*\\b";
    regex fractionPattern_01(pattern_01);
    check_01 = regex_match(value, fractionPattern_01);
    if (check_01 == true) {
        return 1;
    }
    string pattern_02 = "\\b\\d+\\s\\d+\\/[1-9][0-9]*\\b";
    regex fractionPattern_02(pattern_02);
    check_02 = regex_match(value, fractionPattern_02);
    if (check_02 == true) {
        return 2;
    }
    string pattern_03 = "\\b\\d+\\b";
    regex fractionPattern_03(pattern_03);
    check_03 = regex_match(value, fractionPattern_03);
    if (check_03 == true) {
        return 3;
    }
    return -1;
}
