// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* Translator.h is a header file which lays out the elements of the Translator class. */

#include <iostream> //pre-processor directive
using namespace std;

class Translator{
public:
  Translator();
  ~Translator();

  string translateEnglishWord(string wordStrInput);
  string translateEnglishSentence(string sentenceStrInput);

  string translateTutneseWord(string wordStrInput);
  string translateTutneseSentence(string sentenceStrInput);
};
