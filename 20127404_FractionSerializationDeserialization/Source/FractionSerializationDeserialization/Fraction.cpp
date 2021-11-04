#include "Integer.h"
#include "Fraction.h"

void Fraction::setNum(long long value) { _num = value; }
void Fraction::setDen(long long value) { _den = value; }

long long Fraction::getNum() const { return _num; }
long long Fraction::getDen() const { return _den; }

void Fraction::sum (Fraction &result, Fraction f1) 
{
	result._num = result._num * f1._den + result._den * f1._num;
	result._den = result._den * f1._den;
}


