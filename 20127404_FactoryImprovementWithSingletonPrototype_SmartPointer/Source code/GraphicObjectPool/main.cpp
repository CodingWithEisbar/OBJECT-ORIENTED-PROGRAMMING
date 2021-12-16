//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>

#include "shape.h"
#include "dataFileReader.h"
using namespace std;

int main() {

	dataFileReader data("data.txt");
	shared_ptr<SHAPEFACTORY> factory = SHAPEFACTORY::instance();
	
	vector<shared_ptr<SHAPE>> pool = data.getAll();
	factory->getShapeData(pool);
	factory->displayAllShape();
	
	cin.get();
	return 0;
}