//Nguyen Trung Nguyen
//20127404
//20CLC07

#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
#include <tuple>
#include <vector>

#include "FractionUIConverter.h"
#include "RandomFractionGenerator.h"
#include "RandomIntegerGenerator.h"
#include "Fraction.h"
#include "Integer.h"
#include "FractionDataReader.h"
#include "FractionDataWriter.h"
using namespace std;

int main() {
	FractionDataReader reader("data.txt");
	vector<Fraction> list = reader.GetAll();

	//Genrate Random Fraction
	RandomFractionGenerator rfg;
	Fraction sample01 = rfg.next(1, 99);
	list.push_back(sample01);

	Fraction sample02 = rfg.next(1, 99);
	list.push_back(sample02);

	//Print list to console and calculate total fraction
	Fraction frac_total;
	cout << endl << "Your list: ";
	for (int i = 0; i < list.size(); i++) {
		if (i == list.size() - 1) 
			cout << list[i].getNum() << "/" << list[i].getDen();
		else
			cout<< list[i].getNum() << "/" << list[i].getDen()<<", ";

		frac_total.sum(frac_total, list[i]);
	}
	FractionToLowestTermUIConverter converter;
	string str_total = converter.convert(frac_total);
	cout << endl << "Your total: " << str_total << endl;

	//Write fraction list to new file
	FractionDataWriter writer("data.txt");
	try {
		writer.writeDataToFile(list);
	}
	catch (runtime_error ex) {
		cout << ex.what() << endl;
	}

	cin.get();
	return 0;
}
