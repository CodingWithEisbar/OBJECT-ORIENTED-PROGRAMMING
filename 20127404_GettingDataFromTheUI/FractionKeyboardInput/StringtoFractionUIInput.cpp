#include "StringtoFractionUIInput.h"
#include "Fraction.h"
#include "FractionUIConverter.h"

void StringToFractionUIInput::setSize(int value)
{
	_n = value;
}

vector<Fraction> StringToFractionUIInput::enterString() {
	vector<Fraction> result;
	FractionToStringDataConverter converter;
	string buffer;
	for (int i = 0; i < _n; i++) {
		do {
		getline(cin >> ws, buffer);
		auto string_convert = converter.convertBack(buffer);
		if (get<0>(string_convert)) {
			result.push_back(get<3>(string_convert));
		}

		} while (!converter.isValidFormat(buffer));
		
	}
	return result;
}