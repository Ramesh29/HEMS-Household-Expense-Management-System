#include "CashTransaction.h"


CashTransaction::CashTransaction(double amount, string type ):Expense{ amount, type}{
	_paymentType = "CASH";
}

string CashTransaction::getPaymentType() {
	return _paymentType;
}
void CashTransaction::setPaymentType(string pType) {
	_paymentType = pType;
}
void CashTransaction::ExpenseDetail() {
	cout << getType() << " =  " << getAmount() << " paid by " << getPaymentType() << endl << endl;
}
