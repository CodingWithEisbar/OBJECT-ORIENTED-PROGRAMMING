//20127404
//NGUYEN TRUNG NGUYEN
//20CLC07


#include "employee.h"
#include "FileDataReader.h"
#include "employeeFactory.h"


int main() {
	FILE_DATA_READER input("November2021.txt");
	shared_ptr<EMPLOYEE_FACTORY> employee_factory = EMPLOYEE_FACTORY::instance();

	vector<shared_ptr<EMPLOYEE>> pool = input.getAll();
	employee_factory->setAllData(pool);
	employee_factory->displayAll();
	
	cin.get();
	return 0;
}