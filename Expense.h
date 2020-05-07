#ifndef __EXPENSE_H__
#define __EXPENSE_H__


#include<iostream>
#include<iomanip>
#include<string>



using namespace std;


class Expense {
private:
	double _amount;
	string _type;

public:
	Expense(double amount, string type);

	double getAmount();
	void updateAmount(double amount);
	string getType();
	
	virtual string getPaymentType();
	virtual void setPaymentType(string pType);
	void ExpenseDetail();
};

#endif 

