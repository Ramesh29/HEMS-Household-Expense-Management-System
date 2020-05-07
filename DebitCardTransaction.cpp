#include "DebitCardTransaction.h"

DebitCardTransaction::DebitCardTransaction(double amount, string type) :Expense{ amount, type } {
	_paymentType = "DEBIT";

}

string DebitCardTransaction::getPaymentType() {
	return _paymentType;
}

void DebitCardTransaction::setPaymentType(string pType) {
	_paymentType = pType;
}


void DebitCardTransaction::ExpenseDetail() {
	cout << getType() << " =  " << getAmount() << " paid by " << getPaymentType() << endl;
}
