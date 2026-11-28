
#include <iostream>
#include <string>   // for getline(cin, )
#include <cctype>    // (char)toupper(ch)
using namespace std;

// MENTAL MODEL: The First Letter of Each Word (Capitalizing)
// The pre-requisite for this mental model is the previous lesson.


/*
 Problem #24

 Write a program to read a string then uppercase the first
 letter of each word in that string.

 Example:

 Please Enter Your String?
 mohammed saqer abu-Hadhoud

 String after conversion:
 Mohammed Saqer Abu-Hadhoud


*/


// unoptimized & a VERY COMPLICATED solution
string ReadString(const string& message)  // by by const. ref.
{
    string sentence;  // what is returned.

    cout << message;
    getline(cin, sentence);

    return sentence;
    
}



string UpperFirstLetterOfEachWord(string sentence) // pass by valuwe
{

    bool IsItFirstLetterInWord = true; // a flag checked with every iteration.

    for (short i = 0; i < sentence.length(); i++) // iterates over the entire string sentence (since a string is an aray of characters).
    {
        if (sentence[i] != 0 && IsItFirstLetterInWord)
        {
           (toupper(sentence[i]));
        }

        (sentence[i] == ' ') ?   true : false;
    }

    return sentence;



  

}




int main()
{
    string sentence = ReadString("Please enter your string: ");
    /*            |
                  |---->   // added at the very end after finishing typing the "return" keyword of the implementing function. */

    cout << "\nString after conversion: ";
    cout << UpperFirstLetterOfEachWord(sentence) << endl;



    return 0;
}


/*
 string UpperFirstLetterOfEachWord(const string& sentence)
{
    bool IsItFirstLetterOfWord = true;  // setting a flag.
    string UpperFirstLettersSentence = " ";  // routine // equivalent to int sum.

    for (short i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ' && IsItFirstLetterOfWord)
        {
            UpperFirstLettersSentence += (char)toupper(sentence[i]);
        }

        else
        {
            UpperFirstLettersSentence += sentence[i];
        }

        IsItFirstLetterOfWord = (sentence[i] == ' ') ? true : false;
    }


    return UpperFirstLettersSentence;
}




*/