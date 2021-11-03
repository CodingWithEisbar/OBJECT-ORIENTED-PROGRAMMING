#pragma once

#include "Fraction.h"

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