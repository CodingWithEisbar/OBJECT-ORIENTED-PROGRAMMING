//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

#include "IntegerToCurrencyUIConverter.h"
#include "IntegerToThousandSeparatedUIConverter.h"
#include "category.h"
#include "product.h"
using namespace std;


int main() {
	while (true) {
	int choice;
		cout << "What do you want to do? " << endl;
		cout << "1. Display all categories" << endl;
		cout << "2. Find products by name" << endl;
		cout << "3. Find products by price range" << endl;
		cout << endl;
		cout << "0. Quit" << endl;

		cout << "Please enter your choice: ";
		cin >> choice;
		if (choice == 1) 
		{
			//In ra tất cả các danh mục
		}
		else if (choice == 2)
		{
			//Tìm sản phẩm theo tên
		}
		else if (choice == 3)
		{
			//Tìm sản phẩm trong khoảng giá 
		}
		else if (choice == 0) 
		{
			cout << endl << "\tHAVE A GOOD DAY. BYE BYE";
			return 0;
		}
		else {
			cout << endl << "\tInvalid choice!! Please re-enter your choice value.";
		}

	}
}