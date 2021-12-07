#include "ReadStudentDataFromFile.h"

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
	if (input_file.is_open()) {
		while (!input_file.eof())
		{
			InputStudentInformation _support;
			string stu_name, stu_gpa, stu_ID, stu_phone, stu_email, stu_dob, stu_address;
		
			//Get student ID and name
			getline(input_file, buffer);
			stringstream student_ID_name(buffer);
			getline(student_ID_name, stu_ID, ' ');
			getline(student_ID_name, stu_ID, ' ');
			stu_name = buffer.substr(buffer.find_first_of("-") + 2);

			//Get student phone number and GPA
			getline(input_file, buffer);
			int comma = buffer.find_first_of(",");
			int equal = buffer.find_first_of("=");
			stu_gpa = buffer.substr(equal + 1, (comma - equal) - 1);

			equal = buffer.find_last_of("=");
			stu_phone = buffer.substr(equal + 1, buffer.size()-1);
			
			//Get student email
			getline(input_file, buffer);
			stu_email = buffer.substr(buffer.find_first_of("=") + 1, buffer.size() - 1);

			//Get student DOB
			getline(input_file, buffer);
			stu_dob = buffer.substr(buffer.find_first_of("=") + 1, buffer.size() - 1);
		

			//Get student home address
			getline(input_file, buffer);
			stu_address = buffer.substr(buffer.find_first_of("=") + 1, buffer.size() - 1);
			
			//Convert DOB to struct DATE
			auto convert_DOB = _support.stringToDOBCovertBack(stu_dob);
			DATE DOB = get<3>(convert_DOB);
			//Convert GPA to double
			double GPA = stod(stu_gpa);

			//Set all value to Student class
			STUDENT sample;
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
	}
	input_file.close();
	return result;
}