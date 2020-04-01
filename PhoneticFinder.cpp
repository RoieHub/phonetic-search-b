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
        //change word and text into a lower case
        string lowword = wordlowercase(word);
        string lowtext = textlowercase(text);
        lowtext = lowtext + ' ';
        text = text + ' ';

        //define vector of strings which includ words from the text
        vector <string> words = wordsfromt(lowtext);
        vector <string> realwords = wordsfromt(text);
        bool real =true;
        int textwords =realwords.size();
        cout << "this is :" << word << "  ";
        

        //check if the words with the same size
        for (int i=0;i<words.size();i++)
        {
            //real = islike(word,words[i]);
            real=same(word,words[i]);
            if (lowword.size()==words[i].size()&&(real==true))
             {
                 int check = checkequal(lowword,words[i]);
                  if (check==0)
                   {
                   return realwords[i];
                  }
 
             }
            textwords--;
        }
        if (textwords==0)
            {
                 string errorMessage = string("Did not find the word ") + word + (" in the text");
	             throw runtime_error(errorMessage);

             }
        

    return "no";
    }



    //check how many same chars betwen two strings
    bool same(string word,string wordtext)
    {
        int i=0;
        int count=0;
        int check=0;
        if (word.size()==wordtext.size())
        {
           for (i=0;i<word.size();i++)
           {
               check=checkequal((word.at(i)),(wordtext.at(i)));
               if (check==0)
               {
                   count ++;
               }
           }

           if (count>=(word.size()-2))
           {
               return true;
           }

           else if (word.size()==2)
           {
               check=checkequal(word,wordtext);
               if (check==0)
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
    int checkequal (string word, string wordtext)
    {
        int count = word.size();
        if (word==wordtext)
        {
            return 0;
        }

        for (int i=0;i<word.size();i++)
        {
            //cout << word << "  " << wordtext << "  " << word.size() << " ";
            if (word.at(i)=='b' && (wordtext.at(i)=='b' || wordtext.at(i)=='f' || wordtext.at(i)=='p'))
            {
                count --;
            }

            else if (word.at(i)=='f' && (wordtext.at(i)=='b' || wordtext.at(i)=='f' || wordtext.at(i)=='p'))
            {
                count --;
            }

            else if (word.at(i)=='p' && (wordtext.at(i)=='b' || wordtext.at(i)=='f' || wordtext.at(i)=='p'))
            {
                count --;
            }

            else if (word.at(i)=='c' && (wordtext.at(i)=='c' || wordtext.at(i)=='k' || wordtext.at(i)=='q'))
            {
                count --;
            }

            else if (word.at(i)=='q' && (wordtext.at(i)=='c' || wordtext.at(i)=='k' || wordtext.at(i)=='q'))
            {
                count --;
            }

            else if (word.at(i)=='k' && (wordtext.at(i)=='c' || wordtext.at(i)=='k' || wordtext.at(i)=='q'))
            {
                count --;
            }

            else if (word.at(i)=='v' && (wordtext.at(i)=='v' || wordtext.at(i)=='w'))
            {
                count --;
            }

            else if (word.at(i)=='w' && (wordtext.at(i)=='v' || wordtext.at(i)=='w'))
            {
                count --;
            }

            else if (word.at(i)=='g' && (wordtext.at(i)=='g' || wordtext.at(i)=='j'))
            {
                count --;
            }

            else if (word.at(i)=='j' && (wordtext.at(i)=='g' || wordtext.at(i)=='j'))
            {
                count --;
            }

            else if (word.at(i)=='s' && (wordtext.at(i)=='s' || wordtext.at(i)=='z'))
            {
                count --;
            }

            else if (word.at(i)=='z' && (wordtext.at(i)=='s' || wordtext.at(i)=='z'))
            {
                count --;
            }

            else if (word.at(i)=='d' && (wordtext.at(i)=='d' || wordtext.at(i)=='t'))
            {
                count --;
            }

            else if (word.at(i)=='t' && (wordtext.at(i)=='d' || wordtext.at(i)=='t'))
            {
                count --;
            }

            else if (word.at(i)=='o' && (wordtext.at(i)=='o' || wordtext.at(i)=='u'))
            {
                count --;
            }

            else if (word.at(i)=='u' && (wordtext.at(i)=='o' || wordtext.at(i)=='u'))
            {
                count --;
            }

            else if (word.at(i)=='i' && (wordtext.at(i)=='i' || wordtext.at(i)=='y'))
            {
                count --;
            }

            else if (word.at(i)=='y' && (wordtext.at(i)=='i' || wordtext.at(i)=='y'))
            {
                count --;
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
    int checkequal (char word, char wordtext)
    {
        if (word==wordtext)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
    }



   //take words from the text
   vector <string> wordsfromt (string text)
   {
       int index=0;
       int i=0;
       vector <string> wordsfromtext;
       for (int i=0;i<text.size();i++)
       {
           if (text.at(i)==' ')
           {
               wordsfromtext.push_back(text.substr(index,(i-index)));
               index=i+1;
           }
       }
       //cout << wordsfromtext.size();
       return wordsfromtext;
   }


    //change word into lowercase
    string wordlowercase(string word)
    {
       for(size_t i=0;i<word.length();i++) 
        {
            char low=word.at(i);
            word.at(i)=tolower(low);
        }
        return word;
        
    }

    //change text into lower case
    string textlowercase(string text)
    {
        string tempText=text;
        for(size_t i=0;i<tempText.length();i++) 
        {
            char low=tempText.at(i);
            tempText.at(i)=tolower(low);
        }
        return tempText;
        
    }

}