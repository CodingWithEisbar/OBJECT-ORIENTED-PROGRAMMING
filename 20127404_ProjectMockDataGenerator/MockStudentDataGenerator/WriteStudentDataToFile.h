#ifndef _WRITESTUDENTDATA_H_
#define _WRITESTUDENTDATA_H_

#include <fstream>

#include "Student.h"
#include "supportStudentInputInfor.h"
using namespace std;


class WriteStudentDataToFile {
private:
	string _connectionString;
public:
	WriteStudentDataToFile(string);
public:
	void writeAll(vector<STUDENT> data);
};


#endif
