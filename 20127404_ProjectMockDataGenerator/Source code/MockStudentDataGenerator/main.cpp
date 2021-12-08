//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>
#include <memory>

#include "RandomIntegerGenerator.h"
#include "RandomFloatGenerator.h"
#include "RandomStudentInformationGenerator.h"
#include "ReadStudentDataFromFile.h"
#include "WriteStudentDataToFile.h"
#include "Student.h"
#include "supportStudentInputInfor.h"
using namespace std;

int main() {
	int choice, file_save_flag =0;
	ReadStudentData _readStudentData("students.txt");
	vector<STUDENT> student_data = _readStudentData.getAll();
	
	while (true)
	{
		cout << endl << "\tSTUDENT MANAGER";
		cout << endl << "------------------------------------------------------------";
		cout << endl << "1. Random n student.";
		cout << endl << "2. Write all student data to file.";
		cout << endl << "3. Manual input new student.";
		cout << endl << "4. Calculate average GPA.";
		cout << endl << "5. Print out all the students that have a GPA greater than average GPA.";

		cout << endl << "0. Exit.";
		cout << endl << "------------------------------------------------------------";
		cout << endl << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) //1. Random n student.
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
			cout << endl << "Random " << n << " students successfully!";
		}
		else if (choice == 2) //2. Write all student data to file.
		{
			WriteStudentDataToFile _writeToFile("students.txt");
			try {
				_writeToFile.writeAll(student_data);
				cout << endl << "Data write to file successfully!!!";
			}
			catch (runtime_error ex) {
				cout << ex.what() << endl;
			}
			file_save_flag = 1;
		}
		else if (choice == 3) //3. Manual input new student.
		{
			STUDENT input_manual = inputStudent();
			student_data.push_back(input_manual);
			cout << endl << "\t- Student information input successfully! -";
			file_save_flag = 0;
		}
		else if (choice == 4) //4. Calculate average GPA.
		{
			double averageGPA = getStudentsAverageGPA(student_data);
			cout << endl << "Average GPA is: " << averageGPA << endl;
		}
		else if (choice == 5) //5. Print out all the students that have a GPA greater than average GPA.
		{
			double averageGPA = getStudentsAverageGPA(student_data);
			cout << endl << "List of students who have GPA greater than the average GPA(" << averageGPA << "): ";
			for (int i = 0; i < student_data.size(); i++)
			{
				if (student_data[i].getStudentGPA() > averageGPA)
				{
					cout << endl;
					cout << student_data[i].getStudentID() << " - "
						<< student_data[i].getStudentFullName() << ", GPA:" << student_data[i].getStudentGPA();
				}
			}
			cout << endl;

		}
		else if (choice == 0) //0. Exit
		{
			//This condition is used in case user forget to save data from file
			if (file_save_flag == 0) {
				int save_choice;
				cout << endl << "\t-----------------------------------------------------------------";
				cout << endl << "\tYou haven't save your data yet. Do you want to save it?";
				cout << endl << "\t1. Save";
				cout << endl << "\t2. Don't save.";
				cout << endl << "\t-----------------------------------------------------------------";
				cout << endl << "Your choice: ";
				cin >> save_choice;
				if (save_choice == 1) {
					WriteStudentDataToFile _writeToFile("students.txt");
					try {
						_writeToFile.writeAll(student_data);
						cout << endl << "Data write to file successfully!!!";
						break;
					}
					catch (runtime_error ex) {
						cout << ex.what() << endl;
					}

				}
				else if (save_choice == 2) {
					break;
				}
			}
			else {
				break;
			}
		}
		else {
			cout << endl << "\tInvalid choice!! Please re-enter it!!";
			continue;
		}

	}



	return 0;
}