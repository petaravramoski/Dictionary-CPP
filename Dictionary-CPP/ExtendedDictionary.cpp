//The following Code is written by Petar Avramoski
// Student Number: 10549882 
//For class CSP2104.3
#include "ExtendedDictionary.h"
#include<iostream>
#include<string>
#include <fstream>
#include <vector> 
#include <random>
#include <sstream> 
#include <algorithm> 




using namespace std;

//Written by Petar Avramoski, Student Number : 10549882
//extended dictionary class refrencing dictionary class to get all functionality 
ExtendedDictionary::ExtendedDictionary() : Dictionary() {

}

//Written by Petar Avramoski, Student Number : 10549882
//This function find all the palindromes in the dictionary
//First we loop through every word object in the dictionary vector
//Then we create a new string called reversed where word.name will be initialized
//Then we use the reverse function to reverse the word 
//Then we simply just compare it to the normal word and if == then print
void ExtendedDictionary::listPalindromes() const {
    cout << "Palindromes in the dictionary:" << endl;

    for (const auto& word : dictionary) {
        string reversed = word.name;
        reverse(reversed.begin(), reversed.end());
        if (reversed == word.name) {
            cout << word.name << endl;
        }
    }
}

//Written by Petar Avramoski, Student Number : 10549882
//This function will find rhyming words with the word that the user has entered. 
//First we iterate througn each dictWord object inside the dictionary vector.
//Then we check if both the name of the current dictWord object and the given word have a length of at least 3 characters
//Then we create two string variables: dictWordLastThreeLetters and inputWordLastThreeLetters, they store the last three letters of the name of the dict word and the given word.
//(Continue from line above) This is done by using the substr() function.
//Then we check if the dictWord and the given word are equal and if they are then it means that they rhyme and then print.
void ExtendedDictionary::findRhymingWords(const string& word) {
    cout << "Rhyming words for '" << word << "':" << endl;

    // Iterate through the dictionary and check for rhyming words
    for (const auto& dictWord : dictionary) {
        if (dictWord.name.length() >= 3 && word.length() >= 3) {
            string dictWordLastThreeLetters = dictWord.name.substr(dictWord.name.length() - 3);
            string inputWordLastThreeLetters = word.substr(word.length() - 3);

            if (dictWordLastThreeLetters == inputWordLastThreeLetters) {
                cout << dictWord.name << endl;
            }
        }
    }
}

//Written by Petar Avramoski, Student Number : 10549882
//TASK 6 To play the game guessTheFourthWord. 
//Code is explained in code blocks inside function.
void ExtendedDictionary::guessTheFourthWord() {

    int score = 0;
    int highScore = 0;

    cout << "Welcome to Guess the Fourth Word!" << endl;
    cout << "Current High Score: " << highScore << endl;

    // Generate a random index to select a word
    // First we create a random number generator using random_device (line 1 in block of code)
    // Then we initialize the generator using the Mersenne Twister algorithm called mt19937 (line 2 in block of code)
    // Next we define a uniform distribution that generates random integers within the range of the dictionary size (line 3 in block of code)
    // Finally we generate a random index using the distribution and store it in randomIndex for later use (line 4 in block of code)  
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, dictionary.size() - 1);
    int randomIndex = dis(gen);

    // Select a word with more than 4 words in its definition
    // First we create a empty word object called sletedWord. (line 1 in block of code)
    // We then use a do while loop. THis is to make sure that the following block of code is executed at least once and repeated untill the condition is met. 
    // Then we assing slectedWord with the random index in the dictionary
    // Then we select a new random word. This is done by using dis(gen) and then it assings it to randomIndex.
    // Finally the while line of code, check if the number of words in the definition is less than or equal to 4. If true the condition loops untill it finds one with more. 
    Word selectedWord;
    do {
        selectedWord = dictionary[randomIndex];
        randomIndex = dis(gen);
    } while (selectedWord.definition.size() - count(selectedWord.definition.begin(), selectedWord.definition.end(), ' ') <= 4);

    // Print the word and its definition with the fourth word replaced by underscores
    // "vector<string> words;" creates an empty vector to store the individual words from the definition that was randomly selecteed
    // The final line uses copy to iterate the words in the iss input stream. It reads each word and then inserts it into the "words" vector using "back_inserter" 
    // This essentially splits the defeniton into individual words and then stores them un the words vector. 
    vector<string> words;
    istringstream iss(selectedWord.definition);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));

    //Essentially the 2 lines of code below just replace the [3] index (fourth word) with underscores _____ (word that has to be guessed)
    string missingWord = words[3];
    words[3] = string(missingWord.length(), '_');

    cout << "Guess the missing word in the following definition:" << endl;
    cout << "Word: " << selectedWord.name << endl;
    cout << "Definition: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;

    // Prompt the player to enter their guess
    string playerGuess;
    cout << "Enter your guess: ";
    cin >> playerGuess;

    // Compare the player's guess with the actual missing word
    if (playerGuess == missingWord) {
        cout << "Congratulations! Your guess is correct." << endl;
        score += 10;

        if (score > highScore) {
            highScore = score;
            cout << "You beat the previous high score!" << endl;
        }
    }
    else {
        cout << "Sorry, your guess is incorrect" << endl;
    }

}

//Written by Petar Avramoski, Student Number : 10549882
void ExtendedDictionary::searchWords() const {

    cout << "*** Cheat at Searchdle ***" << std::endl;
    cout << "Enter the following parameters:" << std::endl;

    string mysteryWord;
    string excludeLetters;
    string requiredLetters;
    string requiredPositions;

    cout << "Mystery Word: ";
    cin >> mysteryWord;

    cout << "Exclude Letters: ";
    cin >> excludeLetters;

    cout << "Required Letters (anywhere): ";
    cin >> requiredLetters;

    cout << "Required Positions (green letters): ";
    cin >> requiredPositions;



}



