#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
	string _name;
	string _cardnumber;
	string _expirydate;
	float _balance;
	string _type;
public:
	Account();
	Account(string name, string cardnumber, string expirydate,  string type , double balance );
	void credit(double);
	bool debit(double);
	string getName();
	string getCardNumber();
	string getExpiryDate();
	double getBalance();
	string getType();
	double virtual calculateInterest() { return 0.0; }
	double virtual getInterestRate() = 0;
	double virtual getFee() = 0;
	void   virtual getDetail() = 0;
};
#endif