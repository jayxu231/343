// ------------------------------------------------ bintree.h -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/8/2025
// Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"

class BinTree {

public:
	BinTree();								// constructor
	BinTree(const BinTree &otherTree);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	

	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true

    BinTree& operator=(const BinTree &otherTree);     // assignment operator
    bool operator==(const BinTree &otherTree) const;  // equality operator
    bool operator!=(const BinTree &otherTree) const;  // inequality operator
    
    bool insert(NodeData *newData);                   // inserts a NodeData object
    bool retrieve(const NodeData &targetData, NodeData *&foundData) const;  // retrieves data
    
    int getHeight(const NodeData &targetData) const;  // gets height of a node
    
    void bstreeToArray(NodeData *dataArray[]);        // converts BST to array
    void arrayToBSTree(NodeData *dataArray[]);        // builds BST from sorted array
    
    void displaySideways() const;                     // displays the tree sideways
	
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

    // helper for makeEmpty()
    void makeEmptyHelper(Node *&curr);

    // helper for insert()
    bool insertHelper(Node *&curr, NodeData *newData);

    // helper for retrieve()
    bool retrieveHelper(Node *curr, const NodeData &targetData, NodeData *&foundData) const;

    // helper for getHeight()
    int getHeightHelper(Node *curr, const NodeData &targetData, int &maxHeight) const;

    // computes height of a node
    int nodeHeight(Node *curr) const;

    // compares two subtrees
    bool isEqual(Node *nodeA, Node *nodeB) const;

    // deep copy utility
    Node* copyTree(Node *sourceNode) const;

    // helper for operator<< (inorder traversal)
    void inorderHelper(Node *curr) const;

    // helper for displaySideways()
    void sideways(Node *curr, int level) const;

    // helpers for tree-array conversion
    int bstreeToArrayHelper(Node *curr, NodeData *dataArray[], int &index);
    Node* arrayToBSTreeHelper(NodeData *dataArray[], int low, int high);
};



#endif