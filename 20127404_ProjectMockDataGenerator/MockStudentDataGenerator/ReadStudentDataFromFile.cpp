#include "ReadStudentDataFromFile.h"

vector<string> spliter(string original, string delete_sample)
{
	vector<string> after_split;
	unsigned long long start = 0;
	unsigned long long end = original.find(delete_sample);
	while (end != -1)
	{
		after_split.push_back(original.substr(start, end - start));
		start = end + delete_sample.size();
		end = original.find(delete_sample, start);
	}
	after_split.push_back(original.substr(start, end - start));
	return after_split;
}


ReadStudentData::ReadStudentData(string connectionString)
{
	_connectionString = connectionString;
}

vector<STUDENT> ReadStudentData::getAll()
{
	vector<STUDENT> result;
	ifstream input_file;
	input_file.open(_connectionString);
	string buffer;
	while (!input_file.eof())
	{
		STUDENT sample;
		InputStudentInformation _support;
		string stu_name, stu_gpa, stu_ID, stu_phone, stu_email, stu_dob, stu_address;
		
		//Get student ID and name
		getline(input_file, buffer);
		stringstream student_ID_name(buffer);
		getline(student_ID_name, stu_ID, ':');
		getline(student_ID_name, stu_ID, '-');
		getline(student_ID_name, stu_name, '-');
		getline(student_ID_name, stu_name);


		//Get student phone number and GPA
		getline(input_file, buffer);
		stringstream student_gpa_phone(buffer);
		getline(student_gpa_phone, stu_gpa, '=');
		getline(student_gpa_phone, stu_gpa, ',');
		getline(student_gpa_phone, stu_phone, '=');
		getline(student_gpa_phone, stu_phone);
		//Convert GPA to double
		auto convert_GPA = _support.stringToGPA(stu_gpa);
		double GPA = get<3>(convert_GPA);

		//Get student email
		getline(input_file, buffer);
		stringstream student_email(buffer);
		getline(student_email, stu_email, '=');
		getline(student_email, stu_email);

		getline(input_file, buffer);
		stringstream student_dob(buffer);
		getline(student_dob, stu_dob, '=');
		getline(student_dob, stu_dob);
		auto convert_DOB = _support.stringToDOBCovertBack(stu_dob);
		DATE DOB = get<3>(convert_DOB);

		//Get student home address
		getline(input_file, buffer);
		stringstream student_address(buffer);
		getline(student_address, stu_address, '=');
		getline(student_address, stu_address);

		//Set all value to Student class
		sample.setStudentID(stu_ID);
		sample.setStudentFullName(stu_name);
		sample.setStudentGPA(GPA);
		sample.setStudentDOB(DOB);
		sample.setStudentEmailAddress(stu_email);
		sample.setStudentHomeAddress(stu_address);
		sample.setStudentPhoneNumber(stu_phone);

		//Put this student into list
		result.push_back(sample);
	}
	return result;
}