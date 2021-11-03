#include "FractionToPercentageConverter.h"
#include <iomanip>

FractionToPercentageConverter::FractionToPercentageConverter() {

}

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