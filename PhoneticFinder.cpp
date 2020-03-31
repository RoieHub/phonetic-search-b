#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "PhoneticFinder.hpp" 
using namespace std;

namespace phonetic
{
    string find(string text, string word)
    {
        string lowword = wordlowercase(word);
        string lowtext = textlowercase(text);
        //string check = inword(text);
        int words = numberofwords(text);
        int size = sizestring(text);
        int i=0;
        int j=0;
        int index=0;
        string temp=text;
        vector <string> wordy;
        int countwords=0;
        int prob=words;
        string textnew = lowtext + "  ";

        
        for (i=0;i<=size;i++)
        {
            if (textnew.at(i)==' ' && words!=0)
            {
            wordy.push_back(textnew.substr(index,(i-index)));       
            index=i+1;
            }

            
        }
           while (prob>0)
            {
               for (j=0,i=0;j<=word.length();j++,prob--)
               {
                   
                   if (problemchar(wordy[i],lowword)==true)
                   {
                       //cout << word << " line 44  " << endl;
                       //cout << wordy [i] << " line 45  " << endl;
                       //cout << " here ";
                       //cout << " in problem char "  <<  wordy[i] << "  " << word << " " << endl;
                       return wordy[i];
                       i++;
                       //cout << "here new word: " << wordy[i] << endl;
                       
                   }

                   else if (word=="")
                   {
                      throw runtime_error {"The "+ word+" is invalid word"};
                   }

                   else
                   {
                      //cout << "in else: " << (wordy[i]) << "  " << (word) << " " << endl;
                      i++;
                      //cout << "here";
                   }


                   
               }
             
             } 
          
            

      return "no word";
        
    }




    int sizestring (string text)
    {
        int count=0;
        int i=0;

        while (text[i]) 
        {
        i++;
        count++;
        }

        return count;
         
    
    }

    int numberofwords (string text)
    {
        int countspaces = 0;
        int words=0;
        int i=0;
        int size = sizestring(text);
        //cout << size;
        for (i=0;i<size;i++)
        {
            if (i==0 && text.at(i)!=' ')
            {
                //cout << "line 64" << endl;
                words++;
            }

            else if (text.at(i)==' ')
            {
                countspaces++;
               //cout << "line 70" << endl;
                words++;
            }
            
            
        }
        
        return words;

    }




    bool problemchar (string word, string realword)
    {
        for(size_t i=0;i<word.length();i++) 
        {
            char c=word.at(i);
            char creal=realword.at(i);

            if (c==creal)
            {
                return true;
            }

            else if (creal=='w' && (c=='w' || c=='v'))
            {
                return true;
            }

            else if (creal=='v' && (c=='w' || c=='v'))
            {
                return true;
            }

            else if (creal=='g' && (c=='g' || c=='j'))
            {
                return true;
            }

            else if (creal=='j' && (c=='g' || c=='j'))
            {
                return true;
            }

            else if (creal=='s' && (c=='s' || c=='z'))
            {
                return true;
            }

            else if (creal=='z' && (c=='s' || c=='z'))
            {
                return true;
            }

            else if (creal=='d' && (c=='t' || c=='d'))
            {
                return true;
            }

            else if (creal=='t' && (c=='t' || c=='d'))
            {
                return true;
            }

            else if (creal=='o' && (c=='o' || c=='u'))
            {
                return true;
            }

            else if (creal=='u' && (c=='o' || c=='u'))
            {
                return true;
            }

            else if (creal=='i' && (c=='i' || c=='y'))
            {
                return true;
            }

            else if (creal=='y' && (c=='i' || c=='y'))
            {
                return true;
            }

            else if (creal=='b' && (c=='b' || c=='f' || c=='p'))
            {
                return true;
            }

            else if (creal=='f' && (c=='b' || c=='f' || c=='p'))
            {
                return true;
            }

            else if (creal=='p' && (c=='b' || c=='f' || c=='p'))
            {
                return true;
            }

            else if (creal=='c' && (c=='k' || c=='q' || c=='p'))
            {
                return true;
            }

            else if (creal=='k' && (c=='k' || c=='q' || c=='p'))
            {
                return true;
            }

            else if (creal=='q' && (c=='k' || c=='q' || c=='p'))
            {
                return true;
            }

            else
            {
                return false;
            }
        }
        return true;
            
    }

    string wordlowercase(string word)
    {
       for(size_t i=0;i<word.length();i++) 
        {
            char low=word.at(i);
            word.at(i)=tolower(low);
        }
        return word;
        
    }


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

    bool notin (string text,string word)
    {
        return false;
    }
   
}