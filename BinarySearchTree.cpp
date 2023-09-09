#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

// Default constructor
// Initializes tree to empty by setting tree's root to NULL
BinarySearchTree::BinarySearchTree()
{
  this->root = NULL;
}

// insert
// pre-condition: receive COURSES value to insert
// post-condition: descend tree with private method insertHelper
// to locate insertion place then return true if value
// is inserted successfuly, else return false.
bool BinarySearchTree::insert(COURSES value)
{
  if (value.getNum() == 0) // disallow course number = 0
  {
    cout << "\nInput fail. Course number must be > 0." << endl;
    return false;
  }
  if (this->root == NULL) // if empty tree, assign 1st value as root
  {
    Node *R = new Node(value);
    this->root = R;
  }
  if (this->root->getValue().getNum() == value.getNum())
    return true;
  else
  {
    bool insertResult = insertHelper(this->root, value);
    return insertResult;
  }
  return false;
}

// find
// pre-condition: receives type int keyCOURSES of object to find
// post-condition: utilize private method findHelper to return
// element object if value is found in tree;
// else, return element object set to invalid.
COURSES BinarySearchTree::find(int keyCOURSES)
{
  return findHelper(this->root, keyCOURSES);
}

// findLevelOf
// pre-condition: receives int keyCOURSES value to search for level.
// post-condition: utilize private method findLevelHelper and
// return level which keyCOURSES was found;
// else return -1 to indicate not found.
int BinarySearchTree::findLevelOf(int keyCOURSES)
{
  if (this->root->getValue().getNum() == keyCOURSES)
    return 0;
  return findLevelHelper(this->root, keyCOURSES, 0);
}

// getHeight
// pre-condition: receives nothing.
// post-condition: utilize private method heightHelper and return
// height of a binary tree; empty tree has height of 0.
int BinarySearchTree::getHeight() const
{
  return heightHelper(this->root);
}

// getBalanceFactor
// pre-condition: receives nothing.
// post-condition: utilize private method heightHelper to find
// height of left and right subtree then return
// balance factor of a binary tree.
int BinarySearchTree::getBalanceFactor() const
{
  // check left
  int leftSubHeight = heightHelper(this->root->getLeft());
  // check right
  int rightSubHeight = heightHelper(this->root->getRight());
  // compute balance factor
  int balanceFactor = leftSubHeight - rightSubHeight;
  return balanceFactor;
}

// printInOrder
// pre-condition: receives nothing
// post-condition: applies the inorder traversal with
// private method helperInOrder.
void BinarySearchTree::printInOrder() const
{
  helperInOrder(this->root);
}

// printPreOrder
// pre-condition: receives nothing
// post-condition: applies the preorder traversal with
// private method helperPreOrder.
void BinarySearchTree::printPreOrder() const
{
  helperPreOrder(this->root);
}

// printPostOrder
// pre-condition: receives nothing
// post-condition: applies the postorder traversal with
// private method helperPostOrder.
void BinarySearchTree::printPostOrder() const
{
  helperPostOrder(this->root);
}
