#ifndef _EMPLOYEE_FACTORY_H_
#define _EMPLOYEE_FACTORY_H_


#include <vector>
#include "employee.h"

class EMPLOYEE_FACTORY {
private:
	vector<shared_ptr<EMPLOYEE>> _pool ;
private:
	inline static shared_ptr<EMPLOYEE_FACTORY> _instance = NULL;
	EMPLOYEE_FACTORY();
public:
	static shared_ptr<EMPLOYEE_FACTORY> instance();
public:
	void setAllData(vector<shared_ptr<EMPLOYEE>> data) { _pool = data; }
	void displayAll();
};



#endif 