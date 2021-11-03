//20127404
//Nguyen Trung Nguyen
#include <sstream>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

//Task 1:
class RandomIntegerGenerator {
private:
	int _left, _right;
public:
	void setLeft(int value) { _left = value; }
	void setRight(int value) { _right = value; }
	
	int getLeft() { return _left; }
	int getRight() { return _right; }
public:
	RandomIntegerGenerator() {
		srand(time(NULL));
	}
	int next(int left, int right) {
		//Return a random number in range [left,right];
		return rand() % (right - left + 1) + left;
	}
public:
	//toString
	string toString() {
		stringstream out;
		out << "Your random number: " << next(_left,_right);
		string result = out.str();
		return result;
	}
};


//Task 2:
class Util {
public:
	static long long gcd(int a, int b)
	{
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		return a;
	}
};

class Fraction {
private:
	long long _num;
	long long _den;
public:
	void setNum(int value) { _num = value; }
	void setDen(int value) { _den = value; }

	int getNum() { return _num; }
	int getDen() { return _den; }
public:
	Fraction lowestTerm() {
		Fraction f1;
		int tmp = Util::gcd(f1.getNum(), f1.getDen());
		f1.setNum(f1.getNum() / tmp);
		f1.setDen(f1.getDen() / tmp);
		return f1;
	}
public:
	//toString
	string toString() {
		stringstream out;
		out << "Your fraction: " << _num << "/" << _den;
		string result = out.str();
		return result;
	}
	Fraction add(Fraction f1) {
		Fraction result;
		result._num = _num * f1._den + _den * f1._num;
		result._den = _den * f1._den;
		result = result.lowestTerm();
		return result;
	}
};


class RandomFractionGenerator {
private:
		RandomIntegerGenerator _rng;
public:
		Fraction next() {
			Fraction f1;
			f1.setNum(rand() % 100 + 1);
			f1.setDen(rand() % 100 + 1);
			return f1;
		}	
};


int main() {
	//Task 1: Generate a random number in the range of [10,20]
	RandomIntegerGenerator i1;
	i1.setLeft(10);
	i1.setRight(20);
	cout << i1.toString() << endl;
	
	//Task 2: Generate randomly n Fractions (numerator & denominator will be in the range of [1, 100])
	RandomFractionGenerator rfg;
	Fraction answer = rfg.next();
	int n;
	cout << "Enter n:";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		Fraction f1 = rfg.next();
		cout << f1.toString() << endl;
		answer = answer.add(f1);
	}
	cout << "The total result: " << answer.toString() << endl;
	system("pause");
	return 0;
}