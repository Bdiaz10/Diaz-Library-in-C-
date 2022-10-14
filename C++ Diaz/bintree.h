// Class BinTree
// This BinTree Object Holds Nodes based on their Data
#include "book.h"
#include "childrens_book.h"
#include "periodical_book.h"
#include "fiction_book.h"
#include <iostream>
using namespace std;
#ifndef BIN_TREE_H
#define BIN_TREE_H

//----------------------------------------------------------------------------
// BinTree:
// Defined as a container for Nodes in which each node has a 
// MAXIMUM of two child nodes and a max of 1 parent Node. Each Node
// contains a pointer (NodeData) to its data. Node data for this exercise
// will contain strings. Nodes in the tree are organized by their data
// values. Data values less than the root will be stored in the left
// subtree while values more than the root will be stored in the right
// subtree. String Data is organized in alphabetical order.
// example: string1 = "a" string2 = "b"
// string1 < string2
//
// Implementation and Assumptions:
//  -- Must have access to nodedata class
//  -- Node is stored in a struct within BinTree
//  -- When a bintree is created it is empty by having a root point to nullptr
//  -- BinTree will not contain nodes with duplicate data
//  -- Values less than the root are stored in the left subtree
//  -- Values more than the root are stored in the right subtree
//  -- Calling ostream will display tree in order (least to greatest)

class BinTree {

public:
  // Default Consructor initially creates empty tree
  BinTree();

  // Destructor- calls makeEmpty()
  ~BinTree();

  // is empty
  bool isEmpty() const;

  // Clears all values in BinTree
  void makeEmpty();

  // insert
  bool insert(Book *);

  // retreive
  Book* retrieveFiction(const FictionBook &) const;

  Book* retrievePeriodical(const PeriodicalBook &) const;

  Book* retrieveChildren(const ChildrensBook &) const;

  // display in order
  void displayInOrder() const;

private:
  struct Node {
    Book *data;
    Node *left;
    Node *right;

    // default constructor nulls all values
    Node() {
      left = right = nullptr;
      data = nullptr;
    }

    // parameter constructor initialzes data
    Node(Book *data) : data(data) { left = right = nullptr; }

    //node destructor
    ~Node(){
      delete data;
      delete left;
      delete right;

      data = nullptr;
      left = right = nullptr;
    }
  };

  // pointer to root of BinTree
  Node *root;

  //----------------------------------------------------------------------------
  // PRIVATE HELPER FUNCTIONS
  // make empty recursive helper
  void makeEmpty(Node *&);
  
  void displayInOrder(Node *) const;
 
};

#endif
