
#include <iostream>
#include <string>
using namespace std;
 
/*
 Problem #34

 Write a program to read a string, then print all vowels in that string.

 Vowels are:
 a, e, i, o, u

 Example:

 Please Enter Your String?
 Mohammed Abu-Hadhoud @ProgrammingAdvices

 Vowels in string are:
 o a e A u a o u o a i A i e

*/



string ReadStringValue(const string& message)  // pass by const. ref.
{
    string value;  // what's returned.

    cout << message;
    getline(cin, value);
    cout << endl;

    return value;
}



bool ValidateStringInRange(const string& value, short MinLength, short MaxLength) // pass by const. ref. as 'value' is ONLY used for comparison against the range.
{
    return (MinLength <= value.length() && value.length() <= MaxLength);
}



string ReadStringInRange(const string& message, short MinLength, short MaxLength)   // pass by constant reference. // Ranges ALWAYS passed by value.
{
    short counter = 0;
    string value;  // what is returned.

    do
    {
        counter++;
        if (counter > 1)
        {
            cout << "Error- String entered must be between " << MinLength << " & " << MaxLength << endl;
        }

        value = ReadStringValue(message); // 'value' is to be IMEDIATELY validated against the range, in the while condition.

    } while (!ValidateStringInRange(value, MinLength, MaxLength));

    return value;

    // the above block of code is to be sequentially composed line by line &at the end implement all functions.
}




bool IsLetterVowel(const char& character)  // pass by const. ref.
{
    char ReadyCharacter = tolower(character);

    return((ReadyCharacter == 'a') || (ReadyCharacter == 'e') || (ReadyCharacter == 'i') || (ReadyCharacter == 'o') || (ReadyCharacter == 'u'));
}




void PrintVowelsInString(const string& sentence)  // pass  by const. ref.
{
    size_t length = sentence.length(); // length() returns a number of data type size_t
    
    for (size_t i = 0; i < length; i++) // ierating through every & each letter of the string 'sentence' as strings are also arrays.
    {
        if (IsLetterVowel(sentence[i]))
        {
            cout << sentence[i] << " ";
        }
    }

    cout << endl;
}




int main()
{
    short MinLength = 1;
    short MaxLength = 1000;

    string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
 /*           |
              |------> Typed at the very end, after finishing typing the "return" keyword in the implementing function. */

    
    cout << "Vowels in string are: \n";
    PrintVowelsInString(sentence);

    return 0;
}


