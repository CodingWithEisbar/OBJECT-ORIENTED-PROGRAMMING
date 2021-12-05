#ifndef _RANDOMSTUDENT_H_
#define _RANDOMSTUDENT_H_

#include <sstream>
#include <regex>
#include <algorithm>

#include "Student.h"
#include "RandomIntegerGenerator.h"
#include "RandomFloatGenerator.h"
#include "supportStudentInputInfor.h"


class RandomStudentGenerator {
private:
	RandomFloatGenerator _rfg;
	RandomIntegerGenerator _rig;
private: //Student's name database
	vector<string> _firstName = { "Nguyen", "Tran", "Le", "Dang", "Trinh", "Mai", "Pham", "Doan", "Vo", "Ho" };
	vector<string> _middleName = { "Hoai", "Van", "Trung", "Thuy", "Thanh", "Vinh", "Anh", "Hung", "Cao", "Quynh" };
	vector<string> _lastName = { "Truong", "Ki", "Khanh", "Phat", "Lan", "Nhi", "Quan", "Tu", "Khoi", "Tam" };
private: //Address database
	vector<string> _street = { //Phường 4, Quận 5 ( 0 - 3 )
								"Tran Phu", "An Duong Vuong", "Tran Binh Trong", "Nguyen Van Cu"
								// Phường 10, Quận 5 ( 4 - 8 )
								, "Tran Hung Dao", "Pham Don", "Tan Hang", "Tan Da", "Vo Van Kiet",
								//Phường Phú Thạnh, Quận Tân Phú ( 9 - 16 )
								"Luy Ban Bich", "Thoai Ngoc Hau", "Nguyen Son", "Thach Lam", "Tran Thu Do",
								"Le Cao Lang", "Tran Quang Co",  "Hien Vuong",
								//Phường Bến Nghé, Quận 1 ( 17 - 25 )
								"Ton Duc Thang", "Nguyen Du", "Hai Ba Trung", "Le Thanh Ton", "Le Duan",
								"Ly Tu Trong", "Thi Sach", "Cao Ba Quat", "Dong Khoi"
								//Phường 1 Quận 3 ( 26 - 29 )
								"Dien Bien Phu", "Nguyen Thien Thuat", "Ly Thai To", "Nguyen Dinh Chieu"
	};
	vector<string> _ward = { "4", "10", "Phu Thanh", "Ben Nghe", "1"};
	vector<string> _district{ "5", "Tan Phu", "1", "3"};
	vector<string> _city = { "Ho Chi Minh City" };
//private://DOB database
//	vector<int> _day = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
//						21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
//	vector<int> _month = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	vector<int> _year = { 1999, 2000, 2001, 2002 };
private://Phone-number database ( 0 - 6 )
	vector<string> _providerCode = { "086", "096", "088", "089", "090", "079", "093" };
public:
	RandomStudentGenerator();
public:
	string setRandomID();
	string setRandomName();
	string setRandomAddress();
	string setRandomPhoneNumber();
	string setRandomDOB();
	float setRandomGPA();
public:
	STUDENT setRandomStudent();
};


bool isNumber(string buffer);

#endif
