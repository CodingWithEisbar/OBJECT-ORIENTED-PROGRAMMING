#include "FileDataReader.h"

FILE_DATA_READER::FILE_DATA_READER(string connectionString)
{
	_connectionString = connectionString;
}

vector<shared_ptr<EMPLOYEE>> FILE_DATA_READER::getAll()
{
	vector<shared_ptr<EMPLOYEE>> employee_list;
	ifstream input;
	input.open(_connectionString, ios::in);
	if (input.is_open())
	{
		while (!input.eof())
		{
			string buffer;
			getline(input, buffer);
			string employeeType, employeeName, paymentString, totalWorkString, paymentPerEmployeeString;
			stringstream ss(buffer);
			getline(ss, employeeType, ':');
			if (employeeType == "DailyEmployee")
			{
				EMPLOYEE* employee_ptr = new DAILY_EMPLOYEE();
				// Get employee name
				getline(ss, employeeName, ':');
				// Get employee payments
				getline(input, buffer);
				int dollar_symbol = buffer.find_first_of("$");
				int equal_symbol = buffer.find_first_of("=");
				paymentString = buffer.substr(equal_symbol + 1, (dollar_symbol - equal_symbol) - 1);
				// Get employee total days
				equal_symbol = buffer.find_last_of("=");
				totalWorkString = buffer.substr(equal_symbol + 1, buffer.size() - 1);

				//Set all to class
				int paymentInteger = stoi(paymentString);
				int totalWorksInteger = stoi(totalWorkString);
				employee_ptr->setName(employeeName);
				employee_ptr->setDailyPayment(paymentInteger);
				employee_ptr->setTotalDays(totalWorksInteger);
				shared_ptr<EMPLOYEE> smart_ptr(employee_ptr);
				employee_list.push_back(smart_ptr);

			}
			else if (employeeType == "HourlyEmployee")
			{
				EMPLOYEE* employee_ptr = new HOURLY_EMPLOYEE();// Get employee name
				getline(ss, employeeName, ':');
				// Get employee payments
				getline(input, buffer);
				int dollar_symbol = buffer.find_first_of("$");
				int equal_symbol = buffer.find_first_of("=");
				paymentString = buffer.substr(equal_symbol + 1, (dollar_symbol - equal_symbol) - 1);
				// Get employee total days
				equal_symbol = buffer.find_last_of("=");
				totalWorkString = buffer.substr(equal_symbol + 1, buffer.size() - 1);

				//Set all to class
				int paymentInteger = stoi(paymentString);
				int totalWorksInteger = stoi(totalWorkString);
				employee_ptr->setName(employeeName);
				employee_ptr->setHourlyPayment(paymentInteger);
				employee_ptr->setTotalHours(totalWorksInteger);
				shared_ptr<EMPLOYEE> smart_ptr(employee_ptr);
				employee_list.push_back(smart_ptr);
			}
			else if (employeeType == "ProductEmployee")
			{
				EMPLOYEE* employee_ptr = new PRODUCT_EMPLOYEE();
				// Get employee name
				getline(ss, employeeName, ':');
				// Get employee payments
				getline(input, buffer);
				int dollar_symbol = buffer.find_first_of("$");
				int equal_symbol = buffer.find_first_of("=");
				paymentString = buffer.substr(equal_symbol + 1, (dollar_symbol - equal_symbol) - 1);
				// Get employee total days
				equal_symbol = buffer.find_last_of("=");
				totalWorkString = buffer.substr(equal_symbol + 1, buffer.size() - 1);

				//Set all to class
				int paymentInteger = stoi(paymentString);
				int totalWorksInteger = stoi(totalWorkString);
				employee_ptr->setName(employeeName);
				employee_ptr->setPaymentPerProduct(paymentInteger);
				employee_ptr->setTotalProducts(totalWorksInteger);
				shared_ptr<EMPLOYEE> smart_ptr(employee_ptr);
				employee_list.push_back(smart_ptr);
			}
			else if (employeeType == "Manager")
			{
				EMPLOYEE* employee_ptr = new MANAGER();
				// Get employee name
				getline(ss, employeeName, ':');
				// Get employee payments
				getline(input, buffer);
				int dollar_symbol = buffer.find_first_of("$");
				int equal_symbol = buffer.find_first_of("=");

				paymentString = buffer.substr(equal_symbol + 1, (dollar_symbol - equal_symbol) - 1);
				// Get employee total days

				stringstream getTotalWorks(buffer);
				getline(getTotalWorks, totalWorkString, '=');
				getline(getTotalWorks, totalWorkString, '=');
				getline(getTotalWorks, totalWorkString, ';');
				
				// Get payment per employee
				dollar_symbol = buffer.find_last_of("$");
				equal_symbol = buffer.find_last_of("=");
				paymentPerEmployeeString = buffer.substr(equal_symbol + 1, (dollar_symbol - equal_symbol) - 1);

				// Set all data to class
				int paymentInteger = stoi(paymentString);
				int totalWorkInteger = stoi(totalWorkString);
				int paymentPerEmployeeInteger = stoi(paymentPerEmployeeString);
				employee_ptr->setName(employeeName);
				employee_ptr->setFixedPayment(paymentInteger);
				employee_ptr->setTotalEmployee(totalWorkInteger);
				employee_ptr->setPaymentPerEmployee(paymentPerEmployeeInteger);
				shared_ptr<EMPLOYEE> smart_ptr(employee_ptr);
				employee_list.push_back(smart_ptr);
			}
		}
	}
	input.close();
	return employee_list;
}