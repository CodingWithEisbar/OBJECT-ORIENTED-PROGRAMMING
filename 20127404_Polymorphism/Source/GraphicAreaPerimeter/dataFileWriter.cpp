#include "dataFileWriter.h"


shapeDataWriter::shapeDataWriter(std::string connectionString)
{
	this->_connectionString = connectionString;
}
void shapeDataWriter::writeShapeDataToFile(std::vector<std::shared_ptr<Shape>> data)
{
	std::ofstream output;
	output.open(_connectionString, std::ios::out);
	for (int i = 0; i < data.size(); i++)
	{
		std::shared_ptr<Shape> pointer = data[i];
		int shapeCode = pointer->getShapeCode();
		if (shapeCode == 1) {
			output << "Rectangle: Width= " << pointer->getWidth() << ", Height=" << pointer->getHeight();
			output << std::endl;
		}
		else if (shapeCode == 2)
		{
			output << "Triangle: A= " << pointer->getA() << ", B=" << pointer->getB() 
				<< ", C=" << pointer->getC();
			output << std::endl;
		}
		else if (shapeCode == 3) {
			output << "Circle: Radius= " << pointer->getRadius();
			output << std::endl;
		}
	}
	output.close();
}