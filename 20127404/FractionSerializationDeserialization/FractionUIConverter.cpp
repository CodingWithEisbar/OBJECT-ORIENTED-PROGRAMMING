#include "FractionUIConverter.h"

//Các hàm trong lớp chuyển đổi thành dạng Thập phân 
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

//Các hàm trong lớp chuyển đổi thành dạng Phần trăm
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

//Các hàm trong lớp chuyển đổi thành dạng Tối giản
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

//Các hàm trong lớp chuyển đổi thành dạng Chuỗi
string FractionToStringDataConverter::convert(const Fraction& f) {
    stringstream builder;
    builder << f.getNum()<<"/"<<f.getDen();

    string result = builder.str();
    return result;
}

Fraction FractionToStringDataConverter::convertBack(string value) {
    

}

bool FractionToStringDataConverter::tryConvertBack(string value, Fraction& f) 
{

}

bool FractionToStringDataConverter::isValidFormat(string value) {



}
