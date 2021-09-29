// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 2

/* Translator.cpp contains the implementation of the Translator class. It implements a constructor, a destructor, and four functions:
1) translateEnglishWord translates a English word string into a tutenese word string
2) translateEnglishSentence translates an English sentence string into a tutenese sentence string. It also uses functions from the Model class to facilitate functionality.
3) translateTutneseWord translates a Tutnese word string into a English word string
4) translateTutneseSentence  translates an Tutnese sentence string into a English sentence string. It also uses functions from the Model class to facilitate functionality.*/

#include "Translator.h"
#include "Model.h"

Translator::Translator(){
}
Translator::~Translator(){
}

// translates a single English word string into a tutenese word string
string Translator::translateEnglishWord(string wordInput){
  string tutneseWord = "";
  //create a model instance on the heap for use of its functions
  Model *model = new Model();

  //loop through each character of word
  for(int i = 0 ; i < wordInput.size() ; ++i){
    //if not double character (i.e. single character)
    if(tolower(wordInput[i]) != wordInput[i+1]){
      tutneseWord += model->translateSingleCharacter(wordInput[i]);
    }
    // if single character
    else{
      tutneseWord += model->translateDoubleCharacter(wordInput[i]);
      ++i;
    }
  }
  //delete instance from memory
  delete model;
  return tutneseWord;
}

// translates an English sentence string into a tutenese sentence string
string Translator::translateEnglishSentence(string sentenceInput){
    string tutneseSentence = "";

    // track the start and end index of the current word in the sentence
    int wordStartIndex = 0;
    int wordEndIndex = 0;

    // loop through the words (tracked by spaces) in the sentence until the sentence string contains no more spaces
    while(sentenceInput.find(" ", wordStartIndex) != string::npos/* represents end of string (value of -1) */){

      // find space after index of word start to get the index of the end of the word
      wordEndIndex = sentenceInput.find(" ", wordStartIndex);

      // extract the substring representing the word
      string englishWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);

      // translate english word to tutnese and add a space for separation with next word
      tutneseSentence += (translateEnglishWord(englishWord) + " ");

      // move to next word (search for next space in sentence string)
      wordStartIndex = wordEndIndex + 1;
    }

    // get the last word in the sentence that does not have space after it (its end index will be the size of the string)
    wordEndIndex = sentenceInput.size();
    string englishWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);
    // add it to the tutnese translation string without a space
    tutneseSentence += translateEnglishWord(englishWord);

    return tutneseSentence;
}

