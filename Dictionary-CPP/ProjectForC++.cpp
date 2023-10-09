//The following Code is written by Petar Avramoski
// Student Number: 10549882 
//For class CSP2104.3
#include<iostream>
#include<string>
#include <fstream>
#include <vector> 
#include <algorithm> //using algorithim for case sensitivity issue. 

#include "Dictionary.h"
#include "ExtendedDictionary.h"



using namespace std;


//Function declarations below for all functions used. 
void menu();

//Written by Petar Avramoski, Student Number : 10549882
/*The main function purpose:
- Prompt user to open file, else if file does not exist opens default
- Has a menu that the user can use with multiple options with functionallity, that are called from other functions.
- The options are stored in aswitch statement
- Option 1: Asks user to enter a word to be found in the dictionary and prints it out along witht type and def
- Option 2: Asks user to input their own word in the dictionary and if they want to save it to a new file
- Option 3: Prints out all the words containg more that 3 z characthers in the dictionary
- Option 4: Print out all palindromes
- Option 5: Find the rhyming word with the users input of word 
- Option 6: Guess the fourth word game
- Option 7: Cheat of searchdle
- Option 8: CLOSE THE PROGRAM 
*/
int main()
{
    //string for name of file (dictionary) in directory
    string filename, foundWord, addName, addDef, addType;
    int option;
    char letter = 'z';
    ExtendedDictionary extDict;


    cout << "Enter the file name or just press enter for default: ";
    getline(cin, filename);
    if (filename.empty() || filename != "dictionary_2023S1.txt" || filename == "") {
        filename = "dictionary_2023S1.txt";
    }
    else {
        cout << "*FILE NOT FOUND*";
    }

    cout << "Attempting to read text file " << filename << endl;

    if (extDict.loadDictionary(filename)) {
        cout << "File loaded successfully" << endl;
    }
    else {
        cout << "Error loading file" << endl;
    };

    //for loop print, so that we can see whats been stored in the vector.
       //comoparing i to size of dictionary vector as it cant be any bigger than that
       //using for loop to iterate through the vector to read the name, def, type for the word.
       /*for (int i = 0; i < dict.dictionary.size(); i++)
       {
           cout << "name: " << dict.dictionary[i].name << endl;
           cout << "definition: " << dict.dictionary[i].definition << endl;
           cout << "type: " << dict.dictionary[i].type << endl;
       }*/

    bool run = true;
    //using a stwitch statment so that the user can choose which option they want.
    while (run)
    {
        //calling upon menu function to display menu.
        //menu in seperate function to make while loop cleaner.
        menu();
        cout << "Please enter your option 1-4; ";
        cin >> option;
        switch (option)
        {
        case 1: //OPTION 1: to display word that users enter from dictionary.
            cout << "You choose option 1. " << endl;
            cout << "Enter a word you want to find in this file e.g. barber or zebra: " << endl;
            cin >> foundWord;

            //transform is imported from <algorithm>
            //converting word that is being searched for to lower case using transform..
            transform(foundWord.begin(), foundWord.end(), foundWord.begin(), ::tolower);

            if (extDict.fWord(extDict.dictionary, foundWord))
            {
                //iterating through the dictionary so we can print the names corresponding type and definition 
                for (const auto& word : extDict.dictionary)
                {
                    string lowerCase = word.name;
                    //converting word.name to lower case.
                    transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
                    if (lowerCase == foundWord)
                    {
                        cout << "======================= " << endl;
                        cout << "Word has been found " << foundWord << endl;
                        cout << "Word Type: " << extDict.getWordType(word.type) << endl; //get word type function is being used so that it outputs the correct format scheme for word type.
                        cout << "Definition: " << word.definition << endl;
                        cout << "======================= " << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "Word has not been found" << endl;
            }
            break;

        case 2:
            cout << "*** You choose option 2 *** " << endl;
            cout << "Enter new word that you would like to add in the dictionary: " << endl;
            cin >> addName;
            //using ignore() so that the junk is cleared, otherwise the two other lines below appear at the same time, hence not letting the user enter the definition.
            //using transform function to turn new word into lower case.
            transform(addName.begin(), addName.end(), addName.begin(), ::tolower);
            cin.ignore();
            cout << "Enter the definition for this word: " << endl;
            getline(cin, addDef);
            cout << "Enter the word type e.g. noun: ";
            getline(cin, addType);
            extDict.addNDT(extDict.dictionary, addName, addDef, addType, filename);
            break;

        case 3:
            cout << "*** You choose option 3 ***" << endl;
            cout << "====================================" << endl;
            cout << "I will now print all words that contain 3 Z charachters" << endl;
            extDict.findZ(extDict.dictionary, letter);
            cout << "====================================" << endl;
            break;

        case 4:
            cout << "*** You choose option 4 ***" << endl;
            cout << "====================================" << endl;
            cout << "I will now print out all palindromes" << endl;
            extDict.listPalindromes();
            cout << "====================================" << endl;
            break;

        case 5: { //reason this case is in brackets is because error "transfer of control bypasses initialization" (bypassing the initilzation of a variable)
            cout << "*** You choose option 5 ***" << endl;
            cout << "====================================" << endl;
            cout << "Enter a word to find rhyming words: ";
            string inputWord;
            cin >> inputWord;
            extDict.findRhymingWords(inputWord);
            cout << "====================================" << endl;
            break;
        }

        case 6: {
            cout << "***** You chose Task 7 - Guess the Fourth Word *****" << endl;
            extDict.guessTheFourthWord();
            break;
        }

        case 7: {
            cout << "***** You chose Task 8 - Searchdle *****" << endl;
            extDict.searchWords();
            break;
        }

        case 8:
            cout << "***** YOU CHOSE TO END THE PROGRAM HOW DARE YOU *****" << endl;
            return false;


        default:
            cout << "*** INVALID OPTION - PLEASE TRY AGAIN ***" << endl;
            //reason for the 2 lines below, the while loop goes into an infinite loop if the wrong condition is entered.
            //hence why i am using clear and ignore so i can clear the input state and then ignore the junk that was invalid
            //therefor the while loop wont go into an infnifite loop if wrong input is entered
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    system("pause");

    return 0;
}
//****************************************************

//Menu function stated on its own to make the switch above clearer to read.
void menu()
{
    cout << "MENU:" << endl;
    cout << "Option 1: Display word " << endl;
    cout << "Option 2: Input your own " << endl;
    cout << "Option 3: Find words with the char Z " << endl;
    cout << "Option 4: Disply all palindromes " << endl;
    cout << "Option 5: Rhyming Words " << endl;
    cout << "Option 6: Guess the fourth word " << endl;
    cout << "Option 7: Cheat in Searchdle " << endl;
    cout << "8. EXIT THE PROGRAM" << endl;
}
