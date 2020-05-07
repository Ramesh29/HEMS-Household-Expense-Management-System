#ifndef __DEBIT_CARD_ACCOUNT_H__
#define __DEBIT_CARD_ACCOUNT_H__

#include "Account.h"

class DebitCardAccount : public Account {
	double _fee;
public:
	DebitCardAccount();
	DebitCardAccount(string, string , string, double, double);
	double virtual getFee();
	double virtual getInterestRate();
	void virtual getDetail();

};


#endif