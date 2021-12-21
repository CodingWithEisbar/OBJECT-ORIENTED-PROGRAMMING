#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

#include "employee.h"
#include "employeeFactory.h"
using namespace std;


class FILE_DATA_READER {
private:
	string _connectionString;
public:
	FILE_DATA_READER(string);
	vector <shared_ptr<EMPLOYEE>> getAll();
};

#endif