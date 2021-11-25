//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <tuple>
#include <vector>

#include "RandomIntegerGenerator.h"
using namespace std;

//Class Declaration
class point2D;
class point3D;
class point3DToString;
class writeDataToFile;


class point2D {
private:
	int _x;
	int _y;
public:
	//Constructor
	point2D() {}

	point2D(int x, int y)
	{
		this->_x = x;
		this->_y = y;
	}
public:
	int getX() { return _x; }
	int getY() { return _y; }
public:
	void setX(int value) { _x = value; }
	void setY(int value) { _y = value; }
public:
	virtual string toString() {
		stringstream ss;
		ss << "(" << getX() << ", " << getY() << ")";
		string result = ss.str();
		return result;
	}
};


class point3D : public point2D {
private:
	int _z;
public:
	point3D() {}
	point3D(int x, int y, int z)
	{
		point2D::setX(x);
		point2D::setY(y);
		this->_z = z;
	}
public:
	int getZ() { return _z; }
public:
	void setZ(int value) { _z = value; }
public:
	string toString()
	{
		stringstream ss;
		ss << "(" << point2D::getX() << ", " << point2D::getY() << ", " << getZ() << ")";

		string result = ss.str();
		return result;
	}
};


class point3DToString {
private:
	std::string _inputString;
public:
	bool isValidFormat(string value)
	{
		string pattern = "\\d+\\, \\d+\\, \\d";
		regex _3DPointPattern(pattern);
		bool result = regex_match(value, _3DPointPattern);
		return result;
	}

	string convert(point3D myPoint)
	{
		stringstream builder;
		builder << "(" << myPoint.getX() << ", " << myPoint.getY() << ", " << myPoint.getZ() << ")";

		string result = builder.str();
		return result;
	}

	tuple<bool, int , string, point3D> convertBack(const string& value)
	{
		//Input value type: a, b, c
		point3D receive_point;

		bool succeeded = true;
		int error_code_value = 0;
		string message = "";

		bool isValid = isValidFormat(value);
		if (isValid) {
			string x_str, y_str, z_str;
			stringstream ss(value);
			getline(ss, x_str, ',');
			getline(ss, y_str, ' ');
			getline(ss, y_str, ',');
			getline(ss, z_str, ' ');
			getline(ss, z_str);
			long long x, y, z;
			x = stoll(x_str);
			y = stoll(y_str);
			z = stoll(z_str);
			receive_point.point2D::setX(x);
			receive_point.point2D::setY(y);
			receive_point.setZ(z);			
		}
		else {
			succeeded = false;
			error_code_value = 1;
			message = "Invalid input value!";
		}
		auto result = make_tuple(succeeded, error_code_value, message, receive_point);
		return result;

	}
};

class writeDataToFile {
private:
	string _fileName;
public:
	writeDataToFile(string fileName)
	{
		_fileName = fileName;
	}
public:
	void writeAll(vector<point3D> data) {
		ofstream file;
		try {
			file.open(_fileName, ios::out);
			for (int i = 0; i < data.size(); i++)
			{
				file << data[i].toString() << endl;
			}
			file.close();
		}
		catch (exception ex) {
			throw runtime_error("Cannot open this file!!!");
			return;
		}
	}
};

int main() {

	vector<point3D> myPoint;
	RandomIntegerGenerator _rig;
	int n = _rig.next(3, 7);
	cout << endl << "You need to enter " << n << " points!"<< endl ;

	for (int i = 0; i < n; i++)
	{
		point3DToString converter;
		string input;
		getline(cin >> ws, input);
		auto result = converter.convertBack(input);
		if(get<0>(result)){
			myPoint.push_back(get<3>(result));
		}
		else {
			cout << endl << get<2>(result) << endl;
			i--;
		}		
	}

	//Print out all the points to the screen
	for (int i = 0; i < myPoint.size(); i++)
	{
		cout << myPoint[i].toString() << endl;
	}

	//Write to file
	writeDataToFile output("point3d.txt");
	try {
		output.writeAll(myPoint);
		cout << endl << "Data write to file successfully!!!";
	}
	catch (runtime_error ex) {
		cout << ex.what() << endl;
	}

	cin.get();
	return 0;
}
