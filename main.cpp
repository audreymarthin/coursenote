#include <iostream>
using namespace std;

// Binary Tree Node HAS-A value and left and right child Node* pointers.
#include "BinarySearchTree.h"

/* Design Documentation
 *
 * #1 TEST CASE 1
 *        root ------>[(350, 'Algorithm')]
 *                     left /     \ right
 *                         /       \
 *           [(200, 'Data')]       [(370, 'Machine')]
 *                     /               \
 *      [(100, 'Intro')]               [(400, 'Capstone')]
 *
 * Test case expected inorder traversal output:
 * (100, 'Intro'), (200, 'Data'), (350, 'Algorithm'),
 * (370, 'Machine'), (400, 'Capstone')
 *
 * Test case expected preorder traversal output:
 * (350, 'Algorithm'), (200, 'Data'), (100, 'intro'),
 * (370, 'Machine'), (400, 'Capstone')
 *
 * Test case expected postorder traversal output:
 * (100, 'intro'), (200, 'Data'), (400, 'Capstone'),
 * (370, 'Machine'), (350, 'Algorithm')
 *
 * #2 TEST CASE 2
 *       root ------>[(350, 'Algorithm')]
 *                     left /     \ right
 *                         /       \
 *           [(100, 'Intro')]      [(400, 'Capstone')]
 *                        \         /
 *              [(200, 'Data')]  [(370, 'Machine')]
 *
 * Test case expected inorder traversal output:
 * (100, 'intro'), (200, 'Data'), (350, 'Algorithm'),
 * (370, 'Machine'), (400, 'Capstone')
 *
 * Test case expected preorder traversal output:
 * (350, 'Algorithm'), (100, 'intro'), (200, 'Data'),
 * (400, 'Capstone'), (370, 'Machine')
 *
 * Test case expected postorder traversal output:
 * (200, 'Data'), (100, 'intro'), (370, 'Machine')
 * (400, 'Capstone'), (350, 'Algorithm')
 *
 * #3 TEST CASE 3
 *       root ------>[(350, 'Algorithm')]
 *                     left /     \ right
 *                         /       \
 *           [(100, 'Intro')]      [(400, 'Capstone')]
 *                        \
 *              [(200, 'Data')]
 *
 * Expected height output: 3
 * Expected balance factor output:
 * = left subtree - right subtree = 2 - 1 = 1
 *
 * #4 TEST CASE 4
 *       root ------>[(350, 'Algorithm')]
 *                     left /     \ right
 *                         /       \
 *           [(100, 'Intro')]      [(400, 'Capstone')]
 *                                  /
 *                                [(370, 'Machine')]
 *
 * Expected height output: 3
 * Expected balance factor output:
 * = left subtree - right subtree = 1 - 2 = -1
 *
 * #5 TEST CASE 5
 *       root ------>[(350, 'Algorithm')]
 *                     left /     \ right
 *                         /       \
 *           [(100, 'Intro')]      [(400, 'Capstone')]
 *
 * Expected height output: 2
 * Expected balance factor output:
 * = left subtree - right subtree = 1 - 1 = 0
 *
 * #6 TEST CASE 6
 * - Best Case Retrieval
 * root --> (350, 'Algorithm') and target key to search 350 so O(1)
 * or tree is balanced so O(log(n))
 * - Worst Case Retrieval
 *        root ------>[(350, 'Algorithm')]
 *                     left /
 *                         /
 *           [(200, 'Data')]
 *                     /
 *      [(100, 'Intro')]
 * Tree unbalanced and have no right child.
 * Height close to # of nodes and target key to search 100
 * have to traverse deepest node so O(n)
 *
 * #7 TEST CASE 6
 * - Best Case Insertion
 * root --> NULL and value to insert (350, 'Algorithm').
 * value inserted on top and becomes root so O(1)
 * or tree is balanced so O(log(n))
 * - Worst Case Insertion
 *        root ------>[(350, 'Algorithm')]
 *                     left /
 *                         /
 *           [(200, 'Data')]
 *                     /
 *      [(100, 'Intro')]
 * Tree unbalanced and have no right child.
 * Height close to # of nodes and target value to insert
 * [(50, 'PreCourse')] and have to traverse till deepest node so O(n)
 */

int main()
{
  cout << "\n////////////////////////////" << endl;
  cout << "\nBINARY SEARCH TREE PROGRAM" << endl;
  cout << "\n////////////////////////////" << endl;
  cout << endl;

  // INTRODUCTION
  cout << "\nThis tree stores courses information that users want to keep note of." << endl;
  cout << "\nYou can insert courses with their number and name." << endl;

  // START PROGRAM
  cout << "\nPlease type 'yes' in lowercase to begin: " << endl;
  string command;
  cin >> command;

  // CREATE BST
  BinarySearchTree Course_interest;

  // INSERTING
  int number;
  string name;

  cout << "\n--------------------" << endl;
  cout << "INSERT COURSES" << endl;
  cout << "--------------------" << endl;

  while (command != "no")
  {
    cout << "\nCourse Number: ";
    cin >> number;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n'); // found hint at stackOverflow
      cout << "\nInput unrecognized. Must be number." << endl;
      cout << "\nCourse Number: ";
      cin >> number;
    }
    cout << "\nCourse Name: ";
    cin >> name;

    COURSES course = COURSES(number, name);
    Course_interest.insert(course);

    cout << "\nWould you like to continue? (yes/no)" << endl;
    cin >> command;
  }
  cout << "\nCourse inserting concluded." << endl;

  // TRAVERSAL
  cout << "\n--------------------" << endl;
  cout << "TREE VALUE TRAVERSAL" << endl;
  cout << "--------------------" << endl;

  cout << "\nInorder Traversal" << endl;
  Course_interest.printInOrder();

  cout << "\nPreorder Traversal" << endl;
  Course_interest.printPreOrder();

  cout << "\nPostorder Traversal" << endl;
  Course_interest.printPostOrder();

  // FIND VALUE
  int targetKey;
  COURSES result;
  int levelFound;
  command = "yes";

  cout << "\n--------------------" << endl;
  cout << "SEARCH COURSES" << endl;
  cout << "--------------------" << endl;

  while (command != "no")
  {
    cout << "\nCourse Number: ";
    cin >> targetKey;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n'); // found hint at stackOverflow
      cout << "\nInput unrecognized. Must be number." << endl;
      cout << "\nCourse Number: ";
      cin >> number;
    }
    result = Course_interest.find(targetKey);
    levelFound = Course_interest.findLevelOf(targetKey);

    if (result.getNum() > 0)
    {
      cout << "Yes, course " << targetKey << " is in tree. Information:" << endl;
      result.print();
      if (levelFound == 0)
        cout << "Found at level " << levelFound << " (root)" << endl;
      else
        cout << "Found at level " << levelFound << endl;
    }
    else
      cout << "Sorry, course " << targetKey << " is not found." << endl;

    cout << "\nWould you like to continue? (yes/no)" << endl;
    cin >> command;
  }
  cout << "\nCourse searching concluded." << endl;

  // HEIGHT AND BALANCE FACTOR
  cout << "\n-------------------------------" << endl;
  cout << "BINARY SEARCH TREE INFORMATION" << endl;
  cout << "-------------------------------" << endl;
  cout << "\nHeight is " << Course_interest.getHeight() << endl;
  cout << "Balance factor is " << Course_interest.getBalanceFactor() << endl;

  // ENDING
  cout << "\nThank you for using our program. See you next time!" << endl;

  return 0;
}