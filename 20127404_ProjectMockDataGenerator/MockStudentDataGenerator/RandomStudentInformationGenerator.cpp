#include "RandomStudentInformationGenerator.h"

RandomStudentGenerator::RandomStudentGenerator()
{
	//Default constructor
}

bool isNumber(string buffer)
{
	string pattern = "\\b\\d+\\b";
	regex numberpattern(pattern);
	bool result = regex_match(buffer, numberpattern);
	return result;
}



STUDENT RandomStudentGenerator::setRandomStudent()
{
	STUDENT student;
	//Generate random student ID:
	stringstream ID_builder;
	ID_builder << "2012" << _rig.next(1000, 9999);
	string studentID = ID_builder.str();
	student.setStudentID(studentID);

	//Generate random name
	int first, middle, last;
	first = this->_rig.next();
	middle = this->_rig.next();
	last = this->_rig.next();
	string first_name = this->_firstName[first];
	string middle_name = this->_middleName[middle];
	string last_name = this->_lastName[last];
	stringstream name_builder;
	name_builder << this->_firstName[first] << " " << this->_middleName[middle] 
				 << " " << this->_lastName[last]; 
	string fullName = name_builder.str();
	student.setStudentFullName(fullName);

	//Generate random email
	stringstream email_builder;
	char first_name_letter = first_name[0] + 32;
	char middle_name_letter = middle_name[0] + 32;
	for_each(last_name.begin(), last_name.end(), [](char& c) {
		c = ::tolower(c);
	});
	email_builder << first_name_letter << middle_name_letter << last_name << "@student.hcmus.edu.vn";
	string email = email_builder.str();
	student.setStudentEmailAddress(email);

	//Generate random phone number
	stringstream phone_builder;
	int randomProviderCode = _rig.next(0, 6);
	phone_builder << _providerCode[randomProviderCode] << _rig.next(1, 9) << "-" 
				  << _rig.next(100, 999) << "-" << _rig.next(100, 999);
	string phoneNumber = phone_builder.str();
	student.setStudentPhoneNumber(phoneNumber);

	//Generate random home address
	stringstream address_builder;
	int street_index = _rig.next(0,29);
	int ward_index, district_index, city_index;
	if (street_index >= 0 && street_index <= 3)
	{
		ward_index = 0;
		district_index = 0;
		city_index = 0;
	}
	else if (street_index >= 4 && street_index <= 8)
	{
		ward_index = 1;
		district_index = 0;
		city_index = 0;
	}
	else if (street_index >= 9 && street_index <= 16)
	{
		ward_index = 2;
		district_index = 1;
		city_index = 0;
	}
	else if (street_index >= 17 && street_index <= 25)
	{
		ward_index = 3;
		district_index = 2;
		city_index = 0;
	}
	else if (street_index >= 26 && street_index <= 29)
	{
		ward_index = 4;
		district_index = 3;
		city_index = 0;
	}
	string street_str, ward_str, district_str, city_str;
	street_str = _street[street_index];
	ward_str = _ward[ward_index];
	district_str = _district[district_index];
	city_str = _city[city_index];
	if (isNumber(ward_str))
	{
		if (isNumber(district_str))
		{
			address_builder << _rig.next(100) << " " 
			<< street_str << ", Ward " << ward_str << ", District" << district_str << ", " << city_str;
		}
		else {
			address_builder << _rig.next(100) << " "
			<< street_str << ", Ward " << ward_str << ", " << district_str << " District, " << city_str;
		}
	}
	else {
		if (isNumber(district_str))
		{
			address_builder << _rig.next(100) << " "
				<< street_str << ", " << ward_str << " Ward, District" << district_str << ", " << city_str;
		}
		else {
			address_builder << _rig.next(100) << " "
				<< street_str << ", " << ward_str << " Ward, " << district_str << " District, " << city_str;
		}
	}
	string homeAddress = address_builder.str();
	student.setStudentHomeAddress(homeAddress);

	//Generate random GPA
	double GPA = _rfg.next(0, 10);
	student.setStudentGPA(GPA);

	//Generate random DOB
	DATE DOB;
	DOB.year = _rig.next(1900, 2003);
	DOB.month = _rig.next(1, 12);
	int maxDayOfMonth = maxDayDeterminator(DOB);
	DOB.day = _rig.next(1, maxDayOfMonth);
	student.setStudentDOB(DOB);

	return student;
}