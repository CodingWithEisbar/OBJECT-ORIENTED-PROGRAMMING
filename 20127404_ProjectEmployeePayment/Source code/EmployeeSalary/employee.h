#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

class EMPLOYEE {
protected:
	int _employeeCode = -1;
	string _name;
	//Payments:
	int _dailyPayment;
	int _hourlyPayment;
	int _paymentPerProduct;
	//Labor results:
	int _totalDays;
	int _totalHours;
	int _totalProducts;

	//Manager data:
	int _fixedPayment;
	int _totalEmployee;
	int _paymentPerEmployee;
public:
	EMPLOYEE();
	virtual int getEmployeeCode() { return 0; }
	virtual string getName() { return ""; }
	virtual void setName(string sample) {};

	// Get payment:
	virtual int getDailyPayment() { return 0; }
	virtual int getHourlyPayment() { return 0; }
	virtual int getPaymentPerProduct() { return 0; }
	
	// Set payment:
	virtual void setDailyPayment(int) {}
	virtual void setHourlyPayment(int) {}
	virtual void setPaymentPerProduct(int) {}
	
	// Get labor results:
	virtual int getTotalDays() { return 0; }
	virtual int getTotalHours() { return 0; }
	virtual int getTotalProducts() { return 0; }

	// Set labor results:
	virtual void setTotalDays(int) {}
	virtual void setTotalHours(int) {}
	virtual void setTotalProducts(int) {}

	// Get manager data:
	virtual int getFixedPayment() { return 0; }
	virtual int getTotalEmployee() { return 0; }
	virtual int getPaymentPerEmployee() { return 0; }

	// Set manager data:
	virtual void setFixedPayment(int) {}
	virtual void setTotalEmployee(int) {}
	virtual void setPaymentPerEmployee(int) {}

	virtual string toString() { return ""; }
public:
	virtual ~EMPLOYEE() {}
};

class DAILY_EMPLOYEE : virtual public EMPLOYEE {
public:
	DAILY_EMPLOYEE();
public:
	string getName() { return _name; }
	void setName(string sample) { _name = sample; }
	int getEmployeeCode() { return _employeeCode; }

public:
	void setDailyPayment(int value) { _dailyPayment = value; }
	int getDailyPayment() { return _dailyPayment; }

	void setTotalDays(int value) { _totalDays = value; }
	int getTotalDays() { return _totalDays;  }
	string toString();
};

class HOURLY_EMPLOYEE : virtual public EMPLOYEE {
public:
	HOURLY_EMPLOYEE();
public:
	string getName() { return _name; }
	void setName(string sample) { _name = sample; }
	int getEmployeeCode() { return _employeeCode; }

public:
	void setHourlyPayment(int value) { _hourlyPayment = value; }
	int getHourlyPayment() { return _hourlyPayment; }

	void setTotalHours(int value) { _totalHours = value; }
	int getTotalHours() { return _totalHours; }

	string toString();
};

class PRODUCT_EMPLOYEE : virtual public EMPLOYEE {
public:
	PRODUCT_EMPLOYEE();
public:
	string getName() { return _name; }
	void setName(string sample) { _name = sample; }
	int getEmployeeCode() { return _employeeCode; }

public:
	void setPaymentPerProduct(int value) { _paymentPerProduct = value; }
	int getPaymentPerProduct() { return _paymentPerProduct; }

	void setTotalProducts(int value) { _totalProducts = value; }
	int getTotalProducts() { return _totalProducts; }

	string toString();
};

class MANAGER : virtual public EMPLOYEE {
public:
	MANAGER();
public:
	string getName() { return _name; }
	void setName(string sample) { _name = sample; }
	int getEmployeeCode() { return _employeeCode; }
public:
	int getFixedPayment() { return _fixedPayment; }
	int getTotalEmployee() { return _totalEmployee; }
	int getPaymentPerEmployee() { return _paymentPerEmployee; }

	void setFixedPayment(int value) { _fixedPayment = value; }
	void setTotalEmployee(int value) { _totalEmployee = value; }
	void setPaymentPerEmployee(int value) { _paymentPerEmployee = value; }
public:
	string toString();
};

#endif