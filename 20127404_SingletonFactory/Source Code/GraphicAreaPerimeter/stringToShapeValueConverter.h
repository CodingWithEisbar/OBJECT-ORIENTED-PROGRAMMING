#ifndef _STRINGTOSHAPE_H_
#define _STRINGTOSHAPE_H_

#include <string>
#include <sstream>
#include <regex>
#include <tuple>
using namespace std;


class stringToShapeValueConverter {
private:
	string _shapeValue;
public:
	stringToShapeValueConverter();
	stringToShapeValueConverter(string);
public:
	bool isValidShapeValue(string);
	string convertBack(double);
	tuple<bool, int, string, double> convert(string);
};


#endif
