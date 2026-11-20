
#include <iostream>
#include <string>
using namespace std;
 
/*
 Problem #33

 Write a program to read a string, then count all vowels in that string.

 Vowels are:
 a, e, i, o, u

 Example:

 Please Enter Your String?
 Mohammed Abu-Hadhoud Programming Advices

 Number of vowels is: 14

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
            cout << "Error- String entered must be between " << MinLength << " & " << MaxLength << " ." << endl;
        }

        value = ReadStringValue(message); // 'value' is to be IMEDIATELY validated against the range, in the while condition.

    } while (!ValidateStringInRange(value, MinLength, MaxLength));

    return value;

    // the above block of code is to be sequentially composed line by line &at the end implement all functions.
}


bool IsLetterVowel(const char& character)
{
    char ReadyCharacter = tolower(character);
    return ((ReadyCharacter == 'a') || (ReadyCharacter == 'e') || (ReadyCharacter == 'i') || (ReadyCharacter == 'o') || (ReadyCharacter == 'u'));
}



short CountAllVowelsInString(const string& sentence)  // pass by const. ref.
{
    short count = 0;
    size_t length = sentence.length();

    for (size_t i = 0; i < length; i++) // iterating through each letter of the string since strings are also arrays (They possess dual nature).
    {
        if (IsLetterVowel(sentence[i]))
        {
            count++;
        }
    }

    return count;
}


int main()
{
    short MinLength = 1;
    short MaxLength = 500;

    string sentence = ReadStringInRange("Please Enter Your String: ", MinLength, MaxLength);

    short NumberOfVowels = CountAllVowelsInString(sentence);
    cout << "\nNumber of vowels is: " << NumberOfVowels << endl;
  


    return 0;
}


