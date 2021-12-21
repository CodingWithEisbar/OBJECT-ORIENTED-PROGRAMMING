#include "employeeFactory.h"

EMPLOYEE_FACTORY::EMPLOYEE_FACTORY()
{
	auto dailyEmployee = make_shared<DAILY_EMPLOYEE>();
	auto hourlyEmployee = make_shared<HOURLY_EMPLOYEE>();
	auto productEmployee = make_shared<PRODUCT_EMPLOYEE>();
	auto manager = make_shared<MANAGER>();

	_pool.push_back(dailyEmployee);
	_pool.push_back(hourlyEmployee);
	_pool.push_back(productEmployee);
	_pool.push_back(manager);
}

shared_ptr<EMPLOYEE_FACTORY> EMPLOYEE_FACTORY::instance()
{
	if (_instance == NULL)
	{
		auto temp = new EMPLOYEE_FACTORY();
		_instance = make_shared<EMPLOYEE_FACTORY>(*temp);
	}
	return _instance;
}

void EMPLOYEE_FACTORY::displayAll()
{
	for (int i = 0; i < _pool.size(); i++)
	{
		shared_ptr<EMPLOYEE> item = _pool[i];
		cout << item->toString() << endl;
		cout << endl;
	}
}