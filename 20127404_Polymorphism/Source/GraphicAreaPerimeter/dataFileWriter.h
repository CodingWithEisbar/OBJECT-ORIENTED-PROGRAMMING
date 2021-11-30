#ifndef _FILEWRITER_H_
#define _FILEWRITER_H_

#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "shape.h"

class shapeDataWriter {
private:
	std::string _connectionString;
public:
	shapeDataWriter(std::string connectionString);
public:
	void writeShapeDataToFile(std::vector<std::shared_ptr<Shape>>);

};


#endif