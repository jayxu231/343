// ------------------------------------------------ bintree.h -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/8/2025
// Date of Last Modification : 7/13/2025
// ------------------------------------------------------------------------------------------------------------------
// Purpose: Defines the BinTree class and Node structure for managing a binary search tree of NodeData pointers.
//          Supports insert, retrieve, height calculation, conversion to/from arrays, deep copying, and comparisons.
// ------------------------------------------------------------------------------------------------------------------
// Notes: Uses NodeData class which encapsulates a string. Tree owns and deletes NodeData* pointers.
//        Follows recursive strategy for all key operations and uses helper functions for clarity.
// ------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"

class BinTree {

public:
	BinTree();								// constructor
	BinTree(const BinTree &otherTree);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	

	bool isEmpty() const;		//done			// true if tree is empty, otherwise false
	void makeEmpty();			//done			// make the tree empty so isEmpty returns true

    BinTree& operator=(const BinTree &otherTree);     // assignment operator
    bool operator==(const BinTree &otherTree) const;  // equality operator
    bool operator!=(const BinTree &otherTree) const;  // inequality operator

    friend std::ostream& operator<<(std::ostream& out, const BinTree& tree); //prints tree in order

    bool insert(NodeData *newData);                   // inserts a NodeData object
    bool retrieve(const NodeData &targetData, NodeData *&foundData) const;  // retrieves data
    
    int getHeight(const NodeData &targetData) const;  // gets height of a node
    
    void bstreeToArray(NodeData *dataArrayF[]);        // converts BST to array
    void arrayToBSTree(NodeData *dataArray[]);        // builds BST from sorted array
    
    void displaySideways() const;                     // displays the tree sideways
	
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

    // helper for makeEmpty() Done
    void makeEmptyHelper(Node *&curr);

    // compares two subtrees Done
    bool isEqual(Node *nodeA, Node *nodeB) const;

    // helper for insert() Done
    bool insertHelper(Node *&curr, NodeData *newData);

    // helper for retrieve() Dones
    bool retrieveHelper(Node *curr, const NodeData &targetData, NodeData *&foundData) const;

    // helper for getHeight()
    int getHeightHelper(Node *curr, const NodeData &targetData, int &maxHeight) const;

    // computes height of a node
    int nodeHeight(Node *curr) const;

    // deep copy utility
    Node* copyTree(Node *curr) const;

    // helper for operator<< (inorder traversal)
    void inorderHelper(Node *curr, std::ostream& out) const;

    // helper for displaySideways()
    void sideways(Node *curr, int level) const;

    // helpers for tree-array conversion
    int bstreeToArrayHelper(Node *curr, NodeData *dataArray[], int &index);
    Node* arrayToBSTreeHelper(NodeData *dataArray[], int low, int high);
};



#endif