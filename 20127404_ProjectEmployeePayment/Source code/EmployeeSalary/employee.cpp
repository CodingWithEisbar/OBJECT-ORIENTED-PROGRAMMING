#include "employee.h"


EMPLOYEE::EMPLOYEE() {

}

DAILY_EMPLOYEE::DAILY_EMPLOYEE()
{
	this->_employeeCode = 0;
}

string DAILY_EMPLOYEE::toString()
{
	stringstream builder;
	builder << "Name: " << getName() << endl;
	builder << "Position: Daily Employee." << endl;
	builder << "Total payment: " << this->_dailyPayment * this->_totalDays << "$";
	
	string result = builder.str();
	return result;
}

HOURLY_EMPLOYEE::HOURLY_EMPLOYEE()
{
	this->_employeeCode = 1;
}

string HOURLY_EMPLOYEE::toString()
{
	stringstream builder;
	builder << "Name: " << getName() << endl;
	builder << "Position: Hourly Employee." << endl;
	builder << "Total payment: " << this->_hourlyPayment * this->_totalHours << "$";

	string result = builder.str();
	return result;
}

PRODUCT_EMPLOYEE::PRODUCT_EMPLOYEE()
{
	this->_employeeCode = 2;
}

string PRODUCT_EMPLOYEE::toString()
{
	stringstream builder;
	builder << "Name: " << getName() << endl;
	builder << "Position: Product Employee." << endl;
	builder << "Total payment: " << this->_paymentPerProduct * this->_totalProducts << "$";

	string result = builder.str();
	return result;
}

MANAGER::MANAGER()
{
	this->_employeeCode = 3;
}

string MANAGER::toString()
{
	stringstream builder;
	builder << "Name: " << getName() << endl;
	builder << "Position: Manager." << endl;
	builder << "Total payment: " << this->_totalEmployee * this->_paymentPerEmployee + this->_fixedPayment << "$";

	string result = builder.str();
	return result;
}