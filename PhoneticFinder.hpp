#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

namespace phonetic
{
    //string getword(int begin,int end,string s);
    string find(string text, string word);
    string wordlowercase(string word);
    string textlowercase(string text);
    bool problemchar (string word, string realword);
    bool notin (string text,string word);
    //string inword(string text);
    int numberofwords (string text);
    int sizestring (string text);
    //string makeword (string text,int index,int i);
    
}