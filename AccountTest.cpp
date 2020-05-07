#include "Account.h"
#include "DebitCardAccount.h"
#include "CreditCardAccount.h"


int main() {


	CreditCardAccount ca("Ramesh", "123456664543", "12/12/20", 1000, 0.9);

	ca.credit(1000);
	ca.debit(500);
	ca.getDetail();


	DebitCardAccount dc("Thanesh", "1212121212", "12/12/20", 1000, 5);
	dc.credit(2000);
	dc.debit(100);
	dc.getDetail();

	return 0;

}