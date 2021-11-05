//20127404
//Nguyen Trung Nguyen
//20CLC07

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Fraction.h"
#include "FractionUIConverter.h"
#include "Integer.h"
#include "RandomFractionGenerator.h"
#include "RandomIntegerGenerator.h"
#include "FractionDataWriter.h"
#include "StringtoFractionUIInput.h"
using namespace std;


int main() {
	//1. Khởi tạo số lượng phân số cần nhập vào
	RandomIntegerGenerator ran_int;
	int n = ran_int.next(5, 10);
	cout << endl << "Fraction needs to type: " << n << endl;

	//2. Tiến hành nhập vào các phân số 
	StringToFractionUIInput input_string;
	input_string.setSize(n);
	vector<Fraction> frac = input_string.enterString();

	//Lưu vào file data.txt




	//Tính tổng phân số nhập vào và xuất ra màn hình theo dạng tối giản





	return 0;
}