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
    // Helper typo programs 
	bool matchVW(char compared );
	bool matchSZ(char compared );
	bool matchBFP(char compared);
	bool matchCKQ(char compared);
	bool matchDT(char compared );
	bool matchIY(char compared );
	bool matchOU(char compared );
	bool matchGJ(char compared );
    char asciitolower(char in);
    bool upLowCaseCheck(char wrdChar, char curr);
    int checkWord(string lword, string curr);

    
}