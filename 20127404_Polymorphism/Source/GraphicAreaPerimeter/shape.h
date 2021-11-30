#ifndef _SHAPE_H_
#define  _SHAPE_H_
#include "RandomFloatGenerator.h"
#include <cmath>

class Shape {
protected:
	int _shapeCode;
	RandomFloatGenerator _rfg;
public:
	Shape() {

	}
public:
	virtual void setRandomComponents(int left, int right){}
	virtual float Area() {
		return 0;
	}
	virtual float Perimeter() {
		return 0;
	}
public:
	virtual void setShapeCode(int)
	{
		_shapeCode = 0;
	}
	virtual float getA() { return 0; }
	virtual float getB() { return 0; }
	virtual float getC() { return 0; }
	virtual float getWidth() { return 0; }
	virtual float getHeight() { return 0; }
	virtual float getRadius() { return 0; }
	virtual int getShapeCode() { return 0; }
public:
	virtual void setA(float) {}
	virtual void setB(float) {}
	virtual void setC(float) {}
	virtual void setWidth(float) {}
	virtual void setHeight(float) {}
	virtual void setRadius(float) {}
};


class Triangle : public Shape {
private:
	float _a;
	float _b;
	float _c;
public:
	Triangle() {}
	Triangle(float a, float b, float c);
	void setRandomComponents(int left, int right);
	void setShapeCode(int code) { _shapeCode = code; }
	int getShapeCode() { return _shapeCode; }
public:
	void setA(float value) { this->_a = value; }
	void setB(float value) { this->_b = value; }
	void setC(float value) { this->_c = value; }
public:
	float getA() { return _a; }
	float getB() { return _b; }
	float getC() { return _c; }
public:
	float Area();
	float Perimeter();
};

class Rectangle : public Shape {
private:
	float _width, _height;
public:
	Rectangle() {}
	Rectangle(float width, float height);
	void setRandomComponents(int left, int right);
	void setShapeCode(int code) { _shapeCode = code; }
	int getShapeCode() { return _shapeCode; }
public:
	void setWidth(float value) { this->_width = value; }
	void setHeight(float value) { this->_height = value; }
public:
	float getWidth() { return _width; }
	float getHeight() { return _height; }
public:
	float Area();
	float Perimeter();
};

class Circle : public Shape {
private:
	float _radius;
public:
	Circle() {}
	Circle(float radius);
	void setRandomComponents(int left, int right);
	void setShapeCode(int code) { _shapeCode = code; }
	int getShapeCode() { return _shapeCode; }
public:
	void setRadius(float value) { this->_radius = value; }
public:
	float getRadius() { return _radius; }
public:
	float Area();
	float Perimeter();
};
#endif