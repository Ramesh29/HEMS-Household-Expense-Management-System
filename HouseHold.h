#ifndef __HOUSE_HOLD_H__
#define __HOUSE_HOLD_H__

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

#include "Account.h"
#include "Expense.h"

using namespace std;

class HouseHold {
private:
	static long currid;
	long _id;
	string _name;
	Account* _account;
	vector<Expense*> _expenses;
public:
	HouseHold();
	HouseHold(string name, Account* account );
	string getName();
	long getId();
	Account* getAccount();
	double getAccountBalance();
	string getAccountType();
	double getFundAvailableForTransaction();
	vector<Expense*> getExpenses();
	void addExpense(Expense* expense);
	void displayExpenses();
	void displayExpenseByCategory(string category);
	void toString();
};

#endif