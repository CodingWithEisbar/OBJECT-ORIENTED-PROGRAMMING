#ifndef _DATAFILEREADER_H_
#define _DATAFILEREADER_H_

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include "shape.h"

class dataFileReader {
private:
	std::string _connectionString;
public:
	dataFileReader(std::string);
public:
	std::vector<std::shared_ptr<SHAPE>> getAll();
};


#endif
