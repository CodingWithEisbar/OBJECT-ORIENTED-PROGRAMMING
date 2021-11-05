#pragma once
#include "RandomIntegerGenerator.h"
#include "Fraction.h"


class RandomFractionGenerator {
private:
	RandomIntegerGenerator _rng;
public:
	Fraction next();
	Fraction next(int ceiling); //num & den in the range of [0, ceiling)
	Fraction next(int left, int right); // num & den in the range of [left, right]
};