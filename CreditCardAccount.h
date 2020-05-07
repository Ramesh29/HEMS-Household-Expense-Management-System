#ifndef __CREDIT_CARD_ACCOUNT_H__
#define __CREDIT_CARD_ACCOUNT_H__

#include "Account.h"

class CreditCardAccount : public Account {
	double _interestRate;
public:
	CreditCardAccount();
	CreditCardAccount(string , string , string , double, double );
	double calculateInterest();
	double virtual getFee();
	double virtual getInterestRate();
	void virtual getDetail();

};

#endif