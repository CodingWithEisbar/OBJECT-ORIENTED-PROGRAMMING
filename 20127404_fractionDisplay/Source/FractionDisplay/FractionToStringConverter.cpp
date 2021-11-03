#include "FractionToStringConverter.h"

string FractionToStringUIConverter::Convert(const Fraction& frac) {
    stringstream builder;
    builder << frac.getNum() << "/" << frac.getDen();

    string result = builder.str();
    return result;
}
