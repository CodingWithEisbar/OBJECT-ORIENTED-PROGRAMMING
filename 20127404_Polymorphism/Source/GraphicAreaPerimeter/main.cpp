//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>
#include <vector>
#include <memory>

#include "RandomIntegerGenerator.h"
#include "RandomFloatGenerator.h"
#include "shape.h"
#include "dataFileWriter.h"
using namespace std;

int main() {

	//Generate a random integer n in the range of [6, 12]
	RandomIntegerGenerator _rig;
	
	int n = _rig.next(6, 12);
	vector<shared_ptr<Shape>> shape_collection;

	cout << endl << "Number of shapes: " << n << endl;
	//Generate randomly n shapes which belong to three types Rectangle, Circle, Triangle 
	for (int i = 0; i < n; i++)
	{
		int choice = _rig.next(1,3);
		if (choice == 1) {
			RandomFloatGenerator _rfg;
			Shape* _rec = new Rectangle();
			_rec->setShapeCode(choice);
			_rec->setRandomComponents(1, 10);
			shared_ptr<Shape> p(_rec);
			shape_collection.push_back(p);
		}
		else if (choice == 2) {
			RandomFloatGenerator _rfg;
			Shape* _tri = new Triangle();
			_tri->setShapeCode(choice);
			_tri->setRandomComponents(1, 10);
			shared_ptr<Shape> p(_tri);
			shape_collection.push_back(p);
		}
		else if (choice == 3){
			RandomFloatGenerator _rfg;
			Shape* _cir = new Circle();
			_cir->setShapeCode(choice);
			_cir->setRandomComponents(1, 10);
			shared_ptr<Shape> p(_cir);
			shape_collection.push_back(p);
		}
	}
	//Print out all the shapes generated, together with their area and perimeter
	for (int i = 0; i < n; i++)
	{
		shared_ptr<Shape> pointer = shape_collection[i];
		int shapeCode = pointer->getShapeCode();
		if (shapeCode == 1) {
			cout << "Rectangle: Width= " << pointer->getWidth() 
				<< ", Height= " << pointer->getHeight() << " => Area= " 
				<< pointer->Area() << ", Perimeter= " << pointer->Perimeter();
		}
		else if (shapeCode == 2)
		{
			cout << "Triangle: A= " << pointer->getA() << ", B= " << pointer->getB() 
				<< ", C= " << pointer->getC() << " => Area= "
				<< pointer->Area() << ", Perimeter= " << pointer->Perimeter();
		}
		else if (shapeCode == 3) {
			cout << "Circle: Radius= " << pointer->getRadius() << " => Area= "
				<< pointer->Area() << ", Perimeter= " << pointer->Perimeter();
		}
		cout << endl;
	}

	//Save all generated graphics shape into the file objects.txt
	shapeDataWriter output("objects.txt");
	output.writeShapeDataToFile(shape_collection);

	cin.get();
	return 0;
}
