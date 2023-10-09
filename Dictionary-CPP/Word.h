//The following Code is written by Petar Avramoski
//Student Number: 10549882 
//For class CSP2104.3
#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Written by Petar Avramoski, Student Number : 10549882
//Defining a class named Word that has three public variables name, type and definition
class Word {
public:
    string name;
    string type;
    string definition;
//These lines of code define the public memeber functions of the "Word class" 
//The default constuctor is set as Word() 
//And anohter constuctor is also set that takes 3 paramaters 
//The other functions defined are getters and setters and the last 4 functions are for the Task8 of the assingment. (Cheat at seacrdhle) 
public:
    Word() = default;
    Word(const string& name, const string& type, const string& definition);
    string getName() const;
    string getType() const;
    string getDefinition() const;
    void setName(const string& name);
    void setType(const string& type);
    void setDefinition(const string& definition);
    void printDefinition() const;

    bool hasSameLengthAs(const string& otherWord) const;
    bool containsAnyLetters(const string& letters) const;
    bool containsAllLetters(const string& letters) const;
    bool hasLettersAtPositions(const string& positions) const;

};
//This code defines the constuctor for the word class and takes three paramaters.
Word::Word(const string& name, const string& type, const string& definition)
    : name(name), type(type), definition(definition) {
}
//Written by Petar Avramoski, Student Number : 10549882
//#################################
//The next three functions are the getters and setters for the "Word" class
string Word::getName() const {
    return name;
}

string Word::getType() const {
    return type;
}

string Word::getDefinition() const {
    return definition;
}
//#################################

//Written by Petar Avramoski, Student Number : 10549882
//#################################
//The next three functions here are the setter functions for the Word Class.
void Word::setName(const string& name) {
    this->name = name;
}

void Word::setType(const string& type) {
    this->type = type;
}

void Word::setDefinition(const string& definition) {
    this->definition = definition;
}
//#################################

//Written by Petar Avramoski, Student Number : 10549882
void Word::printDefinition() const {
    cout << "Word: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Definition: " << definition << endl;
}

//Written by Petar Avramoski, Student Number : 10549882
//########### NOTE FOR LECTURER ############
// FUNCTIONS for task8 Cheat at searchdle 
//i have tried my best to get these functions to work in the ExtendedDictionary file but whenver i #include "Word.h" i get alot of errors 
//They work fine in anohter visual studio file/folder as i tried to implement them sepearatly first to get everything to work.
//i did some research and i think this error is due to circular dependency. I have tried my best to solve it and went over the due date to figure it out but still couldnt.
//So i would like to apologise. 

//In this functions we compare the length of thename member variable, if they are equal it return true.
bool Word::hasSameLengthAs(const string& otherWord) const {
    return name.length() == otherWord.length();
}

//First we iterate through each character letter in letters
//thyen we check if the current letter exits in name variable then the find function searched for the first occurance of that letter.
//If the letter is found then the condition is satisfied and it returns true.
bool Word::containsAnyLetters(const string& letters) const {
    for (char letter : letters) {
        if (name.find(letter) != string::npos) {
            return true;
        }
    }
    return false;
}
//This does the opposite of the top one. 
bool Word::containsAllLetters(const string& letters) const {
    for (char letter : letters) {
        if (name.find(letter) == string::npos) {
            return false;
        }
    }
    return true;
}

//First we iterate through the loop over each characther position in the positions string
//Then we convert the current position 
bool Word::hasLettersAtPositions(const string& positions) const {
    for (char position : positions) {
        int index = position - '0';  //Convert char to integer
        if (index >= 0 && index < name.length() && name[index] != ' ') {
            return true;
        }
    }
    return false;
}

#endif // WORD_H


