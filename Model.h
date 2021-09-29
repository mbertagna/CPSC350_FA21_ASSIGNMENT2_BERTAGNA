// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* Model.h is a header file which lays out the elements of the Model class. */

#include <iostream> //pre-processor directive
using namespace std;

class Model{
public:
  Model();// constructor
  ~Model();// destructor

  string translateSingleCharacter(char charInput);
  string translateDoubleCharacter(char doubleCharInput);
};
