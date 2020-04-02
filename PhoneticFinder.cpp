#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic
{

/**
 * @param text : string type text, ,must contain only english alphabet and whitespaces (otherwise undefined) , throws exception if empty .
 * @param word : string type word , must contain only english alphabet and whitespaces (otherwise throws exeption) , that is to be found in the text,throws exception if empty.
 * This function finds the first occurrence of a given "word" in a given "text" , and return it as is from the text. 
 * The function is not case sensetive.
 * The function allows certian typos being made in the text , as described in the assingment:
 *  https://github.com/RoieJinx/phonetic-search-a/blob/master/README.md
 * @return : returns a string , which is the first
 */
string find(string text, string word)
{
    
    if (word.length() == 0) // Check empty text
    {
        string errorMessage1 = string("No words found in text");
        throw runtime_error(errorMessage1);
    }

    // Change word and text into a lower case for convinions
    string originalWord = word;
    string lowword = wordlowercase(word);
    text = text + ' '; // Added delimiter for partition.

    // Init vector of strings , which are words from the text.
    vector<string> wordsArray = wordsfromt(text); 
    int numOfWords = wordsArray.size();
    if (numOfWords == 0) // Check empty text
    {
        string errorMessage2 = string("No words found in text");
        throw runtime_error(errorMessage2);
    }
    bool found = false; // For match found use.

    // Check if any word in my txt match
    for (int i = 0; i < numOfWords ; i++)
    { 
        // Check only on words with matching size
        if(lowword.length() == wordsArray[i].length())
        {
          int match = checkWord(lowword,wordsArray[i]);
          if( match == 0 ) // wordFound!
          {
              found = true;
              //cout << "Found the word "<<wordsArray[i] << endl;
                return wordsArray[i];
          } 
               
        }
        
    }

    if (!found) // if no word was found !
    {
        string errorMessage3 = string("Did not find the word ") + word + (" in the text");
        throw runtime_error(errorMessage3);
    }

    return "no";
}






/**
 * @param text :string.
 * This method will split the text by the delimiter whitespace " " , and store the separeted words in a vector
 * @return vector<string> : made by 
 */
vector<string> wordsfromt(string text)
{
    int index = 0;
    int i = 0;
    vector<string> wordsfromtext;
    for (int i = 0; i < text.size(); i++)
    {
        if (text.at(i) == ' ')
        {
            wordsfromtext.push_back(text.substr(index, (i - index)));
            index = i + 1;
        }
    }
    return wordsfromtext;
}

/**
 * @param word : string representing a word , only english alphabet allowed!
 * This method turns any uppercase char to lowercase contained in the string "word"
 * @return string with only lowercase chars
 */
string wordlowercase(string word)
{
    for (size_t i = 0; i < word.length(); i++)
    {
        char low = word.at(i);
        word.at(i) = tolower(low);
    }
    return word;
}

//change text into lower case
string textlowercase(string text)
{
    string tempText = text;
    for (size_t i = 0; i < tempText.length(); i++)
    {
        char low = tempText.at(i);
        tempText.at(i) = tolower(low);
    }
    return tempText;
}

// Roie addition
// Typo helper function section:
//Letter match functions use "english sorted by frequency" to determine which letters test first"
// LINK : https://en.wikipedia.org/wiki/Letter_frequency

bool matchVW(char compared)
{
    return (
        (compared == 'w') ||
        (compared == 'W') ||
        (compared == 'v') ||
        (compared == 'V'));
}
bool matchSZ(char compared)
{
    return (
        (compared == 's') ||
        (compared == 'S') ||
        (compared == 'z') ||
        (compared == 'Z'));
}
bool matchBFP(char compared)
{
    return (
        (compared == 'f') ||
        (compared == 'F') ||
        (compared == 'p') ||
        (compared == 'P') ||
        (compared == 'b') ||
        (compared == 'B'));
}
bool matchCKQ(char compared)
{
    return (
        (compared == 'c') ||
        (compared == 'C') ||
        (compared == 'k') ||
        (compared == 'K') ||
        (compared == 'q') ||
        (compared == 'Q'));
}

bool matchDT(char compared)
{
    return (
        (compared == 't') ||
        (compared == 'T') ||
        (compared == 'd') ||
        (compared == 'D'));
}
bool matchIY(char compared)
{
    return (
        (compared == 'i') ||
        (compared == 'I') ||
        (compared == 'y') ||
        (compared == 'Y'));
}
bool matchOU(char compared)
{
    return (
        (compared == 'o') ||
        (compared == 'O') ||
        (compared == 'u') ||
        (compared == 'U'));
}
bool matchGJ(char compared)
{
    return (
        (compared == 'g') ||
        (compared == 'G') ||
        (compared == 'j') ||
        (compared == 'J'));
}

char asciitolower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

/**
 *@param wrdChar : A char from the  word we are looking for, !must be lower Case! , otherwise undefined.
 *@param curr: A char that can be lower case or upper case.
 * This is a helper method to define if two given chars are equal ,  regardless if "curr" is lower or upper case.
 * @return : Returning true only if curr is lower case or upper case version of wrdChar , otherwise false.
 
 **/
bool upLowCaseCheck(char wrdChar, char curr)
{
    //cout << "wrdChar = "<< wrdChar <<" and curr is = "<< curr << endl;
    return (curr == wrdChar || // Lower case
           (curr + 32) == wrdChar); // Upper case
}
/**
 * @param lword: A lower case version of the word typed to search , all char must be lowercase english alphabet.
 * @param curr : the current word that is checked to be equal to "lword".
 * This method match the "word" , and "curr" by the rules of the assigment as described in the link
 * https://github.com/RoieJinx/phonetic-search-a/blob/master/README.md
 * ! word & curr assumed to be the same length! - Otherwise undefined 
 * @return: 0 if the word match , otherwise -1;
 * */

int checkWord(string lword, string curr)
{
    bool mistakeFound = false; // Flag to stop the loop if mistake found
    for (int i = 0; i < lword.length() && !mistakeFound; i++)
    {
        switch (lword[i])
        {
        case 'e':
            mistakeFound = (!upLowCaseCheck('e', curr[i]));
            break;

        case 't':
            mistakeFound = (!phonetic::matchDT(curr[i]));
            break;

        case 'a':
            mistakeFound = (!upLowCaseCheck('a', curr[i]));
            break;

        case 'o':
            mistakeFound = (!phonetic::matchOU(curr[i]));
            break;

        case 'i':
            mistakeFound = (!phonetic::matchIY(curr[i]));
            break;

        case 'n':
            mistakeFound = (!upLowCaseCheck('n', curr[i]));
            break;

        case 's':
            mistakeFound = (!phonetic::matchSZ(curr[i]));
            break;

        case 'h':
            cout<< "this is lword = " << lword << " this is curr" << curr <<" ,this is curr["<<i<<"] = "<< curr[i] << endl;
            mistakeFound = (!upLowCaseCheck('h', curr[i]));
            break;

        case 'r':
            mistakeFound = (!upLowCaseCheck('r', curr[i]));
            break;

        case 'd':
            mistakeFound = (!phonetic::matchDT(curr[i]));
            break;

        case 'l':
            mistakeFound = (!upLowCaseCheck('l', curr[i]));
            break;

        case 'c':
            mistakeFound = (!phonetic::matchCKQ(curr[i]));
            break;

        case 'u':
            mistakeFound = (!phonetic::matchOU(curr[i]));
            break;

        case 'm':
            mistakeFound = (!upLowCaseCheck('m', curr[i]));
            break;

        case 'w':
            mistakeFound = (!phonetic::matchVW(curr[i]));
            break;

        case 'f':
            mistakeFound = (!phonetic::matchBFP(curr[i]));
            break;

        case 'g':
            mistakeFound = (!phonetic::matchGJ(curr[i]));
            break;

        case 'y':
            mistakeFound = (!phonetic::matchIY(curr[i]));
            break;

        case 'p':
            mistakeFound = (!phonetic::matchBFP(curr[i]));
            break;

        case 'b':
            mistakeFound = (!phonetic::matchBFP(curr[i]));
            break;

        case 'v':
            mistakeFound = (!phonetic::matchVW(curr[i]));
            break;

        case 'k':
            mistakeFound = (!phonetic::matchCKQ(curr[i]));
            break;

        case 'j':
            mistakeFound = (!phonetic::matchGJ(curr[i]));
            break;

        case 'x':
            mistakeFound = (!upLowCaseCheck('x', curr[i]));
            break;

        case 'q':
            mistakeFound = (!phonetic::matchCKQ(curr[i]));
            break;

        case 'z':
            mistakeFound = (!phonetic::matchSZ(curr[i]));
            break;

        default:
        string errorMessage3 = string("ERR:Illigal char '") +lword[i] + ("' in the word");
        throw runtime_error(errorMessage3);
            mistakeFound = true;
            cout << " Illigal char! : " << lword[i] << endl;
            break;
        }
    }
    if (mistakeFound)
        return -1;
    else
    {
        return 0;
    }
}

} 