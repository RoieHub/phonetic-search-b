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
    vector <string> wordsfromt (string text);
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