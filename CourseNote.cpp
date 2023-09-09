#include "CourseNote.h"
#include <iostream>
using namespace std;

// Default Constructor
// initializes to defaults of name 'empty' and
// number 000
COURSES::COURSES()
{
  this->name = "none";
  this->number = 000;
}

// COURSES
// pre-condition: receives specified data string courseName and int courseNum
// post-condition: assigns data to courseName and courseNum
COURSES::COURSES(int courseNum, string courseName)
{
  this->number = courseNum;
  this->name = courseName;
}

// setName
// pre-condition: receives string newName
// post-condition: changes name of the course
bool COURSES::setName(string newName)
{
  this->name = newName;
  return true;
}

// getName
// pre-condition: receives nothing
// post-condition: return data value as type string value
string COURSES::getName() const
{
  return this->name;
}

// getNum
// pre-condition: receives nothing
// post-condition: return data value as type int value
int COURSES::getNum() const
{
  return this->number;
}

// print
// pre-condition: receives nothing
// post-condition: print data value inside this Node.
void COURSES::print() const
{
  cout << this->number << "-" << this->name << endl;
}
