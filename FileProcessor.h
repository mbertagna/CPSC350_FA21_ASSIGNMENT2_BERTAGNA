// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* FileProcessor.h is a header file which lays out the elements of the FileProcessor class. */

#include <iostream> //pre-processor directive
#include <fstream>
using namespace std;

class FileProcessor{
public:
  FileProcessor();
  ~FileProcessor();

  void processFile(string inputFileName, string outputFileName);
  void processFileT2E(string englishFileName, string tutneseFileName);
};
