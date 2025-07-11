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
    root = copyTree(otherTree.root);
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
    makeEmpty();
    root = copyTree(otherTree.root);
    return *this;
}
BinTree::Node* BinTree::copyTree(Node *curr) const {
    if(curr == nullptr) {
        return nullptr;
    }
    Node * temp = new Node();
    temp->data = new NodeData(*curr->data);
    temp->left = copyTree(curr->left);
    temp->right = copyTree(curr->right);
    return temp;
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
    return insertHelper(root, newData);
}   
bool BinTree::insertHelper(Node *&curr, NodeData *newData) {
    if(curr == nullptr) {
        Node * temp = new Node();
        temp->data = new NodeData(*newData);
        temp->left = nullptr;
        temp->right = nullptr;
        curr = temp;
        return true;
    }
    if(*curr->data == *newData) {
        return false; 
    }
    if(*curr->data < *newData) {
        return insertHelper(curr->right, newData);
    } else {
        return insertHelper(curr->left, newData);
    }   
}
// retrieves data            
bool BinTree::retrieve(const NodeData &targetData, NodeData *&foundData) const {
    return retrieveHelper(root, targetData, foundData);
} 
// recursive retrieval helper
bool BinTree::retrieveHelper(Node *curr, const NodeData &targetData, NodeData *&foundData) const {
    if(curr == nullptr) {
        foundData = nullptr;
        return false;
    }
    if(*curr->data == targetData) {
        foundData = curr->data;
        return true;
    }
    if( targetData < *curr->data) {
        return retrieveHelper(curr->left, targetData, foundData);
    } else {
        return retrieveHelper(curr->right, targetData, foundData);
    }
}
// gets height of a node
int BinTree::getHeight(const NodeData &targetData) const {
    int height;
    return getHeightHelper(root, targetData, height);
}
// recursive height finder 
int BinTree::getHeightHelper(Node *curr, const NodeData &targetData, int &maxHeight) const {

}
// converts BST to array
void bstreeToArray(NodeData *dataArray[]) {
// call the helpers
}        
// builds BST from sorted array
void arrayToBSTree(NodeData *dataArray[]) {
// call helpers
}       