
#include <iostream>
#include <string>
using namespace std;

/*
 Problem #25

 Write a program to read a string, then lowercase the first
 letter of each word in that string.

 Example:

 Please Enter Your String?
 Mohammed Saqer Abu-Hadhoud

 String after conversion:
 mohammed saqer abu-Hadhoud

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



string LowerFirstLetterOfEachWord(string sentence)   // pass by value.
{
   bool IsItFirstLetterInWord = true; // A flag needed for eadch iteration.

   for (short i = 0; i < sentence.length(); i++)
   {
       if (sentence[i] != ' ' && IsItFirstLetterInWord)
       {
           sentence[i] = tolower(sentence[i]);       // The array is declared in the parameter. Here you override the value of some element (the first letter of each word).
       }                                             // as for the rest of elements they retain their original values as the if statement is false
       // now you need to re-reset IsItFirstLetterOfWord IMMEDIATELY to false
       // so that the second letter in the word in the 2nd iteration get lower cased.
       IsItFirstLetterInWord = (sentence[i] == ' ') ? true : false;       // strive to make the statement positive (==)
       // type variable first
   }

   return sentence;
}


int main()
{
    
    string sentence = ReadString("Please Enter Your String: ");
/*            |
              |--> // added at the very end after finishing typing the "return" keyword of the implementing function.    */

    cout << "String after conversion : " << endl;
    cout << LowerFirstLetterOfEachWord(sentence) << endl;

    return 0;
}

