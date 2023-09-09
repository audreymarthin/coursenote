#ifndef BST_HDR
#define BST_HDR
#include "Node.h"

class BinarySearchTree
{
private:
  // PRIVATE DATA MEMBER
  Node *root;

  // PRIVATE HELPER METHODS
  // insertHelper
  // pre-condition: receive pointer R to root node and COURSES V value to insert
  // post-condition: descend tree to locate insertion place
  // then create new Node and links it as left and right child
  // of an existing Node
  // return true if value is inserted successfuly, else return false.
  bool insertHelper(Node *R, COURSES V)
  {
    if (R->getValue().getNum() > V.getNum())
    {
      if (R->getLeft() != NULL)
      {
        insertHelper(R->getLeft(), V);
      }
      else
      {
        Node *value = new Node(V);
        R->setLeft(value);
        return true;
      }
    }
    else
    {
      if (R->getRight() != NULL)
      {
        insertHelper(R->getRight(), V);
      }
      else
      {
        Node *value = new Node(V);
        R->setRight(value);
        return true;
      }
    }
    return false;
  }

  // findHelper
  // pre-condition: receives pointer to current Node and int target to find
  // post-condition: returns element object if value is found in tree;
  // else, return element object set to invalid.
  COURSES findHelper(Node *current, int target)
  {
    if (current == NULL)
      return COURSES();
    if (current->getValue().getNum() == target)
      return current->getValue();
    else if (current->getValue().getNum() < target)
      return findHelper(current->getRight(), target);
    else
      return findHelper(current->getLeft(), target);
  }

  // findLevelHelper
  // pre-condition: receives a Node* pointer R of binary tree root,
  // int target value to search for level, and int level to
  // indicate start level search.
  // post-condition: return level which target was found,
  // else return -1 to indicate not found.
  int findLevelHelper(Node *R, int target, int level) const
  {
    if (R == NULL)
      return -1;
    if (R->getValue().getNum() == target)
      return level;
    int leftSearch = findLevelHelper(R->getLeft(), target, level + 1);
    if (leftSearch > 0)
      return leftSearch;
    int rightSearch = findLevelHelper(R->getRight(), target, level + 1);
    return rightSearch;
  }

  // heightHelper
  // pre-condition: receives current a Node* pointer to a root
  // of a binary tree.
  // post-condition: return height of a binary tree;
  // empty tree has height of 0.
  int heightHelper(Node *R) const
  {
    if (R == NULL)
      return 0;
    else
    {
      int leftCheck = heightHelper(R->getLeft());
      int rightCheck = heightHelper(R->getRight());
      return 1 + max(leftCheck, rightCheck);
    }
  }

  // helperInOrder
  // pre-condition: receives current a Node* pointer to a Node
  // of a binary tree.
  // post-condition: applies the inorder traversal to visit
  // and print node values.
  void helperInOrder(Node *current) const
  {
    if (current != NULL)
    {
      // LEFT: recursively, repeat on left child
      helperInOrder(current->getLeft());
      // VISIT: process or print this current node.
      current->print();
      // RIGHT: recursively, repeat on right child
      helperInOrder(current->getRight());
    }
  }

  // helperPreOrder
  // pre-condition: receives current a Node* pointer to a Node
  // of a binary tree.
  // post-condition: applies the preorder traversal to visit
  // and print node values.
  void helperPreOrder(Node *current) const
  {
    if (current != NULL)
    {
      // VISIT: process or print this current node.
      current->print();
      // LEFT: recursively, repeat on left child
      helperPreOrder(current->getLeft());
      // RIGHT: recursively, repeat on right child
      helperPreOrder(current->getRight());
    }
  }

  // helperPostOrder
  // pre-condition: receives current a Node* pointer to a Node
  // of a binary tree.
  // post-condition: applies the postorder traversal to visit
  // and print node values.
  void helperPostOrder(Node *current) const
  {
    if (current != NULL)
    {
      // LEFT: recursively, repeat on left child
      helperPostOrder(current->getLeft());
      // RIGHT: recursively, repeat on right child
      helperPostOrder(current->getRight());
      // VISIT: process or print this current node.
      current->print();
    }
  }

public:
  // Default constructor
  // Initializes tree to empty by setting tree's root to NULL
  BinarySearchTree();

  // insert
  // pre-condition: receive COURSES value to insert
  // post-condition: descend tree with private method insertHelper
  // to locate insertion place then return true if value
  // is inserted successfuly, else return false.
  bool insert(COURSES V);

  // find
  // pre-condition: receives type int keyCOURSES of object to find
  // post-condition: utilize private method findHelper to return
  // element object if value is found in tree;
  // else, return element object set to invalid.
  COURSES find(int keyCOURSES);

  // findLevelOf
  // pre-condition: receives int keyCOURSES value to search for level.
  // post-condition: utilize private method findLevelHelper and
  // return level which keyCOURSES was found;
  // else return -1 to indicate not found.
  int findLevelOf(int keyCOURSES);

  // getHeight
  // pre-condition: receives nothing.
  // post-condition: utilize private method heightHelper and return
  // height of a binary tree; empty tree has height of 0.
  int getHeight() const;

  // getBalanceFactor
  // pre-condition: receives nothing.
  // post-condition: utilize private method heightHelper to find
  // height of left and right subtree then return
  // balance factor of a binary tree.
  int getBalanceFactor() const;

  // printInOrder
  // pre-condition: receives nothing
  // post-condition: applies the inorder traversal with
  // private method helperInOrder.
  void printInOrder() const;

  // printPreOrder
  // pre-condition: receives nothing
  // post-condition: applies the preorder traversal with
  // private method helperPreOrder.
  void printPreOrder() const;

  // printPostOrder
  // pre-condition: receives nothing
  // post-condition: applies the postorder traversal with
  // private method helperPostOrder.
  void printPostOrder() const;
};

#endif