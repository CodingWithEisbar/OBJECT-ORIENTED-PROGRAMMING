//Nguyen Trung Nguyen
//20127404
//20CLC07

#include <iostream>
#include <iomanip>

#include "shape.h"
#include "dataFileReader.h"
using namespace std;


int main() {
	dataFileReader input_file("data.txt");
	vector<shared_ptr<SHAPE>> shape = input_file.getAll();

	for (int i = 0; i < shape.size(); i++)
	{
		if (shape[i]->getShapeCode() == 1)
		{
			cout << fixed;
			cout << "Rectangle: Width=" <<setprecision(2) << shape[i]->getWidth() << ", Height="
			<< shape[i]->getHeight() << " => Area=" << shape[i]->Area() 
			<< ", Perimeter="<< shape[i]->Perimeter() << endl;
		}
		else if (shape[i]->getShapeCode() == 2)
		{
			cout << fixed;
			cout << "Circle: Radius=" << shape[i]->getRadius() << " => Area=" 
			<< setprecision(2) << shape[i]->Area() << ", Perimeter=" << setprecision(2) 
			<< shape[i]->Perimeter() << endl;
		}
		else if (shape[i]->getShapeCode() == 3)
		{
			cout << fixed;
			cout<<"Triangle: A=" << setprecision(0) << shape[i]->getA() << ", B=" << shape[i]->getB() << ", C="
				<<shape[i]->getC() << " => Area=" << shape[i]->Area() 
				<< ", Perimeter="<< shape[i]->Perimeter() << endl;
		}
	}

	cin.get();
	return 0;
}