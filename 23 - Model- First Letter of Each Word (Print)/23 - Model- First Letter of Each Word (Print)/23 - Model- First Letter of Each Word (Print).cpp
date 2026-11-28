
#include <iostream>
#include <string>  // to use getline(cin, )
using namespace std;

//******************** MENTAL MODEL: The First Letter of Each Word  ***************************

// your assignent is to simply comprehend the following code and be able to justify every single line:



/*
 bool IsItFirstLetterOfWord = true;  // declaring a flag

 for (short i = 0; i < sentence.length(); i++)  // iterating through the entire string the user enters (a string is an array of characters)
 {
     if (sentence[i] != ' ' && IsItFirstLetterOfWord)
     {
         cout << sentence[i] << endl;  // or do something else with sentence[i] // do what you need to do at this iteration of the first letter of the word.
     }

     IsFirstLetterOfWord = (sentence[i] == ' ') ? true : false;
 }

 // PLUS (CRUCIAL): examine the comments of this mental model in the example below.
 */




 /* CRUCIAL: String Manipulation problems are VERY IMPORANT for developers to master
             no matter what you specialize in as a developer.
             you'll use it in:

             Databases, Desktop Applications, Web, HTML, Mobile, etc. (virtually everywhere).

             Strings manipulations problems are asked in interviews.

             */


             /*
              Problem #23

              Write a program to read a string then print the first letter
              of each word in that string.

              Example:

              Please Enter Your String?
              Mohammed Saqer Abu-Hadhoud @Programming Advices

              First letters of this string:

              M
              S
              A
              @
              A

             */


string ReadStringValue(const string& message)  // by by const. ref.
{
    string sentence;  // what is returned.

    cout << message;
    getline(cin, sentence);

    return sentence;
}



string ReadString(const string& message)  // pass by const. ref.   // Notice that this entire function is redundant as it meant to include validation which is ignored.
{
    string sentence;  // what's returned.

    sentence = ReadStringValue(message);

    return sentence;
}



void PrintFirstLetterOfEachWord(const string& sentence)  // pass by const. ref.
{
    bool IsItFirstLetterOfWord = true;  // declare a flag

    for (short i = 0; i < sentence.length(); i++)  // iterating through the entire string the user enters (a string is an array of characters)
    {
        if (sentence[i] != ' ' && IsItFirstLetterOfWord) // on first iteration: if the first letter of the sentence is not space, then print it.
        {                                                 // this means that immediately, while still on the 1st iteration, the flag IsFirstLetterOfWord  
            cout << sentence[i] << endl;            // has to be switched to false becasue on the 2nd iteration, the 2nd letter of word
            // is not IsfirstLetterOfWord (common sense). this is done in the short if statement below.

            IsItFirstLetterOfWord = (sentence[i] == ' ') ? true : false;  // and when the iteration reaches the 1st space, the flag has to be switched to true
        }                                                                // so that the first letter of the enxt word is printed out.
                                                                   // and then immediately, switch the flag back to false, so the second letter of the 
                                                              // word we are on does not get printed out to the screen.
    }
}

    int main()
    {
        string sentence = ReadString("Please Enter your string: ");  // I decided that no range validation for the string (length) // in the future think: how can I only accept character strings and not for example digit strings or special cahracter strings and vice versa.// how to reject entering empty space(s)
        /*            |
                      |------>    // added at the very end after typing the "return" keyword in the implementing function. */


                      //cout << sentence << endl;


        PrintFirstLetterOfEachWord(sentence);

        return 0;
    }


