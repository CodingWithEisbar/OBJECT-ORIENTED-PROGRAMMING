//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>

#include "RandomIntegerGenerator.h"
#include "RandomFloatGenerator.h"
#include "RandomStudentInformationGenerator.h"
#include "ReadStudentDataFromFile.h"
#include "WriteStudentDataToFile.h"
#include "Student.h"
#include "supportStudentInputInfor.h"
using namespace std;

int main() {
	int choice;
	ReadStudentData _readStudentData("students.txt");
	vector<STUDENT> student_data = _readStudentData.getAll();
	while (true)
	{
		cout << endl << "\tSTUDENT MANAGER";
		cout << endl << "------------------------------------------------------------";
		cout << endl << "1. Random n student.";
		cout << endl << "2. Write all student data to file";
		cout << endl << "3. Manual input new student.";
		cout << endl << "4. Calculate average GPA.";
		cout << endl << "5. Print out all the students that have a GPA greater than average GPA.";

		cout << endl << "0. Exit.";
		cout << endl << "------------------------------------------------------------";
		cout << endl << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			//Generate randomly a number n in the range of[5, 10]
			RandomIntegerGenerator _rig;
			RandomStudentGenerator _rsg;
			int n = _rig.next(5, 10);
			for (int i = 0; i < n; i++)
			{
				STUDENT temp = _rsg.setRandomStudent();
				student_data.push_back(temp);
			}
		}
		else if (choice == 2)
		{
			WriteStudentDataToFile _writeToFile("students.txt");
			try {
				_writeToFile.writeAll(student_data);
				cout << endl << "Data write to file successfully!!!";
			}
			catch (runtime_error ex) {
				cout << ex.what() << endl;
			}
		}
		else if (choice == 3)
		{
			
		}
		else if (choice == 4)
		{

		}
		else if (choice == 5)
		{

		}
		else if (choice == 0)
		{
			break;
		}
		else {
			cout << endl << "\tInvalid choice!! Please re-enter it!!";
			continue;
		}

	}



	return 0;
}