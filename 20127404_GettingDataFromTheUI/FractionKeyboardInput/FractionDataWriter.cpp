#include "FractionDataWriter.h"

FractionDataWriter::FractionDataWriter(string connectionString)
{
	_connectionString = connectionString;
}
void FractionDataWriter::writeDataToFile(vector<Fraction> frac)
{
	ofstream output;
	try {
		output.open(_connectionString, ios::out);
	}
	catch(exception ex){
		throw runtime_error("Cannot open this file!!!");
		return;
	}
	for (int i = 0; i < frac.size(); i++)
	{
		if (i == frac.size() - 1) 
			output << frac[i].getNum() << "/" << frac[i].getDen();
		
		else 
			output << frac[i].getNum() << "/" << frac[i].getDen() << ", ";
	}
	output.close();
}