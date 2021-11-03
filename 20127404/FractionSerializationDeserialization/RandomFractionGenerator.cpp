#include "RandomFractionGenerator.h"

Fraction RandomFractionGenerator::next() {
	Fraction f1;
	f1.setNum(_rng.next());
	f1.setDen(_rng.next());
	return f1;
}

Fraction RandomFractionGenerator::next(int ceiling) {
	Fraction f1;
	f1.setNum(_rng.next(ceiling));
	f1.setDen(_rng.next(ceiling));
	return f1;
}

Fraction RandomFractionGenerator::next(int left, int right)
{
	Fraction f1;
	f1.setNum(_rng.next(left, right));
	f1.setDen(_rng.next(left, right));
	return f1;
}