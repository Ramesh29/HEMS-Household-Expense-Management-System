#include "HouseHoldDB.h"
#include "Account.h"
#include "DebitCardAccount.h"
#include "CreditCardAccount.h"
#include "CashTransaction.h"
#include "CreditCardTransaction.h"
#include "DebitCardTransaction.h"


int getOption() {

	int displaywidth = 100;
	int colwidth = 40;
	int padding = (100 - colwidth) / 2;

	cout << string(padding, ' ') << setw(colwidth) << "HEMS - HouseHold Expense Moniotring System" << endl;
	cout << string(padding, ' ') << setw(colwidth) << "==========================================" << endl << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " Choose your option: " << endl << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 1. Create Household " << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 2. Perform Transaction" << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 3. Print summary " << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 4. Print summary by category " << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 5. clear" << endl;
	cout << string(padding, ' ') << left << setw(colwidth) << " 0. Exit " << endl;
	int option;
	cin >> option;

	return option;
}


double getDouble(string tag) {
	cout << tag << endl;
	double val;
	while (1) {
		if (cin >> val) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	cin.ignore();
	return val;
}

int getInt(string tag) {
	cout << tag << endl;
	int val;
	while (1) {
		if (cin >> val) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a integer value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	cin.ignore();

	return val;
}


DebitCardAccount* createDebitAccount() {
	string name, cardnumber, expirydate;
	double balance, fee;
	cin.ignore();
	cout << "Name on Debitcard : " << endl;
	getline(cin, name);
	cout << "Debitcard number : " << endl;
	getline(cin, cardnumber);
	cout << "Expiry date : " << endl;
	getline(cin,expirydate);
	balance = getDouble("Debit balance");
	fee = getDouble("Transaction Fee");
	cout << "";
	return new DebitCardAccount(name, cardnumber, expirydate, balance, fee);
}

CreditCardAccount* createCreditAccount() {
	string name, cardnumber, expirydate;
	double limit, interestrate;
	cin.ignore();
	cout << "Name of Creditcard : " << endl;
	getline(cin, name);
	cout << "Creditcard number: " << endl;
	getline( cin ,cardnumber);
	cout << "Expiry date : " << endl;
	getline(cin ,expirydate);
	limit = getDouble("Credit limit");
	interestrate = getDouble("Interest rate");
	cout<<"";
	return new CreditCardAccount(name, cardnumber, expirydate, limit, interestrate);
}

int getAccountType() {
	cout << "Select Account Type" << endl;
	cout << "1. Debit" << endl;
	cout << "2. Credit" << endl;
	int option;
	cin >> option;
	return option;
}

int getTransactionType() {
	cout << "Select the type of transaction" << endl;
	cout << "1. Cash " << endl;
	cout << "2. Debit" << endl;
	cout << "3. Credit" << endl;
	int option;
	cin >> option;
	return option;
}

int main() {
	
	HouseHoldDB db;
	int option = -1;
	int accountType = -1;
	int transactionType = -1;
	int userid = -1;
	double amount = 0;
	string type = "";
	string name, category;
	
	do {
		option = getOption();

		switch (option) {
		case 1: // creat a new household
			cin.ignore();
			cout << "Enter name :" << endl;
			getline(cin, name);
			// get account type ( credit or debit )
			while (1) {
				accountType = getAccountType();
				if (accountType == 1 || accountType == 2) break;
			}
			if (accountType == 1) {
				DebitCardAccount* da = createDebitAccount();
				HouseHold hh(name, da);
				db.root = db.insert(db.root, hh);
			}
			else {
				CreditCardAccount* ca = createCreditAccount();
				HouseHold hh(name, ca);
				db.root = db.insert(db.root, hh);
			}
			break;
		case 2: // perform transaction
			userid = getInt("Enter user id");
			cout << "Enter type of payment ( bill, shopping, medication, etc )\n";
			getline(cin, type);
			amount = getDouble("Enter the amount to pay");
			// get transaction type ( cash, debit or credit )
			while (1) {
				transactionType = getTransactionType();
				if (transactionType == 1 || transactionType == 2 || transactionType == 3) break;
			}
			if (transactionType == 1) { // cash
				Expense* cashTrans = new  CashTransaction(amount, type);
				//CashTransaction cashTrans (amount, type);
				db.performTransaction(userid, cashTrans);
			}
			else if (transactionType == 2) { // debit
				Expense* debitTrans = new  DebitCardTransaction(amount, type);
				//DebitCardTransaction debitTrans(amount, type);
				db.performTransaction(userid, debitTrans);
			}
			else {
				//credit
				Expense* creditTrans = new  CreditCardTransaction(amount, type);
				//CreditCardTransaction creditTrans(amount, type);
				db.performTransaction(userid, creditTrans);
			}

			break;
		case 3:
			db.display(db.root);
			break;
		case 4: // display expense by category
			cin.ignore();
			cout << "Enter expense category type( e.g bill )" << endl;
			getline(cin, category);
			cout << endl << "*** Amount spent on " << category << ":" << endl;
			db.displayByCategory(db.root, category);
			cout << endl;

			break;
		case 5:
			system("cls");
			break;
		default:
			break;
		}

	} while (option != 0);










	/*

	HouseHoldDB db;

	DebitCardAccount* a1 = new DebitCardAccount("Thanesh", "12121212", "12/12/12", 1000, 4);
	DebitCardAccount* a2 = new DebitCardAccount("Balesh", "12121212", "12/12/12", 1000, 4);
	CreditCardAccount* a3 = new CreditCardAccount("Ramesh", "12121212", "12/12/12", 1000, 0.1);
	CreditCardAccount* a4 = new CreditCardAccount("Rathes", "12121212", "12/12/12", 1000, 0.2);

	HouseHold thanesh("Thanesh", a1);
	HouseHold balesh("Balesh", a2);
	HouseHold ramesh("Ramesh", a3);
	HouseHold rathesh("Rathesh", a4);



	
	db.root = db.insert(db.root, thanesh);
	db.root = db.insert(db.root, balesh);
	db.root = db.insert(db.root, ramesh);
	db.root = db.insert(db.root, rathesh);

	// do not need pass account here.
	DebitCardTransaction * ex1 = new DebitCardTransaction(100.00, "Bill Payment");
	DebitCardTransaction * ex2 = new DebitCardTransaction(1000, "Medication");


	db.performTransaction(1, ex1);
	db.performTransaction(1, ex2);




	db.display(db.root);
*/


	return 0;
}