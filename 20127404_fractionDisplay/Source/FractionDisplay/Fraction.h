#pragma once
#include <string>
#include <sstream>
using namespace std;

class Fraction {
private:
	long long _num;
	long long _den;
public:
	void setNum(int value); 
	void setDen(int value);

	long long getNum() const;
	long long getDen() const;
public:
	Fraction lowestTerm();

};