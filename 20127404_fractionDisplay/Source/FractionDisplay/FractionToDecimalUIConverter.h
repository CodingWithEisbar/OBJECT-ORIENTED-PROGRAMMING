#pragma once
#include "Fraction.h"

class FractionToDecimalUIConverter {
private:
    int _precision;
    bool _isFixed;
public:
    FractionToDecimalUIConverter(int precision, bool isFixed); 
public:
    string convert(const Fraction& frac);
};