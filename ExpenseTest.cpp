#include "Expense.h"
#include "CashTransaction.h"
#include "DebitCardTransaction.h"
#include "CreditCardTransaction.h"
#include "DebitAccount.h"
#include "CreditCardAccount.h"

int main() {

	// test cash transaction
	CashTransaction ct1(200.00, "Bill");
	CashTransaction ct2(500.00, "Medication");
	ct1.ExpenseDetail();
	ct2.ExpenseDetail();

	// test debit transaction
	// 1. create a debit account
	DebitCardAccount da("Rameswaran", "121212121", "12/12/20", 2000, 5);
	DebitCardTransaction dt(100, "Bill Payment", da);
	
	dt.ExpenseDetail();

	// text credit transaction
	CreditCardAccount ca("Rameswaran", "121212121", "12/12/20", 1000, 0.9);
	CreditCardTransaction ct(100, "Medication", ca);
	ct.ExpenseDetail();
	


}