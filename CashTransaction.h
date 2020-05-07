#ifndef __CASH_TRANSACTION__
#define __CASH_TRANSACTION__

#include<iostream>
#include<iomanip>
#include<string>
#include "Expense.h"

using namespace std;


class CashTransaction:public Expense {
	string _paymentType;
public :
	CashTransaction(double amount, string type);
	void ExpenseDetail();
	string getPaymentType();
	void setPaymentType(string pType);
};

#endif