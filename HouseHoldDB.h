/*
 * File    : HouseHoldDB.h
 * This contains the implementation of storing household objects 
 * in memory using Binary Tree.
 *  
 */

#include "HouseHold.h"

/*
 * Class : HouseHoldNode
 * This node stores HouseHold Object along with its id. And left and right
 * pointers to HouseHoldNode. This HouseHoldNode is stored in a binary tree.
 *
 */
class HouseHoldNode {
public:
	long _id;					// Unique id of the household
	HouseHold _household;		// Stored HouseHold object
	HouseHoldNode* _leftNode;	// Pointer to left HouseHoldNode
	HouseHoldNode* _rightNode;	// Pointer to right HouseHoldNode

	HouseHoldNode(long id, HouseHold household);
};


/*
 * Class : HouseHoldDB
 * This class implements neccessary functions to store and retrieve 
 * HouseHoldNode using Binary tree.
 */
class HouseHoldDB {
public:
	HouseHoldNode* root;		// Root node to the binary tree

	HouseHoldDB();				
	HouseHoldNode* find(HouseHoldNode* root, long id);	
	HouseHoldNode* insert(HouseHoldNode* root, HouseHold household);
	void performTransaction(long id, Expense* expense);
	void display(HouseHoldNode* root);
	void displayByCategory(HouseHoldNode* root, string category);
};