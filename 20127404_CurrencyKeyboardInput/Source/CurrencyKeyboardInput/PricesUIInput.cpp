#include "PricesUIInput.h"

void PriceUIInput::setSize(int value)
{
	_n = value;
}

vector<long long> PriceUIInput::enterPrice()
{
	vector<long long> result;
	long long buffer;
	for (int i = 0; i < _n; i++) {
		cin >> buffer;
		result.push_back(buffer);
	}
	return result;
}