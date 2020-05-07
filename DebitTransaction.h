#ifndef __DEBIT_CARD_TRANSACTION__
#define __DEBIT_CARD_TRANSACTION__

#include<iostream>
#include<iomanip>
#include<string>
#include "Expense.h"
#include "Account.h"

using namespace std;

class DebitCardTransaction : public Expense {
	string _paymentType;
	Account _account;

public:
	DebitCardTransaction(float amount, string type, Account account);


};


#endif
