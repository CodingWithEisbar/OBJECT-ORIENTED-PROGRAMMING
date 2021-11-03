#include "Integer.h"
#include "Fraction.h"

void Fraction::setNum(long long value) { _num = value; }
void Fraction::setDen(long long value) { _den = value; }

long long Fraction::getNum() const { return _num; }
long long Fraction::getDen() const { return _den; }

Fraction Fraction::lowestTerm()
{
	Fraction f1;
	int tmp = Integer::gcd(f1.getNum(), f1.getDen());
	f1.setNum(f1.getNum() / tmp);
	f1.setDen(f1.getDen() / tmp);
	return f1;
}

