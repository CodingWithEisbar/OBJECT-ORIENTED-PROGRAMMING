#pragma once

#include "category.h"
#include "product.h"

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;

class productDBSet;
class categoryDBSet;

class TextDbContext {
private:
	map<string, string> _fileName;
	shared_ptr<Category> _categories;
	shared_ptr<Product> _products;
public:
	TextDbContext(){
	
	}
	TextDbContext(string connectionString);

};
