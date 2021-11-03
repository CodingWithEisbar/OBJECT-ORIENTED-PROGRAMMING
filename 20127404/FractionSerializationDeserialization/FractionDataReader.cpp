#include "FractionDataReader.h"

FractionDataReader::FractionDataReader(string connectionString)
{
	_connectionString = connectionString;
};

vector<Fraction> FractionDataReader::GetAll()
{
	vector<Fraction> frac;
	ifstream input;
	input.open(_connectionString);

	string buffer;
	while (input >> buffer)[

	]
	
};