#include "shape.h"

TRIANGLE::TRIANGLE(float a, float b, float c) {
	this->_a = a;
	this->_b = b;
	this->_c = c;
}


float TRIANGLE::Area()
{
	float p = (this->_a + this->_b + this->_c) / 2;
	float area = sqrt(p * (p - this->_a) * (p - this->_b) * (p - this->_c));
	return area;
}
float TRIANGLE::Perimeter() {
	float perimeter = _a + _b + _c;
	return perimeter;
}

string TRIANGLE::shapeInfor()
{
	stringstream builder;
	builder << "Triangle: A=" << getA() << ", B=" << getB() << ", C="
		<< getC() << " => Area=" << Area()
		<< ", Perimeter=" << Perimeter();
	string result = builder.str();
	return result;
}

RECTANGLE::RECTANGLE(float width, float height) {
	this->_width = width;
	this->_height = height;
}



float RECTANGLE::Area() {
	float area = this->_width * this->_height;
	return area;
}
float RECTANGLE::Perimeter() {
	float perimeter = (this->_width + this->_height) * 2;
	return perimeter;
}

string RECTANGLE::shapeInfor()
{
	stringstream builder;
	builder << "Rectangle: Width=" << this->getWidth() << ", Height="
		<< this->getHeight() << " => Area=" << this->Area()
		<< ", Perimeter=" << this->Perimeter();
	string result = builder.str();
	return result;
}


CIRCLE::CIRCLE(float radius)
{
	this->_radius = radius;
}

float CIRCLE::Area() {
	float area = this->_radius * this->_radius * 3.14;
	return area;
}
float CIRCLE::Perimeter() {
	float perimeter = 2 * 3.14 * this->_radius;
	return perimeter;
}

string CIRCLE::shapeInfor()
{
	stringstream builder;
	builder << "Circle: Radius=" << getRadius() << " => Area="
		<< Area() << ", Perimeter="
		<< Perimeter();
	string result = builder.str();
	return result;
}


//Object Pool design
SHAPEFACTORY::SHAPEFACTORY()
{
	auto shape01 = make_shared<RECTANGLE>();
	auto shape02 = make_shared<TRIANGLE>();
	auto shape03 = make_shared<CIRCLE>();

	_pool.push_back(shape01);
	_pool.push_back(shape02);
	_pool.push_back(shape03);

}

shared_ptr<SHAPEFACTORY> SHAPEFACTORY::instance()
{
	if (_instance == NULL)
	{
		auto temp = new  SHAPEFACTORY();
		_instance = make_shared <SHAPEFACTORY>(*temp);
	}
	return _instance;
}


void SHAPEFACTORY::displayAllShape()
{
	for (int i = 0; i < _pool.size(); i++)
	{
		shared_ptr<SHAPE> item = _pool[i];
		cout << item->shapeInfor() << endl;
	}
}