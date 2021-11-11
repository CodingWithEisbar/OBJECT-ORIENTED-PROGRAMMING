#pragma once

#include <vector>
#include <iostream>
using namespace std;

class PriceUIInput {
private:
	int _n;
public:
	void setSize(int);
public:
	vector<long long> enterPrice();
};
