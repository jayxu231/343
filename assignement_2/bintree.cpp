// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/8/2025
// Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"

BinTree::BinTree() {
    root = nullptr;
}    

BinTree::BinTree(const BinTree &otherTree) {

}

BinTree::~BinTree() {
    makeEmpty();
}

bool BinTree::isEmpty() const {
    return root == nullptr;
}

void BinTree::makeEmpty() {
// call the helper to clear the tree
    makeEmptyHelper(root);
}

void BinTree::makeEmptyHelper(Node *&curr) {
    if(curr == nullptr) {
        return;
    }

    makeEmptyHelper(curr->left);
    makeEmptyHelper(curr->right);

    delete curr->data;
    curr->data = nullptr;
    delete curr;
    curr = nullptr;
}

// assignment operator
BinTree& BinTree::operator=(const BinTree &otherTree) {
// deep copy the tree
    if(this == &otherTree) {
        return;
    }

}
BinTree::Node* BinTree::copyTree(Node *curr) const {
    if(curr == nullptr) {
        return nullptr;
    }
    Node * temp = new Node();
    
}
// equality operator
bool BinTree::operator==(const BinTree &otherTree) const {
    return isEqual(this->root, otherTree.root);
} 

// helper function called in operator==
bool BinTree::isEqual(Node *nodeA, Node *nodeB) const {
    if(nodeA == nullptr && nodeB == nullptr) {
        return true;
    }
    if ((nodeA == nullptr) != (nodeB == nullptr)){
        return false;
    }

    return *nodeA->data == *nodeB->data && isEqual(nodeA->left, nodeB->left) && isEqual(nodeA->right, nodeB->right);
}

// inequality operator
bool BinTree::operator!=(const BinTree &otherTree) const {
    return !isEqual(this->root, otherTree.root);
}  
// inserts a NodeData object
bool BinTree::insert(NodeData *newData) {

}   
// retrieves data            
bool BinTree::retrieve(const NodeData &targetData, NodeData *&foundData) const {

} 
// gets height of a node
int BinTree::getHeight(const NodeData &targetData) const {

}
// converts BST to array
void bstreeToArray(NodeData *dataArray[]) {
// call the helpers
}        
// builds BST from sorted array
void arrayToBSTree(NodeData *dataArray[]) {
// call helpers
}       