#ifndef __DEBIT_CARD_TRANSACTION__
#define __DEBIT_CARD_TRANSACTION__

#include<iostream>
#include<iomanip>
#include<string>
#include "Expense.h"
#include "DebitCardAccount.h"

using namespace std;

class DebitCardTransaction :public Expense {
	string _paymentType;

public:
	DebitCardTransaction(double amount, string type);
	void ExpenseDetail();
	string getPaymentType();
	void setPaymentType(string pType);
};

#endif