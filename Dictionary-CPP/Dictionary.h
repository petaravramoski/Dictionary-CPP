#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Word {

public:
    std::string name;
    std::string type;
    std::string definition;

};
//defining dictionary class
class Dictionary {
public:
    vector<Word> dictionary;

public:
    // Constructor
    Dictionary();

    // Method to load the dictionary file
    bool loadDictionary(const string& filename);

    // Other member functions
    bool fWord(const vector<Word>& dictionary, const string wFound);

    bool addNDT(vector<Word>& dictionary, const string name, const string definition, const string type, const string filename); //NDT = NAME DEF TYPE

    bool findZ(const vector<Word>& dictionary, char letter);

    string getWordType(const string& type);

};

#endif

