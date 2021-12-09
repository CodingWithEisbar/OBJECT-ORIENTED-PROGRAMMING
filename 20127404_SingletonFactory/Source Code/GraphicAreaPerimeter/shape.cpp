#include "shape.h"


TRIANGLE::TRIANGLE(float a, float b, float c) {
	this->_a = a;
	this->_b = b;
	this->_c = c;
}


float TRIANGLE::Area()
{
	float p = (this->_a + this->_b + this->_c) / 2;
	float area = sqrt(p*(p- this->_a)*(p- this->_b)*(p- this->_c));
	return area;
}
float TRIANGLE::Perimeter() {
	float perimeter = _a + _b + _c;
	return perimeter;
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
