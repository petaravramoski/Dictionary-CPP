//The following Code is written by Petar Avramoski
// Student Number: 10549882 
//For class CSP2104.3
#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H

#include "Dictionary.h"


//Written by Petar Avramoski, Student Number : 10549882
class ExtendedDictionary : public Dictionary {
public:
    //Constructor
    ExtendedDictionary();

    //Other member functions specific to ExtendedDictionary
    void listPalindromes() const;

    void findRhymingWords(const std::string& word);

    void guessTheFourthWord();

    void searchWords() const;



};




#endif