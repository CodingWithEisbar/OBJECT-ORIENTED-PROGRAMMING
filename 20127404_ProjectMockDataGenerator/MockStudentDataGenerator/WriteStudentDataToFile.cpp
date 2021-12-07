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
	for (int i = 0; i < data.size(); i++)
	{
		output << "Student: " << data[i].getStudentID() << " - " << data[i].getStudentFullName();
		output << endl;
		output << "GPA= " << data[i].getStudentGPA() << ", Telephone=" << data[i].getStudentPhoneNumber();
		output << endl;
		output << "Email=" << data[i].getStudentEmailAddress();
		output << endl;
		output << "DOB=" << data[i].getStudentDOB().day << "/" << data[i].getStudentDOB().month << "/"<< data[i].getStudentDOB().year;
		output << endl;
		output << "Address=" << data[i].getStudentHomeAddress();
	}
	output.close();
}