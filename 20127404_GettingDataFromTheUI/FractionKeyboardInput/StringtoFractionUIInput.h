#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Fraction.h"
using namespace std;

class StringToFractionUIInput {
private:
	int _n;
public:
	void setSize(int value);
public:
	vector<Fraction> enterString();
};