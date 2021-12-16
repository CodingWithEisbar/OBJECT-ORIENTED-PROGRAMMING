#include "dataFileReader.h"

dataFileReader::dataFileReader(std::string connectionString) {
	this->_connectionString = connectionString;

}

std::vector<std::shared_ptr<SHAPE>> dataFileReader::getAll()
{
	std::ifstream data;
	data.open(_connectionString);
	std::vector<std::shared_ptr<SHAPE>> shape_collection;
	if (data.is_open())
	{
		while (!data.eof())
		{
			std::string buffer;
			getline(data, buffer);
			std::string shape_name;
			std::string width_str, height_str, a_str, b_str, c_str, radius_str;
			std::stringstream getShapeName(buffer);
			getline(getShapeName, shape_name, ':');
			if (shape_name == "Rectangle")
			{
				SHAPE* shape_ptr = new RECTANGLE();
				width_str = buffer.substr(buffer.find_first_of("=") + 1);
				height_str = buffer.substr(buffer.find_last_of("=") + 1);
				//Covert value to double
				double width = stod(width_str);
				double height = stod(height_str);
				//Add to shape list
				shape_ptr->setShapeCode(1);
				shape_ptr->setWidth(width);
				shape_ptr->setHeight(height);
				std::shared_ptr<SHAPE> smart_ptr(shape_ptr);
				shape_collection.push_back(smart_ptr);
			}
			else if (shape_name == "Circle")
			{
				SHAPE* shape_ptr = new CIRCLE();
				radius_str = buffer.substr(buffer.find_first_of("=") + 1);
				//Convert to double
				double radius = stod(radius_str);
				//Add to shape list
				shape_ptr->setShapeCode(2);
				shape_ptr->setRadius(radius);
				std::shared_ptr<SHAPE> smart_ptr(shape_ptr);
				shape_collection.push_back(smart_ptr);
			}
			else if (shape_name == "Triangle")
			{
				SHAPE* shape_ptr = new TRIANGLE();
				a_str = buffer.substr(buffer.find_first_of("=") + 1);
				getline(getShapeName, b_str, '=');
				getline(getShapeName, b_str, '=');
				getline(getShapeName, b_str, '=');
				c_str = buffer.substr(buffer.find_last_of("=") + 1);

				//Convert to double
				double a = stod(a_str);
				double b = stod(b_str);
				double c = stod(c_str);
				//Add to shape list
				shape_ptr->setShapeCode(3);
				shape_ptr->setA(a);
				shape_ptr->setB(b);
				shape_ptr->setC(c);
				std::shared_ptr<SHAPE> smart_ptr(shape_ptr);
				shape_collection.push_back(smart_ptr);
			}
		}
	}
	data.close();
	return shape_collection;

}