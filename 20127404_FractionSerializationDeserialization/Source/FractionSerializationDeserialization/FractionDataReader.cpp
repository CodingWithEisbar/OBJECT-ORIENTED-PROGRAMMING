#include "FractionDataReader.h"
#include "FractionUIConverter.h"

#include <iostream>
using namespace std;

FractionDataReader::FractionDataReader(string connectionString)
{
	_connectionString = connectionString;
};

vector<Fraction> FractionDataReader::GetAll()
{
	vector<Fraction> frac;
	ifstream input;
	input.open(_connectionString);
	while (!input.eof()) {
		string buffer;
		getline(input, buffer);
		FractionToStringDataConverter converter;
		bool check = get<0>(converter.convertBack(buffer));
		if (check) 
		{
			Fraction f = get<3>(converter.convertBack(buffer));
			frac.push_back(f);
		}
	}
	input.close();
	return frac;
}