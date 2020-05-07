#ifndef __CREDIT_CARD_TRANSACTION__
#define __CREDIT_CARD_TRANSACTION__

#include<iostream>
#include<iomanip>
#include<string>
#include "Expense.h"
#include "CreditCardAccount.h"

using namespace std;

class CreditCardTransaction :public Expense {
	string _paymentType;

public:
	CreditCardTransaction(double amount, string type);
	void ExpenseDetail();
	string getPaymentType();
	void setPaymentType(string pType);
};

#endif