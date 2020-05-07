#include "CreditCardTransaction.h"

CreditCardTransaction::CreditCardTransaction(double amount, string type ) :Expense{ amount, type } {
	_paymentType = "CREDIT";
}

string CreditCardTransaction::getPaymentType() {
	return _paymentType;
}

void CreditCardTransaction::setPaymentType(string pType) {
	_paymentType = pType;
}


void CreditCardTransaction::ExpenseDetail() {
	cout << getType() << " =  " << getAmount() << " paid by " << getPaymentType() << endl;
	cout << endl;
}
