#include "shape.h"


Triangle::Triangle(float a, float b, float c) {
	this->_a = a;
	this->_b = b;
	this->_c = c;
}
void Triangle::setRandomComponents(int left, int right)
{
	this->_a = _rfg.next(left, right);
	this->_b = _rfg.next(left, right);
	this->_c = _rfg.next(left, right);
}

float Triangle::Area()
{
	float p = (this->_a + this->_b + this->_c) / 2;
	float area = sqrt(p*(p- this->_a)*(p- this->_b)*(p- this->_c));
	return area;
}
float Triangle::Perimeter() {
	float perimeter = _a + _b + _c;
	return perimeter;
}



Rectangle::Rectangle(float width, float height) {
	this->_width = width;
	this->_height = height;
}
void Rectangle::setRandomComponents(int left, int right) {
	this->_width = _rfg.next(left, right);
	this->_height = _rfg.next(left, right);
}


float Rectangle::Area() {
	float area = this->_width * this->_height;
	return area;
}
float Rectangle::Perimeter() {
	float perimeter = (this->_width + this->_height) * 2;
	return perimeter;
}



Circle::Circle(float radius)
{
	this->_radius = radius;
}
void Circle::setRandomComponents(int left, int right) {
	this->_radius = _rfg.next(left, right);
}
float Circle::Area() {
	float area = this->_radius * this->_radius * 3.14;
	return area;
}
float Circle::Perimeter() {
	float perimeter = 2 * 3.14 * this->_radius;
	return perimeter;
}
