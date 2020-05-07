#include "HouseHold.h"

// House holder id starts with 1
long HouseHold::currid = 1;

HouseHold::HouseHold():_id(-1){
	_name = "NIL";
	_account = nullptr;
}

HouseHold::HouseHold(string name,Account* account) {
	_id = currid++;
	_name = name;
	_account = account;
}

string HouseHold::getName() {
	return _name;
}

long HouseHold::getId() {
	return _id;
}

Account* HouseHold::getAccount() {
	return _account;
}

double HouseHold::getAccountBalance() {
	return _account->getBalance();
}

string HouseHold::getAccountType() {
	return _account->getType();
}

double HouseHold::getFundAvailableForTransaction() {
	return _account->getBalance() - _account->getFee();
}

void HouseHold::addExpense(Expense* expense) {

	// check if the household has the right account 
	if (expense->getPaymentType() != "CASH" && (expense->getPaymentType() != getAccountType())) {
		cout << "There is no " << expense->getPaymentType() << " account in file" << endl;
		cout << "Transaction aborted" << endl;
		return;
	}
	// If there is an expense of same type, accumlate the amount.
	for (vector<Expense*>::iterator it = _expenses.begin(); it != _expenses.end(); it++) {
		Expense* expensePtr = (*it);
		if (expensePtr->getType() == expense->getType()) {
			expensePtr->updateAmount(expense->getAmount());
			expensePtr->setPaymentType(expense->getPaymentType());

			// deduct the money from the account
			if ( expense->getPaymentType() != "CASH")
				_account->debit(expense->getAmount() + _account->getFee() );
			return;
		}
	}
	// this is a new expense, so add it the vector
	
	if (expense->getPaymentType() != "CASH")
		_account->debit(expense->getAmount() + _account->getFee());
	_expenses.push_back(expense);
}
vector<Expense*> HouseHold::getExpenses() {

	return _expenses;
}

void HouseHold::displayExpenses() {
	
	cout << "\t\t*** Expenses *** " << endl;
	if (_expenses.size() == 0) {
		cout << "\t-- no expense record found -- " << endl;
		return;
	}
	double totalExpense = 0.0;
	for (vector<Expense*>::iterator it = _expenses.begin(); it != _expenses.end(); it++) {
		Expense* expensePtr = (*it);
		totalExpense += expensePtr->getAmount();
		cout << "\t" << setw(10) << expensePtr->getType() << " \t$" << setw(10) << setprecision(2) << fixed << expensePtr->getAmount() << "\t" << setw(10) << expensePtr->getPaymentType() << endl;
		
	}
	cout << endl;
	cout << "\t" << setw(10) << "Total" << "\t$" << setw(10) << setprecision(2) << fixed << totalExpense << endl;
}

void HouseHold::displayExpenseByCategory(string category) {
	
	double totalExpense = 0.0;
	for (vector<Expense*>::iterator it = _expenses.begin(); it != _expenses.end(); it++) {
		Expense* expensePtr = (*it);
		if (expensePtr->getType() == category) {
			totalExpense = expensePtr->getAmount();
			break;
		}
	}

	cout << "\t" << left << setw(30) << getName() << " \t$" << right << setw(10) << setprecision(2) << fixed << totalExpense << endl;

}


void HouseHold::toString() {
	cout << "*****" << endl;
	cout << "UserID : " << getId() << "\t\tName : " << getName() << endl << endl;
	cout << "Account Details: " << endl;
	_account->getDetail();
	displayExpenses();
	cout << endl;
}

