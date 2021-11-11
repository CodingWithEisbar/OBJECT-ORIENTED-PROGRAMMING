//Nguyen Trung Nguyen
//20127404
//20CLC07

#include <iostream>
#include <vector>
#include <string>

#include "RandomIntegerGenerator.h"
#include "IntegerToCurrencyUIConverter.h"
#include "IntegerToThousandSeparatedUIConverter.h"
#include "PricesUIInput.h"
using namespace std;



int main() {

	//Khởi tạo kích thước vector
	RandomIntegerGenerator _rig;
	int n = _rig.next(5, 10);
	cout << "Prices need to type: " << n << endl;

	//Nhập các giá trị vào vector
	PriceUIInput _input;
	IntegerToThousandSeparatedUIConverter _intToThousand;
	IntegerToCurrencyUIConverter _intToCurrency;
	_input.setSize(n);
	vector<long long> prices = _input.enterPrice();
	long long sum = 0;

	cout << endl << "Your vector: " << endl;
	for (int i = 0; i < prices.size(); i++) {
		cout << prices[i] << " ";
		sum += prices[i];
	}

	cout << endl << "Convert to thousand seperated: "<<endl;
	for (int i = 0; i < prices.size(); i++) {
		string convertThousandSeperated = _intToThousand.convert(prices[i]);
		cout << convertThousandSeperated << " ";
	}

	cout << endl << "Convert to currency: " << endl;
	for (int i = 0; i < prices.size(); i++) {
		string convertToCurrency = _intToCurrency.convert(prices[i]);
		cout << convertToCurrency << " ";
	}

	string sumCurrency = _intToCurrency.convert(sum);
	cout << endl << "Your total money: " << sumCurrency << endl;

	cin.get();
	return 0;
}