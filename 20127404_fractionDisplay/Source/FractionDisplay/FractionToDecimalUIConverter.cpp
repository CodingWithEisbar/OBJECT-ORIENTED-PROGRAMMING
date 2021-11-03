#include "FractionToDecimalUIConverter.h"
#include <iomanip>
#include <sstream>


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