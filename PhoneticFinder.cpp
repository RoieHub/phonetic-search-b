#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic
{

//find the phonatic words
string find(string text, string word)
{
    
    if (word.length() == 0) // Check empty text
    {
        string errorMessage1 = string("No words found in text");
        throw runtime_error(errorMessage1);
    }

    //change word and text into a lower case for convinions
    string originalWord = word;
    string lowword = wordlowercase(word);
    //cout << "this is the low :" << lowword << "  and this is original : "<< word << endl;
    text = text + ' '; // Added delimiter for partition.

    // Init vector of strings , which are words from the text
    bool found = false;
    vector<string> wordsArray = wordsfromt(text);
    int numOfWords = wordsArray.size();
    //cout << "this is :" << word << "  ";

    if (numOfWords == 0) // Check empty text
    {
        string errorMessage2 = string("No words found in text");
        throw runtime_error(errorMessage2);
    }

    // Check if any word in my txt match
    for (int i = 0; i < numOfWords ; i++)
    { 
        // Do the check only on words with matching size
        if(lowword.length() == wordsArray[i].length())
        {
          int match = checkWord(lowword,wordsArray[i]);
          if( match == 0 ) // wordFound
          {
              found = true;
              //cout << "Found the word "<<wordsArray[i] << endl;
                return wordsArray[i];
          }      
        }
        
    }

    if (!found)
    {
        string errorMessage3 = string("Did not find the word ") + word + (" in the text");
        throw runtime_error(errorMessage3);
    }

    return "no";
}

//check how many same chars betwen two strings
bool same(string word, string wordtext)
{
    int i = 0;
    int count = 0;
    int check = 0;
    if (word.size() == wordtext.size())
    {
        for (i = 0; i < word.size(); i++)
        {
            check = checkequal((word.at(i)), (wordtext.at(i)));
            if (check == 0)
            {
                count++;
            }
        }

        if (count >= (word.size() - 2))
        {
            return true;
        }

        else if (word.size() == 2)
        {
            check = checkequal(word, wordtext);
            if (check == 0)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

//check if there are typing problem
int checkequal(string word, string wordtext)
{
    int count = word.size();
    if (word == wordtext)
    {
        return 0;
    }

    for (int i = 0; i < word.size(); i++)
    {
        //cout << word << "  " << wordtext << "  " << word.size() << " ";
        if (word.at(i) == 'b' && (wordtext.at(i) == 'b' || wordtext.at(i) == 'f' || wordtext.at(i) == 'p'))
        {
            count--;
        }

        else if (word.at(i) == 'f' && (wordtext.at(i) == 'b' || wordtext.at(i) == 'f' || wordtext.at(i) == 'p'))
        {
            count--;
        }

        else if (word.at(i) == 'p' && (wordtext.at(i) == 'b' || wordtext.at(i) == 'f' || wordtext.at(i) == 'p'))
        {
            count--;
        }

        else if (word.at(i) == 'c' && (wordtext.at(i) == 'c' || wordtext.at(i) == 'k' || wordtext.at(i) == 'q'))
        {
            count--;
        }

        else if (word.at(i) == 'q' && (wordtext.at(i) == 'c' || wordtext.at(i) == 'k' || wordtext.at(i) == 'q'))
        {
            count--;
        }

        else if (word.at(i) == 'k' && (wordtext.at(i) == 'c' || wordtext.at(i) == 'k' || wordtext.at(i) == 'q'))
        {
            count--;
        }

        else if (word.at(i) == 'v' && (wordtext.at(i) == 'v' || wordtext.at(i) == 'w'))
        {
            count--;
        }

        else if (word.at(i) == 'w' && (wordtext.at(i) == 'v' || wordtext.at(i) == 'w'))
        {
            count--;
        }

        else if (word.at(i) == 'g' && (wordtext.at(i) == 'g' || wordtext.at(i) == 'j'))
        {
            count--;
        }

        else if (word.at(i) == 'j' && (wordtext.at(i) == 'g' || wordtext.at(i) == 'j'))
        {
            count--;
        }

        else if (word.at(i) == 's' && (wordtext.at(i) == 's' || wordtext.at(i) == 'z'))
        {
            count--;
        }

        else if (word.at(i) == 'z' && (wordtext.at(i) == 's' || wordtext.at(i) == 'z'))
        {
            count--;
        }

        else if (word.at(i) == 'd' && (wordtext.at(i) == 'd' || wordtext.at(i) == 't'))
        {
            count--;
        }

        else if (word.at(i) == 't' && (wordtext.at(i) == 'd' || wordtext.at(i) == 't'))
        {
            count--;
        }

        else if (word.at(i) == 'o' && (wordtext.at(i) == 'o' || wordtext.at(i) == 'u'))
        {
            count--;
        }

        else if (word.at(i) == 'u' && (wordtext.at(i) == 'o' || wordtext.at(i) == 'u'))
        {
            count--;
        }

        else if (word.at(i) == 'i' && (wordtext.at(i) == 'i' || wordtext.at(i) == 'y'))
        {
            count--;
        }

        else if (word.at(i) == 'y' && (wordtext.at(i) == 'i' || wordtext.at(i) == 'y'))
        {
            count--;
        }
    }
    if (count >= 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }

    return 2;
}

//check if there are typing problems in chars
int checkequal(char word, char wordtext)
{
    if (word == wordtext)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//take words from the text
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
    //cout << wordsfromtext.size();
    return wordsfromtext;
}

//change word into lowercase
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
 * This is a helper method to define if two given chars are equal ,  regardless if "curr" is lower or upper case.
 * Returning true only if curr is lower case or upper case version of wrdChar , otherwise false.
 * wrdChar : A char from the  word we are looking for, !must be lower Case! , otherwise undefined.
 * curr: A char that can be lower case or upper case.
 **/
bool upLowCaseCheck(char wrdChar, char curr)
{
    //cout << "wrdChar = "<< wrdChar <<" and curr is = "<< curr << endl;
    return (curr == wrdChar || // Lower case
           (curr + 32) == wrdChar); // Upper case
}
/**
 * lword: A lower case version of the word typed to search , all char must be lowercase english alphabet.
 * curr : the current word that is checked to be equal to "lword".
 * This method match the "word" , and "curr" by the rules of the assigment
 * ! word & curr assumed to be the same length! - Otherwise undefined 
 * return: 0 if the word match , otherwise -1;
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
            mistakeFound = true;
            cout << " could not match the charecter : " << lword[i] << endl;
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

} // namespace phonetic