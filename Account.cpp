#include "Account.h"

Account::Account(){}
Account::Account(string name, string cardnumber, string expirydate, string type , double balance = 0.0) {
	_name = name;
	_cardnumber = cardnumber;
	_expirydate = expirydate;
	_type = type;

	if (balance < 0) {
		cout << "Initial balance is invalid " << endl;
		_balance = 0.0;
		return;
	}
	_balance = balance;
}

void Account::credit(double amount) {
	_balance += amount;
}

bool Account::debit(double amount) {
	if (amount > _balance) {
		cout << "Debit amount " << amount << " exceeded account balance " << endl;
		return false;
	}
	_balance -= amount;

	return false;
}

string Account::getName() {
	return _name;
}

string Account::getCardNumber() {
	return _cardnumber;
}
 
string Account::getExpiryDate() {
	return _expirydate;
}


double Account::getBalance() {
	return _balance;
}

string Account::getType() {
	return _type;
}
