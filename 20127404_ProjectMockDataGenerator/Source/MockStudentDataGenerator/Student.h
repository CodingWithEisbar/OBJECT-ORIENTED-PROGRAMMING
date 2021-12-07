#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <vector>
#include <string>
using namespace std;

struct DATE {
	int day, month, year;
};

class STUDENT {
private:
	string _ID;
	string _fullName;
	double _GPA;
	string _phoneNumber;
	string _emailAddress;
	DATE _DOB;
	string _homeAddress;
public:
	STUDENT();
	STUDENT(string, string, double, string, string, DATE, string);
public:
	string getStudentID() { return _ID; }
	string getStudentFullName() { return _fullName; }
	double getStudentGPA() { return _GPA; }
	string getStudentPhoneNumber() { return _phoneNumber; }
	string getStudentEmailAddress() { return _emailAddress; }
	DATE getStudentDOB() { return _DOB; }
	string getStudentHomeAddress() { return _homeAddress; }
public:
	void setStudentID(string ID) { _ID = ID; }
	void setStudentFullName(string fullName) { _fullName = fullName; }
	void setStudentGPA(double GPA) { _GPA = GPA; }
	void setStudentPhoneNumber(string phoneNumber) { _phoneNumber = phoneNumber; }
	void setStudentEmailAddress(string emailAddress) { _emailAddress = emailAddress; }
	void setStudentDOB(DATE DOB);
	void setStudentHomeAddress(string homeAdderss) { _homeAddress = homeAdderss; }

};


double getStudentsAverageGPA(vector<STUDENT> data);


#endif 
