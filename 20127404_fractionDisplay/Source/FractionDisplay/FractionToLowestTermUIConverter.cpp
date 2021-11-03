#include "Fraction.h"
#include "Integer.h"
#include "FractionToLowestTermUIConverter.h"

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

