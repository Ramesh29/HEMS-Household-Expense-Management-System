#include<iostream>
#include "Expense.h"

using namespace std;

Expense::Expense(double amount, string type) {
		_amount = amount;
		_type = type;
}
double Expense::getAmount() {
	return _amount;
}

void Expense::updateAmount(double amount) {
	_amount += amount;
}
string Expense::getType() {
	return _type;
}

string Expense::getPaymentType() {
	return "CASH";
}

void Expense::setPaymentType(string pType) {

}
void Expense::ExpenseDetail() {
	cout << getType() << " =  " << getAmount() << endl;
}
