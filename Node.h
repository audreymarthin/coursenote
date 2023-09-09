/*
 * Node --- In file Node.h (interface/header)
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

#ifndef NODE_HDR
#define NODE_HDR
#include "CourseNote.h"

// define the NULL symbol to be the undefined
// memory address 0.
#ifndef NULL
#define NULL 0
#endif

class Node
{
private:
  COURSES value;
  Node *left;
  Node *right;

public:
  // Default Constructor
  // post-condition: initializes to defaults of data empty and
  // left and right both to NULL
  Node();

  // Node
  // pre-condition: receives specified data value
  // post-condition: assigns data to given value and
  // sets left and right both to NULL
  Node(COURSES value);

  // setLeft
  // pre-condition: receives pointer to another Node
  // post-condition: assigns left to otherNode's pointer
  void setLeft(Node *otherNode);

  // setRight
  // pre-condition: receives pointer to another Node
  // post-condition: assigns right to otherNode's pointer
  void setRight(Node *otherNode);

  // getValue
  // pre-condition: receives nothing
  // post-condition: return data value as a type class COURSES value
  COURSES getValue() const;

  // getLeft
  // pre-condition: receives nothing
  // post-condition: return pointer to left child Node.
  // Value of NULL means there is no left child.
  Node *getLeft() const;

  // getRight
  // pre-condition: receives nothing
  // post-condition: return pointer to right child Node.
  // Value of NULL means there is no right child.
  Node *getRight() const;

  // print
  // pre-condition: receives nothing
  // post-condition: prints data value inside this Node.
  void print() const;
};

#endif