/*
 * Node --- In file Node.cpp (implementation)
 *
 * Represents one node of a binary tree structure.
 * A Node HAS-A
 *   data - character data value for this example
 *   left - pointer to left child Node
 *   right - pointer to right child Node
 *
 * Example binary tree constructed from three Nodes.
 *
 *              root ------>[ 'R' ]
 *                     left /     \ right
 *                         /       \
 *                     ['P']       ['T']
 *
 * Example usage:
 * Let root be a Node* pointer to a Node.
 *     Node* leftChildPtr = root->getLeft();
 *     if(leftChildPtr != NULL)
 *       cout << "Left is " << leftChildPtr->getData();
 */

#include "Node.h"
#include <iostream>
using namespace std;

// Default Constructor
// post-condition: initializes to defaults of data empty and
// left and right both to NULL
Node::Node()
{
  this->value = COURSES();
  this->left = NULL;
  this->right = NULL;
}

// Node
// pre-condition: receives specified data value
// post-condition: assigns data to given value and
// sets left and right both to NULL
Node::Node(COURSES value)
{
  this->value = value;
  this->left = NULL;
  this->right = NULL;
}

// setLeft
// pre-condition: receives pointer to another Node
// post-condition: assigns left to otherNode's pointer
void Node::setLeft(Node *otherNode)
{
  this->left = otherNode;
}

// setRight
// pre-condition: receives pointer to another Node
// post-condition: assigns right to otherNode's pointer
void Node::setRight(Node *otherNode)
{
  this->right = otherNode;
}

// getValue
// pre-condition: receives nothing
// post-condition: return data value as a type class COURSES value
COURSES Node::getValue() const
{
  return this->value;
}

// getLeft
// pre-condition: receives nothing
// post-condition: return pointer to left child Node.
// Value of NULL means there is no left child.
Node *Node::getLeft() const
{
  return this->left;
}

// getRight
// pre-condition: receives nothing
// post-condition: return pointer to right child Node.
// Value of NULL means there is no right child.
Node *Node::getRight() const
{
  return this->right;
}

// print
// pre-condition: receives nothing
// post-condition: prints data value inside this Node.
void Node::print() const
{
  this->value.print();
}