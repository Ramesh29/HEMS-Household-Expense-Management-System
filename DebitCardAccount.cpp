#include "DebitCardAccount.h"

DebitCardAccount::DebitCardAccount(){
	_fee = 0.0;
}
DebitCardAccount::DebitCardAccount(string name, string cardnumber, string expirydate, double balance, double fee = 0.0) : Account(name, cardnumber, expirydate, string("DEBIT"), balance ) {
	_fee = fee;

}


double DebitCardAccount::getFee() {
	return _fee;
}
double DebitCardAccount::getInterestRate() {
	return 0.0;
}

void DebitCardAccount::getDetail() {
	cout << "Acount Type      : DEBIT - CHECKING \n";
	cout << "Card Holder      : " + getName() + "\n";
	cout << "Card Number      : " + getCardNumber() + "\n";
	cout << "Expiry Date      : " + getExpiryDate() + "\n";
	cout << "Balance          : " << setprecision(2) << fixed << getBalance() <<  "\n";
	cout << "Fee              : " << setprecision(2) << fixed << getFee() << "\n";
}