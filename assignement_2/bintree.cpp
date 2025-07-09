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
    makeEmpty()
    root = nullptr;
}

bool BinTree::isEmpty() const {
return root == nullptr;
}

void BinTree::makeEmpty() {
// call the helper to clear the tree
}

// assignment operator
BinTree& BinTree:operator=(const BinTree &otherTree) {
// deep copy the tree
}

// equality operator
bool BinTree::operator==(const BinTree &otherTree) const {
// go through all of the nodes at the same time using isEqual()
} 
// inequality operator
bool BinTree::operator!=(const BinTree &otherTree) const {

}  
// inserts a NodeData object
bool insert(NodeData *newData) {

}   
// retrieves data            
bool retrieve(const NodeData &targetData, NodeData *&foundData) const {

} 
// gets height of a node
int getHeight(const NodeData &targetData) const {

}
// converts BST to array
void bstreeToArray(NodeData *dataArray[]) {

}        
// builds BST from sorted array
void arrayToBSTree(NodeData *dataArray[]) {
    
}       