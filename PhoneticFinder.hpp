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
    vector <string> wordsfromt (string text);
    int checkequal (string word, string wordtext);
    int checkequal (char word, char wordtext);
    bool same(string word,string wordtext);

    
}