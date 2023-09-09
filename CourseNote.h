#ifndef REGISTRATION_HDR
#define REGISTRATION_HDR
#include <string>
using namespace std;

class COURSES
{
private:
  string name;
  int number;

public:
  // Default Constructor
  // initializes to defaults of name 'empty' and
  // number 000
  COURSES();

  // COURSES
  // pre-condition: receives specified data string courseName and int courseNum
  // post-condition: assigns data to courseName and courseNum
  COURSES(int courseNum, string courseName);

  // setName
  // pre-condition: receives string newName
  // post-condition: changes name of the course
  bool setName(string newName);

  // getName
  // pre-condition: receives nothing
  // post-condition: return data value as type string value
  string getName() const;

  // getNum
  // pre-condition: receives nothing
  // post-condition: return data value as type int value
  int getNum() const;

  // print
  // pre-condition: receives nothing
  // post-condition: print data value inside this Node.
  void print() const;
};

#endif