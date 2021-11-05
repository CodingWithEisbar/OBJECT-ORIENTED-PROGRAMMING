#include "StringtoFractionUIInput.h"
#include "Fraction.h"
#include "FractionUIConverter.h"

void StringToFractionUIInput::setSize(int value)
{
	_n = value;
}

vector<Fraction> StringToFractionUIInput::enterString() {
	vector<Fraction> frac;
	FractionToStringDataConverter converter;
	string buffer;
	
	for (int i = 0; i < _n; i++) {
		do {
		getline(cin >> ws, buffer);
		auto string_convert = converter.convertBack(buffer);
		if (get<0>(string_convert)) {
			frac.push_back(get<3>(string_convert));
		}
		else {
			cout << endl << "\t Invalid Fraction Type. Your fraction must be 1.a - 2.a b/c - 3.a/b"<<endl;
		}
		} while (converter.isValidFormat(buffer) == -1);
	}
	return frac;
}