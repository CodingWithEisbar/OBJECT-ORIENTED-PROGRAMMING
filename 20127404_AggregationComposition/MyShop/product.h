#pragma once
#include <string>
#include <memory>
#include "category.h"

using namespace std;

class Product {
private:
	int _productID;
	std::string _productName;
	int _price;
	shared_ptr<Category> _category;
public:
	Product() {

	}
	Product(int, std::string);
public:
	std::string getProductName() { return _productName; }
	int getProductID() { return _productID; }
	int getPrice() { return _price; }
public:
	void setProductName(std::string name) { _productName = name; }
	void setProductID(int value) { _productID = value; }
	void setProductPrice(int value) { _price = value; }
};