#include "HouseHoldDB.h"

/**
 * Constructor HouseHoldNode
 * Parameters:
 *  id - id of the household
 *  household - HouseHold object to store
 * Purpose :
 *  - Initialize a HouseHoldNode with household id and object 
 */
HouseHoldNode::HouseHoldNode(long id, HouseHold household) {
	_id = id;
	_household = household;
	_leftNode = _rightNode = nullptr;
}

/**
 * Constructor HouseHoldDB
 * Parameters : None
 * Purpose :
 * - Initialize the root pointer of the binary tree to nullptr
 */
HouseHoldDB::HouseHoldDB() {
	root = nullptr;
}

/**
 * Function find
 * Parameters: 
 *  root - root pointers of the binary tree
 *  id   - id of the household to find.
 * Purpose:
 *  - Find the household with the given id. It returns
 *  - a HouseHoldNode if found, else return nullptr.
 */
HouseHoldNode* HouseHoldDB::find(HouseHoldNode* root, long id) {
	if (root == nullptr || root->_id == id) {
		return root;
	}
	else if (id < root->_id) {
		return find(root->_leftNode, id);
	}
	else {
		return find(root->_rightNode, id);
	}
}

/**
 * Function insert
 * Parameters:
 *  root - root pointers of the binary tree
 *  household   - HouseHold object to be inserted in the binary tree
 * Purpose:
 *  - insert a householdNode in the binary tree for the given household
 */ 

HouseHoldNode* HouseHoldDB::insert(HouseHoldNode* root, HouseHold household) {
	// only insert household with unique id
	if (find(root, household.getId()) != nullptr) {
		cout << "Household with id : " << household.getId() << " exists. Try with different id " << endl;
		return nullptr;
	}

	if (root == nullptr) {
		root = new HouseHoldNode(household.getId(), household);
	}
	else if (household.getId() <= root->_id) {
		root->_leftNode = insert(root->_leftNode, household);
	}
	else {
		root->_rightNode = insert(root->_rightNode, household);
	}

	return root;
}


/**
 * Function performTransaction
 * Parameters:
 *  root - root pointers of the binary tree
 *  expense - transaction to be performed.
 * Purpose:
 *  - Perfrom the transaction(expense) for the given HouseHold with id = id
 */
void HouseHoldDB::performTransaction(long id, Expense* expense) {
	// find the household 
	HouseHoldNode* tempNode = find(root, id);
	if (tempNode == nullptr) {
		cout << "Household with id : " << id << " is not found" << endl;
		return;
	}

	// if payment type is debit or credit, check for available funds
	if (expense->getPaymentType() == "DEBIT" || expense->getPaymentType() == "CREDIT") {
		double balance = tempNode->_household.getFundAvailableForTransaction();
		if ((balance - expense->getAmount()) < 0) {
			cout << "Transaction failed due to insufficient fund. Available fund : " << balance << endl;
			return;
		}
	}



	tempNode->_household.addExpense(expense);
}


/**
 * Function display
 * Parameters:
 *  root - root pointer to the binary tree 
 * Purpose:
 * display the household information.
 */
void HouseHoldDB::display(HouseHoldNode* root) {
	if (root == nullptr) return;
	display(root->_leftNode);
	root->_household.toString();
	display(root->_rightNode);

}

void HouseHoldDB::displayByCategory(HouseHoldNode* root, string category) {
	if (root == nullptr) return;
	displayByCategory(root->_leftNode, category);
	root->_household.displayExpenseByCategory(category);
	displayByCategory(root->_rightNode,category);
}


