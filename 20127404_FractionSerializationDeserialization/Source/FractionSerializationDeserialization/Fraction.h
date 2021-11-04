#pragma once
#include <string>
#include <sstream>
using namespace std;

class Fraction {
private:
	long long _num;
	long long _den;
public:
	Fraction() {
		_num = 0;
		_den = 1;
	}
public:
	void setNum(long long value);
	void setDen(long long value);

	long long getNum() const;
	long long getDen() const;
public: 
	void sum(Fraction& result, Fraction f1);
};