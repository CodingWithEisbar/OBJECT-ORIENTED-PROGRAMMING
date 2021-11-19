#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "product.h"

class Category {
private:
	int _categoryID;
	std::string _categoryName;
	std::vector<std::shared_ptr<Product>> _productPtr;
public:
	Category(){
	
	}
	Category(int, std::string);
public:
	int getCategoryID() { return _categoryID; }
	std::string getCategoryName() { return _categoryName; }
	std::vector<std::shared_ptr<Product>> getProducts() { return _productPtr; }
public:
	void setCategoryID(int value) { _categoryID = value; }
	void setCategoryName(std::string name) { _categoryName = name; }
	void setProducts(std::vector<std::shared_ptr<Product>> product) { _productPtr = product; }
}; 