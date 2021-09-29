// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* main.cpp contains the main method and creates an instance of the FileProcessor class in order to test its functionality.
It takes three command line arguements:
1) the name of English text file
2) the name of an Tutnese text file
3) the type of translation to be done:
    a) "E2T" = translate text in English text file to Tutnese and write translation to Tutnese text file
    b) "T2E" = translate text in Tutnese text file to English and write translation to English text file
*/

#include <iostream>
#include "FileProcessor.h"
using namespace std;

int main(int argc/*number of arguments*/, char** argv/*array*/){
  string englishFile = "";
  string tutneseFile = "";
  string translationType = "";

  // if user does not provide three command line aruguements, notify user
  if(argc < 4){
    cout << "ERROR: Please provide both an input and an output file name (in that order) as command line arguements." << endl;
    return -1;
  }
  // else, collect names of english and tutnese files and translation specification from command line arguements
  else{
    englishFile = argv[1];
    tutneseFile = argv[2];

    translationType = argv[3];

    if(translationType == "E2T"){
      // create instance of FileProcessor for function use
      FileProcessor *fp = new FileProcessor();

      // convert text in input file to Tutnese
      fp->processFile(englishFile, tutneseFile);

      // delete instance of FileProcessor
      delete fp;
    }
    else if(translationType == "T2E"){
      // create instance of FileProcessor for function use
      FileProcessor *fp = new FileProcessor();

      // convert text in input file to Tutnese
      fp->processFileT2E(englishFile, tutneseFile);

      // delete instance of FileProcessor
      delete fp;
    }
    else{
      cout << "ERROR: Please provide a valid translation type ('E2T' or 'T2E') as the third command line arguement." << endl;
    }

  }

  return 0;
}