// translates a single Tutnese word string into a English word string
string Translator::translateTutneseWord(string wordStrInput){
  string tutneseSyllableStr = "";//stores Tutnese chars from word
  string englishWord = "";

  bool doubleLetter = false;//true if instance of squa or Squa found
  bool doubleIsUpper = false;//true if Squa found

  Model *model = new Model();

  int indexOfNextChar2Translate = 0;//saves next char index to be translated

  //iterates through chars in word searching for complete Tutnese syllables
  for(int index = 0 ; index < wordStrInput.size() ; ++index){

    tutneseSyllableStr += wordStrInput[index];//add char to Tutnese syllable string

    //check if == ex first because it is a special case: first letter "e" not represented by English translation "x" and is only 2 char Tutnese syllable
    if(tutneseSyllableStr == "ex"){
      //if Squa before
      if(doubleLetter == true && doubleIsUpper == true){
        englishWord += "Xx";
        doubleLetter = false;
        doubleIsUpper = false;
      }
      //if squa before
      else if(doubleLetter == true){
        englishWord += "xx";
        doubleLetter = false;
      }
      //if no squa or Squa before
      else{
        englishWord += "x";
      }
      tutneseSyllableStr = "";
      indexOfNextChar2Translate = index+1;//set index of next char to translate
    }

    //if == "Ex" add "X" to English word
    else if(tutneseSyllableStr == "Ex"){
      englishWord += "X";
      tutneseSyllableStr = "";
      indexOfNextChar2Translate = index+1;
    }

    //this if statement is very powerful, as it takes advantage of the fact that most Tutnese syllables (except for double chars (squa-) and x (ex))
    //start with the letter they translate to in English
    //therefore, it checks if the first letter of the Tutnese syllable translated to Tutnese == the given "possible" Tutnese syllable
    //if ==, then it return first letter of Tutnese syllable (i.e. English translation)
    else if((model->translateSingleCharacter(tutneseSyllableStr[0])) == tutneseSyllableStr){//checks if the first letter of the Tutnese syllable translated to Tutnese == the given "possible" Tutnese syllable
      if(tutneseSyllableStr != "e" && tutneseSyllableStr != "E"){//acounts for ex being special
        if(doubleLetter == true && doubleIsUpper == true){//if Squa before
          englishWord += toupper(tutneseSyllableStr[0]);
          englishWord += tutneseSyllableStr[0];
          doubleLetter = false;
          doubleIsUpper = false;
        }
        else if(doubleLetter == true){//if squa before
          englishWord += tutneseSyllableStr[0];
          englishWord += tutneseSyllableStr[0];
          doubleLetter = false;
        }
        else{//if no squa or Squa before
          englishWord += tutneseSyllableStr[0];
        }
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
      }
      else if(wordStrInput[index+1] != 'x'){//if letter is e but no x after then run as usual
        englishWord += tutneseSyllableStr[0];
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
      }
    }

    //check if syllable is squa or Squa
    else if(tutneseSyllableStr.size() > 3 && (tutneseSyllableStr == "squa" || tutneseSyllableStr == "Squa")) {//add uppercase
      doubleLetter = true;//save double char
      if(tutneseSyllableStr == "Squa"){//if Squa, save capitalization
        doubleIsUpper = true;
      }
      tutneseSyllableStr = "";
      indexOfNextChar2Translate = index+1;
    }

    //if double letter and uppercase and Tutnese double vowel (ta,te,ti,to,tu)
    else if( (doubleLetter == true && doubleIsUpper == true) && (tutneseSyllableStr == "ta" || tutneseSyllableStr == "te" || tutneseSyllableStr == "ti" || tutneseSyllableStr == "to" || tutneseSyllableStr == "tu") ){
      if(tutneseSyllableStr != "tu"){//accounts for squatut vs squatu which only happens with tu
        englishWord += toupper(tutneseSyllableStr[1]);//add uppercase and lowercase vowel to English word
        englishWord += tutneseSyllableStr[1];
        doubleLetter = false;
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
        doubleIsUpper = false;
      }
      else if(wordStrInput[index+1] != 't'){//if possible syllable == Squatu check for t after; if none, run as usual
        englishWord += toupper(tutneseSyllableStr[1]);//add uppercase and lowercase vowel to English word
        englishWord += tutneseSyllableStr[1];
        doubleLetter = false;
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
        doubleIsUpper = false;
      }
    }

    //if double letter and Tutnese double vowel (ta,te,ti,to,tu)
    else if( (doubleLetter == true) && (tutneseSyllableStr == "ta" || tutneseSyllableStr == "te" || tutneseSyllableStr == "ti" || tutneseSyllableStr == "to" || tutneseSyllableStr == "tu") ){
      if(tutneseSyllableStr != "tu"){//accounts for squatut vs squatu which only happens with tu
        englishWord += tutneseSyllableStr[1];//add double lowercase vowel to English word
        englishWord += tutneseSyllableStr[1];
        doubleLetter = false;
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
      }
      else if(wordStrInput[index+1] != 't'){//if possible syllable == squatu check for t after; if none, run as usual
        englishWord += tutneseSyllableStr[1];//add double lowercase vowel to English word
        englishWord += tutneseSyllableStr[1];
        doubleLetter = false;
        tutneseSyllableStr = "";
        indexOfNextChar2Translate = index+1;
      }
    }

    //final check is for punctution and numbers or out of Tutnese scope letters
    else if(tutneseSyllableStr.size() == 5 || (index + 1) == wordStrInput.size()){
      if(doubleLetter == true && doubleIsUpper == true){//very special case where squa not used in double letter content
        englishWord += "Squa";//add out of context Squa
        doubleIsUpper = false;
        doubleLetter = false;
      }
      else if(doubleLetter == true){//very special case where squa not used in double letter content
        englishWord += "squa";//add out of context squa
        doubleLetter = false;
      }
      englishWord += tutneseSyllableStr[0];//add first char of possible syllable string
      tutneseSyllableStr = "";
      index = indexOfNextChar2Translate++;//move word index back to index after first char(tutneseSyllableStr[0]) to translate and increment indexOfNextChar2Translate
    }
  }

  delete model;
  return englishWord;
}

// translates an Tutnese sentence string into a English sentence string
string Translator::translateTutneseSentence(string sentenceInput){
  string englishSentence = "";

  // track the start and end index of the current word in the sentence
  int wordStartIndex = 0;
  int wordEndIndex = 0;

  // loop through the words (tracked by spaces) in the sentence until the sentence string contains no more spaces
  while(sentenceInput.find(" ", wordStartIndex) != string::npos/* represents end of string (value of -1) */){

    // find space after index of word start to get the index of the end of the word
    wordEndIndex = sentenceInput.find(" ", wordStartIndex);

    // extract the substring representing the word
    string tutneseWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);

    // translate tutnese word to english and add a space for separation with next word
    englishSentence += (translateTutneseWord(tutneseWord) + " ");

    // move to next word (search for next space in sentence string)
    wordStartIndex = wordEndIndex + 1;
  }

  // get the last word in the sentence that does not have space after it (its end index will be the size of the string)
  wordEndIndex = sentenceInput.size();
  string tutneseWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);
  // add it to the english translation string without a space
  englishSentence += translateTutneseWord(tutneseWord);

  return englishSentence;
}
