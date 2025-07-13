// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/8/2025
// Date of Last Modification : 7/13/2025
// ------------------------------------------------------------------------------------------------------------------
// Purpose: Implements the BinTree class functions, including construction, destruction, insertion, retrieval,
//          deep copying, comparisons, height calculation, and BST <-> array conversions.
// ------------------------------------------------------------------------------------------------------------------
// Notes: All memory management is handled internally. Operations such as copy, assignment, and equality use
//        recursive helper functions. Input/output assumes NodeData has appropriate overloaded operators.
// ------------------------------------------------------------------------------------------------------------------
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
// ---------------------------- isEmpty ------------------------------------
// Returns true if the binary search tree is empty.
bool BinTree::isEmpty() const {
    return root == nullptr;
}
// ---------------------------- makeEmpty ----------------------------------
// Empties the binary tree by deleting all nodes and their data.
void BinTree::makeEmpty() {
    makeEmptyHelper(root);
}
// ---------------------------- makeEmptyHelper ----------------------------
// Recursively deletes all nodes starting from curr.
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
std::ostream& operator<<(std::ostream& out, const BinTree& tree) {
    tree.inorderHelper(tree.root, out);
    return out;
}
void BinTree::inorderHelper(Node* curr, std::ostream& out) const {
    if (curr != nullptr) {
        inorderHelper(curr->left, out);
        out << *curr->data << " ";  // assuming NodeData has operator<<
        inorderHelper(curr->right, out);
    }
}
// ---------------------------- operator= ----------------------------------
// Deep copies the contents of another BinTree into this one.
BinTree& BinTree::operator=(const BinTree &otherTree) {
// deep copy the tree
    if(this == &otherTree) {
        return *this;
    }
    makeEmpty();
    root = copyTree(otherTree.root);
    return *this;
}
// ---------------------------- copyTree -----------------------------------
// Recursively deep copies the tree rooted at curr.
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
// ---------------------------- operator== ---------------------------------
// Returns true if two binary trees are structurally equal and store the same data.
bool BinTree::operator==(const BinTree &otherTree) const {
    return isEqual(this->root, otherTree.root);
} 

// ---------------------------- isEqual ------------------------------------
// Recursively checks if two subtrees are equal in structure and data.
bool BinTree::isEqual(Node *nodeA, Node *nodeB) const {
    if(nodeA == nullptr && nodeB == nullptr) {
        return true;
    }
    if ((nodeA == nullptr) != (nodeB == nullptr)){
        return false;
    }

    return *nodeA->data == *nodeB->data && isEqual(nodeA->left, nodeB->left) && isEqual(nodeA->right, nodeB->right);
}

// ---------------------------- operator!= ---------------------------------
// Returns true if two binary trees are not equal in structure or data.
bool BinTree::operator!=(const BinTree &otherTree) const {
    return !isEqual(this->root, otherTree.root);
}  
// ---------------------------- insert -------------------------------------
// Inserts a new NodeData into the tree. Returns false if duplicate.
bool BinTree::insert(NodeData *newData) {
    return insertHelper(root, newData);
}   
// ---------------------------- insertHelper -------------------------------
// Recursively inserts a new NodeData into the tree.
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
// ---------------------------- retrieve -----------------------------------
// Finds the NodeData in the tree that matches targetData.
// If found, sets foundData to point to the matching node's data and returns true.
// Otherwise, foundData is set to nullptr and returns false.           
bool BinTree::retrieve(const NodeData &targetData, NodeData *&foundData) const {
    return retrieveHelper(root, targetData, foundData);
} 
// ---------------------------- retrieveHelper -----------------------------
// Recursively finds targetData in the tree starting from curr.
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
// ---------------------------- getHeight ----------------------------------
// Returns the height of the node that matches targetData. 
// Returns 0 if the data is not found in the tree.
int BinTree::getHeight(const NodeData &targetData) const {
    int height = 0;
    getHeightHelper(root, targetData, height);
    return height;
}
// ---------------------------- getHeightHelper ----------------------------
// Recursively searches for targetData and returns its height in the tree.
int BinTree::getHeightHelper(Node *curr, const NodeData &targetData, int &maxHeight) const {
    if (curr == nullptr) return 0;

    int left = getHeightHelper(curr->left, targetData, maxHeight);
    int right = getHeightHelper(curr->right, targetData, maxHeight);

    if (*curr->data == targetData) {
        int h = nodeHeight(curr);
        maxHeight = std::max(maxHeight, h);
    }

    return std::max(left, right);  // This return value is unused
}
// ---------------------------- nodeHeight ---------------------------------
// Returns the height of the subtree rooted at curr.
int BinTree::nodeHeight(Node *curr) const{
    if(curr == nullptr) {
        return 0;
    }
    int leftH = nodeHeight(curr->left);
    int rightH = nodeHeight(curr->right);
    return max(leftH, rightH) + 1;  
}
// ---------------------------- bstreeToArrayHelper ------------------------
// Recursively transfers the BST into a sorted array and deletes nodes.
void BinTree::bstreeToArray(NodeData *dataArray[]) {
int index = 0;
bstreeToArrayHelper(root, dataArray, index);
root = nullptr;
}        
int BinTree::bstreeToArrayHelper(Node *curr, NodeData *dataArray[], int &index) {
    if(curr == nullptr) {
        return index;
    }

    bstreeToArrayHelper(curr->left, dataArray, index);

    dataArray[index++] = curr->data;
    curr->data = nullptr;

    bstreeToArrayHelper(curr->right, dataArray, index);

    delete curr;
    curr = nullptr;
    return index;
}
// ---------------------------- bstreeToArray ------------------------------
// Converts the BST into a sorted array of NodeData pointers and empties the tree.
void BinTree::arrayToBSTree(NodeData *dataArray[]) {
    int size = 0;
    while (dataArray[size] != nullptr) {
        size++;
    }

    // Clear existing tree
    makeEmpty();

    // Build BST
    root = arrayToBSTreeHelper(dataArray, 0, size - 1);

    // Null out array
    for (int i = 0; i < size; i++) {
        dataArray[i] = nullptr;
    }
}      
// ---------------------------- arrayToBSTreeHelper ------------------------
// Recursively builds a balanced BST from a sorted array between low and high indices.
BinTree::Node* BinTree::arrayToBSTreeHelper(NodeData* dataArray[], int low, int high) {
    if (low > high) {
        return nullptr;
    }

    int mid = (low + high) / 2;

    Node* curr = new Node();
    curr->data = dataArray[mid];

    curr->left = arrayToBSTreeHelper(dataArray, low, mid - 1);
    curr->right = arrayToBSTreeHelper(dataArray, mid + 1, high);

    return curr;
} 
// ---------------------------- displaySideways ----------------------------
// Displays the binary tree sideways, mainly for debugging purposes.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}