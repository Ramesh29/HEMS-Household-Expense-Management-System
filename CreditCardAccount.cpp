#include "CreditCardAccount.h"

CreditCardAccount::CreditCardAccount() {
	_interestRate = 0.0;
}
CreditCardAccount::CreditCardAccount(string name, string cardnumber, string expirydate, double balance, double interestRate) : Account(name, cardnumber, expirydate,  string("CREDIT"), balance ) {
	_interestRate = interestRate;

}

double CreditCardAccount::calculateInterest() {
	return getBalance() * getInterestRate();
}
double CreditCardAccount::getFee() {
	return 0.0;
}

double CreditCardAccount::getInterestRate() {
	return _interestRate;
}


void CreditCardAccount::getDetail() {
	cout << "Acount Type      : CREDIT \n";
	cout << "Card Holder      : " + getName() + "\n";
	cout << "Card Number      : " + getCardNumber() + "\n";
	cout << "Expiry Date      : " + getExpiryDate() + "\n";
	cout << "Balance          : "  << setprecision(2) << fixed << getBalance() << "\n";
	cout << "Interest Rate    : "  << setprecision(2) << fixed << getInterestRate() << "\n";
}