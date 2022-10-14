// BinTree implementation File
// Braxton Diaz

#include "bintree.h"

//----------------------------------------------------------------------------
// BinTree
// Default Consructor initially creates empty tree
BinTree::BinTree() : root(nullptr) {}


//----------------------------------------------------------------------------
// ~BinTree()
// Destructor calls makeEmpty()
BinTree::~BinTree() { makeEmpty(); }

//----------------------------------------------------------------------------
// isEmpty()
bool BinTree::isEmpty() const{
  if (root == nullptr){
    return true;
  }else{
    return false;
  }
}


//----------------------------------------------------------------------------
// makeEmpty()
// deletes all memory in BinTree
// isEmpty returns true
void BinTree::makeEmpty() {
  makeEmpty(root);
  
}
// make empty helper function
void BinTree::makeEmpty(Node *&root) {
  // base case empty tree
  if (root != nullptr) {

    // recurse left and right subtree
    if (root->left != nullptr) {
      makeEmpty(root->left);
    }
    if (root->right != nullptr) {
      makeEmpty(root->right);
    }

    // once at a leaf, delete node and set to nullptr
    delete root;
    root = nullptr;
  }
}


//----------------------------------------------------------------------------
// insert()
// returns bool: true if successfull, false if data already exists
bool BinTree::insert(Book *dataptr) {
  Node *ptr = new Node; // exception is thrown if memory is not allocated
  ptr->data = dataptr;
  dataptr = nullptr;
  ptr->left = ptr->right = nullptr;
  if (isEmpty()) {
    root = ptr;
  } else {
    Node *current = root;
    bool inserted = false;

    // if item is less than current item, insert in left subtree,
    // otherwise insert in right subtree
    while (!inserted) {
      if (*ptr->data < *current->data) {
        if (current->left == nullptr) { // at leaf, insert left
          current->left = ptr;
          inserted = true;
        } else
          current = current->left; // one step left
      } else if (*ptr->data > *current->data) {
        if (current->right == nullptr) { // at leaf, insert right
          current->right = ptr;
          inserted = true;
        } else
          current = current->right; // one step right
      } else {
        return false; // if its a duplicate return false
      }
    }
  }
  return true;
}
//----------------------------------------------------------------------------
// retrieve()
// Retrieve a * of a given object in tree
// returns true if found
// second parameter will point to actuall object if found
// if not found, second parameter points to nullptr
Book* BinTree::retrieveFiction(const FictionBook &target) const{
  
  Node *current = root;

  // traverse tree
  while (current != nullptr) {
    if (target > (*current->data)) {
      // if target is more than current, check right subtree
      current = current->right;
    } else if (target < (*current->data)){
      // if target is less than current, check left subtree
      current = current->left;
    } else if (target == (*current->data)) {
      
      return current->data;
    } else {
      //return nullptr;
    }

  }

  return nullptr;
  
  
}
//----------------------------------------------------------------------------
// retreive childresn book
Book* BinTree::retrieveChildren(const ChildrensBook &target) const{
  
  Node *current = root;

  // traverse tree
  while (current != nullptr) {
    if (target > (*current->data)) {
      // if target is more than current, check right subtree
      current = current->right;
    } else if (target < (*current->data)){
      // if target is less than current, check left subtree
      current = current->left;
    } else if (target == (*current->data)) {
      
      return current->data;
    } else {
      //return nullptr;
    }

  }

  return nullptr;
  
  
}
//----------------------------------------------------------------------------
// retrievePeriodical()
// takes in year, month, target
Book* BinTree::retrievePeriodical(const PeriodicalBook &target) const{
  
  Node *current = root;

  // traverse tree
  while (current != nullptr) {
    if (target > (*current->data)) {
      // if target is more than current, check right subtree
      current = current->right;
    } else if (target < (*current->data)) {
      // if target is less than current, check left subtree
      current = current->left;
    } else if (target == (*current->data)) {
      
      return current->data;
    } else {
      //return nullptr;
    }

  }

  return nullptr;
}


//----------------------------------------------------------------------------
void BinTree::displayInOrder() const{
  displayInOrder(root);
}


void BinTree::displayInOrder(Node *root) const {
  if (root == nullptr) {
    return;
  }
  // left subtree
  displayInOrder(root->left);
  // once at target, out its data
  (*(root->data)).displayBook();
  // right subtree
  displayInOrder(root->right);
}