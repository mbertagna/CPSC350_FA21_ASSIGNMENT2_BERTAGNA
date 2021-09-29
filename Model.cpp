// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* Model.cpp contains the implementation of the Model class. It implements a constructor, a destructor, and two functions:
translateSingleCharacter translates a single English character into a tutenese string; translateDoubleCharacter translates a
single English character that appears twice in a row in a word into a tutnese string. */

#include "Model.h"

Model::Model(){
}
Model::~Model(){
}

// translates a single English character to a tutenese string
string Model::translateSingleCharacter(char charInput){
  string tutneseString = "";
  //lowercase consonant translation
  switch(charInput){
    case 'b':
      tutneseString += "bub";
      break;
    case 'c':
      tutneseString += "cash";
      break;
    case 'd':
      tutneseString += "dud";
      break;
    case 'f':
      tutneseString += "fuf";
      break;
    case 'g':
      tutneseString += "gug";
      break;
    case 'h':
      tutneseString += "hash";
      break;
    case 'j':
      tutneseString += "jay";
      break;
    case 'k':
      tutneseString += "kuck";
      break;
    case 'l':
      tutneseString += "lul";
      break;
    case 'm':
      tutneseString += "mum";
      break;
    case 'n':
      tutneseString += "nun";
      break;
    case 'p':
      tutneseString += "pub";
      break;
    case 'q':
      tutneseString += "quack";
      break;
    case 'r':
      tutneseString += "rug";
      break;
    case 's':
      tutneseString += "sus";
      break;
    case 't':
      tutneseString += "tut";
      break;
    case 'v':
      tutneseString += "vuv";
      break;
    case 'w':
      tutneseString += "wack";
      break;
    case 'x':
      tutneseString += "ex";
      break;
    case 'y':
      tutneseString += "yub";
      break;
    case 'z':
      tutneseString += "zub";
      break;
  //uppercase consonant translation
    case 'B':
      tutneseString += "Bub";
      break;
    case 'C':
      tutneseString += "Cash";
      break;
    case 'D':
      tutneseString += "Dud";
      break;
    case 'F':
      tutneseString += "Fuf";
      break;
    case 'G':
      tutneseString += "Gug";
      break;
    case 'H':
      tutneseString += "Hash";
      break;
    case 'J':
      tutneseString += "Jay";
      break;
    case 'K':
      tutneseString += "Kuck";
      break;
    case 'L':
      tutneseString += "Lul";
      break;
    case 'M':
      tutneseString += "Mum";
      break;
    case 'N':
      tutneseString += "Nun";
      break;
    case 'P':
      tutneseString += "Pup";
      break;
    case 'Q':
      tutneseString += "Quack";
      break;
    case 'R':
      tutneseString += "Rug";
      break;
    case 'S':
      tutneseString += "Sus";
      break;
    case 'T':
      tutneseString += "Tut";
      break;
    case 'V':
      tutneseString += "Vuv";
      break;
    case 'W':
      tutneseString += "Wack";
      break;
    case 'X':
      tutneseString += "Ex";
      break;
    case 'Y':
      tutneseString += "Yub";
      break;
    case 'Z':
      tutneseString += "Zub";
      break;
    //default case for vowels and punctuation (remain the same)
    default:
      tutneseString += charInput;
      break;
  }
  return tutneseString;
}

// translates a single character that appears twice in a row in a word
string Model::translateDoubleCharacter(char doubleCharInput){
  string tutneseString = "";
  char doubleCharLower = tolower(doubleCharInput);

  //if double character is uppercase
  if(doubleCharLower != doubleCharInput){
    tutneseString = "Squa";
  }
  //if double character is lowercase
  else{
    tutneseString = "squa";
  }

  //if vowel
  if(doubleCharLower == 'a' || doubleCharLower == 'e' || doubleCharLower == 'i' || doubleCharLower == 'o' || doubleCharLower == 'u'){
    tutneseString+="t";
  }

  //translate and add single char
  tutneseString += translateSingleCharacter(doubleCharLower);

  return tutneseString;
}
