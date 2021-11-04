#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <string>
#include "Fraction.h"


class FractionDataReader {
private:
    string _connectionString;
public:
    FractionDataReader(string connectionString);
public:
    vector<Fraction> GetAll();
};