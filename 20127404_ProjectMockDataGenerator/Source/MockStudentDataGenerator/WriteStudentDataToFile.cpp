#include "WriteStudentDataToFile.h"

WriteStudentDataToFile::WriteStudentDataToFile(string connectionString)
{
	_connectionString = connectionString;
}

void WriteStudentDataToFile::writeAll(vector<STUDENT> data)
{
	ofstream output;
	try {
		output.open(_connectionString, ios::trunc);
	}
	catch (exception ex)
	{
		throw runtime_error("Cannot open the file!!");
		return;
	}
	output << "Student: " << data[0].getStudentID() << " - " << data[0].getStudentFullName();
	output << endl;
	output << "\tGPA= " << data[0].getStudentGPA() << ", Telephone=" << data[0].getStudentPhoneNumber();
	output << endl;
	output << "\tEmail=" << data[0].getStudentEmailAddress();
	output << endl;
	output << "\tDOB=" << data[0].getStudentDOB().day << "/" << data[0].getStudentDOB().month << "/"<< data[0].getStudentDOB().year;
	output << endl;
	output << "\tAddress=" << data[0].getStudentHomeAddress();
	for (int i = 1; i < data.size(); i++)
	{
		output << endl << "Student: " << data[i].getStudentID() << " - " << data[i].getStudentFullName();
		output << endl;
		output << "\tGPA= " << data[i].getStudentGPA() << ", Telephone=" << data[i].getStudentPhoneNumber();
		output << endl;
		output << "\tEmail=" << data[i].getStudentEmailAddress();
		output << endl;
		output << "\tDOB=" << data[i].getStudentDOB().day << "/" << data[i].getStudentDOB().month << "/" << data[i].getStudentDOB().year;
		output << endl;
		output << "\tAddress=" << data[i].getStudentHomeAddress();
	}
	output.close();
}