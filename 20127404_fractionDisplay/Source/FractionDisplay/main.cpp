//Nguyen Trung Nguyen
//2012704
#include <sstream>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "Integer.h"
#include "Fraction.h"
#include "RandomIntegerGenerator.h"
#include "RandomFractionGenerator.h"
#include "FractionToLowestTermUIConverter.h"
#include "FractionToDecimalUIConverter.h"
#include "FractionToStringConverter.h"
#include "FractionToPercentageConverter.h"
using namespace std;

int main() {
	ofstream out_file("data.txt");
	
	//Generate a random integer number n in the range of [15, 25].
	int left = 15;
	int right = 25;
	RandomIntegerGenerator i1;
	int n = i1.next(left, right);
	
	cout << endl << "n = " << n;

	//Generate randomly n Fractions (numerator & denominator will be in the range of [1, 50])
	RandomFractionGenerator rfg;
	vector<Fraction> my_list;

	int minNumDen = 1;
	int maxNumDen = 50;
	
	for (int i = 0; i < n; i++) {
		Fraction f1 = rfg.next(minNumDen,maxNumDen);
		my_list.push_back(f1);
	}
	FractionToStringUIConverter stringConverter;
	cout << endl << "Your ORIGINAL fraction: "<<endl;
	for (int i = 0; i < my_list.size(); i++) {
		string show = stringConverter.Convert(my_list[i]);
		out_file << show << endl;
		cout << show << ", "; 
	}
	cout << endl;

	FractionToLowestTermUIConverter lowestTerm;
	cout << endl << "Your fraction in LOWEST TERM : " << endl;
	for (int i = 0; i < my_list.size(); i++) {
		string show = lowestTerm.convert(my_list[i]);
		out_file << show << endl;
		cout << show << ", ";
	}
	cout << endl;


	int dec_precision = 2;
	bool decIsFixed = true;
	FractionToDecimalUIConverter decimal_ver(dec_precision, decIsFixed);
	cout << endl << "Your fraction in DECIMAL : " << endl;
	for (int i = 0; i < my_list.size(); i++) {
		string show = decimal_ver.convert(my_list[i]);
		out_file << show << endl;
		cout << show << ", ";
	}
	cout << endl;


	int percent_precision = 2;
	bool percentIsFixed = true;
	FractionToPercentageConverter percent_ver(percent_precision, percentIsFixed);
	cout << endl << "Your fraction in PERCENTAGE : " << endl;
	for (int i = 0; i < my_list.size(); i++) {
		string show = percent_ver.convert(my_list[i]);
		out_file << show << endl;
		cout << show << ", ";
	}
	cout << endl;

	out_file.close();
	cin.get();
	return 0;
}