#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Fraction.h"
using namespace std;

class FractionDataWriter {
private:
	string _connectionString;
public:
	FractionDataWriter(string connectionString);
public:
	void writeDataToFile(vector<Fraction> frac);

};