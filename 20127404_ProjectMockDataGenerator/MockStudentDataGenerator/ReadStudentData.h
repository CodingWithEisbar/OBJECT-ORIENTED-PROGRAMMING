#ifndef _READSTUDENT_H_
#define _READSTUDENT_H_


#include <string>
#include <vector>
#include <regex>
#include <tuple>
#include <fstream>

#include "Student.h"
using namespace std;

class ReadStudentData {
private:
	string _connectionString;
public:
	ReadStudentData(string);
public: 
	vector<STUDENT> getAll();
};

#endif
