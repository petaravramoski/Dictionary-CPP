//The following Code is written by Petar Avramoski
// Student Number: 10549882 
//For class CSP2104.3
#include "Dictionary.h"
#include <fstream>
#include <iostream>


using namespace std;

Dictionary::Dictionary() {

}

//Written by Petar Avramoski, Student Number : 10549882
//Opening the file.
bool Dictionary::loadDictionary(const string& filename) {
    ifstream myfile(filename);
    if (myfile.is_open()) {
        Word word;
        string line;
        while (getline(myfile, line)) {
            if (line == "<word>") {
                getline(myfile, word.name);
                getline(myfile, word.definition);
                getline(myfile, word.type);
                dictionary.push_back(word);
            }
        }
        myfile.close();
        return true;
    }
    else {
        return false;
    }
}


//Written by Petar Avramoski, Student Number : 10549882
// Function to search through the dictionary for a word that the user has entered to find.
//We are using the & operator to reference the address of the vector.
//Using a const because the content of the vector arent going to change and arent supposed to change for this function. 
//vector<Word>& dictionary refrences the vector/struct we created above and passes it on as an input.
bool Dictionary::fWord(const vector<Word>& dictionary, const string wFound)
{
    //looping through the dictionary 
    for (const auto& word : dictionary)
    {
        if (word.name == wFound)
        {
            return true;
        }
    }
    return false;

}


//Written by Petar Avramoski, Student Number : 10549882
//function to add name, desc and type (NDT)
//in the previous function we had "vector<Word>& dictionary" as a const.
//here we change that because we will be modifying the .txt file.
bool Dictionary::addNDT(vector<Word>& dictionary, const string name, const string definition, const string type, const string filename)
{
    //we dont need to iterate thorugh it again as im already iterating through the dictionary in the main function.
    //so we can just call fword instaed of creating a forloop.

    Word newNDT;
    newNDT.name = name;
    newNDT.definition = definition;
    newNDT.type = type;
    dictionary.push_back(newNDT);

    // open the file for writing
    ofstream outfile(filename, ios::app);

    // write the updated dictionary to the file
    //Begin with <word> and end with </word> because thats how the .txt file is structured.
    //So it can also be read using the find word function
    outfile << "<word>" << endl;
    outfile << name << endl;
    outfile << definition << endl;
    outfile << type << endl;
    outfile << "</word>" << endl;

    outfile.flush();
    outfile.close(); // close the file

    //Prompt user to for yes or no to save to new file.
    char saveDict;
    cout << "The word has been added to the dictionary. Do you want to save the dictionary to a new file? (Y/N)" << endl;
    cin >> saveDict;
    if (saveDict == 'Y' || saveDict == 'y') {
        string newFilename;
        cout << "Enter the new filename (note: .txt will automatically be appended to the file): ";
        cin >> newFilename;
        //appending .txt to the new file.
        newFilename += ".txt";

        //Open the new file for writing and write the entire dictionary to it, specified by the user.
        ofstream newFile(newFilename);
        if (newFile.is_open()) {
            //iterate through the dictionary and add into new file.
            for (const auto& word : dictionary) {
                newFile << "<word>\n" << word.name << "\n" << word.definition << "\n" << word.type << "\n</word>\n";
            }
            newFile.close();
            cout << "Dictionary saved to " << newFilename << endl;
        }
        else {
            cout << "Error: Unable to save dictionary to " << newFilename << endl;
        }
    }

    return true;
}



//Written by Petar Avramoski, Student Number : 10549882
//Function to search for words in the dictionary that contain 3 'z' charachters 
//Using const as the vector will not be modified
//Using nested forloop to first iterate through the dictonary and then iterate through the word.
//Using a counter to count how many 'z' charchters there are in the word
bool Dictionary::findZ(const vector<Word>& dictionary, char letter)
{
    bool foundZ = false;

    for (const auto& word : dictionary)
    {
        // counter is here so that it iterates thorugh all the all the characthers in each word 
        // so that it can then count the number of times the letter 'z' appears in each word 
        int zCount = 0;

        for (const auto& c : word.name)
        {
            if (c == letter)
            {
                //looping through the words, if a word has the char 'z' then count.
                zCount++;
            }
        }
        // If the count variable previously is = to 3, it will initiate this if statement and print the word. 
        if (zCount == 3) // debug: change to 1 or 2 to see if it works, it works correctly as it prints words that contain 1 z and words that contain 2 z 
        {
            cout << "Here is a word that contains 3 Z chars: " << word.name << endl;
            foundZ = true; // return true if word has 3 z characthers
        }
    }
    return foundZ;
}

//Written by Petar Avramoski, Student Number : 10549882
//Function to print the correct word type scheme, when using option 1 in the menu.
string Dictionary::getWordType(const string& type)
{
    if (type == "Noun" || type == "noun" || type == "n") {
        return "[noun] ";
    }
    else if (type == "Verb" || type == "verb" || type == "v") {
        return "[verb] ";
    }
    else if (type == "Adverb" || type == "adverb" || type == "adv") {
        return "[adverb] ";
    }
    else if (type == "Adjective" || type == "adjective" || type == "adj") {
        return "[adjective] ";
    }
    else if (type == "Preposition" || type == "preposition" || type == "prep") {
        return "[preposition] ";
    }
    else if (type == "Miscellaneous" || type == "miscellaneous" || type == "misc") {
        return "[miscellaneous] ";
    }
    else if (type == "Proper Noun" || type == "proper noun" || type == "pn") {
        return "[proper noun] ";
    }
    else if (type == "Noun and Verb" || type == "noun and verb" || type == "n_and_v") {
        return "[noun and verb] ";
    }
    else {
        return "[unknown type] ";
    }
}

