
#include <iostream>
#include <string>
using namespace std;

/*
 Problem #31

 Write a program to read a string and read a character,
 then count the occurrences of that character in the string.

 Condition: CASE SENSITIVE


 Example:

 Please Enter Your String?
 Mohammed Abu-Hadhoud

 Please Enter a Character?
 m

 Letter 'm' Count = 2

*/



string ReadStringValue(const string& message)  // Pass by constant reference.
{
    string value; // what's returned.

    cout << message;
    getline(cin, value);
    cout << endl;

    return value;
}



bool ValidateStringInRange(const string& value, short MinNumOfCharacters, short MaxNumOfCharacters) // pass by const. ref. as 'value' is ONLY used for comparison against the range (not worth creating a nw memory space for it just for thjat)
{
    return (MinNumOfCharacters <= value.length() && value.length() <= MaxNumOfCharacters);
}


string ReadStringInRange(const string& message, short MinNumOfCharacters, short MaxNumOfCharacters) // pass by const. ref. //ranges ALWAYS passed by value
{
    string value; // what's returned

    value = ReadStringValue(message); // 'value' is to be IMMEDIATELY validated against the range, in the while condition.

    while (!ValidateStringInRange(value, MinNumOfCharacters, MaxNumOfCharacters))
    {
        cout << "Error- The number of characters entered should be between " << MinNumOfCharacters << " & " << MaxNumOfCharacters << endl;
        value = ReadStringValue(message);
    }

    return value;
    // the above block of code is to be sequentially composed line by line. & at the end, implement all the functions.
}


char ReadCharacter(const string& message)   // pass by const. ref.  // NOTICE: we never included the other function whose purpose is to range evaluate the input as we do not need range evaluation for this problem.
{
    char character;  // what is returned.

    cout << message;
    cin >> character;
    cout << endl;

    return character;
}


short CountCharacter(const char& character, const string& text)  // pass by const. ref.
{
    short count = 0;

    for (short i = 0; i < text.length(); i++)
    {
        if (tolower(text[i]) == tolower(character))   // this ignores case sensitivity.  // or toupper() on both sides.
        {
            count++;
        }
    }


    return count;
}




int main()
{
    short MinNumOfCharacters = 1;
    short MaxNumOfCharacters = 1000;

    string text = ReadStringInRange("Please Enter Your text: ", MinNumOfCharacters, MaxNumOfCharacters);
    /*           |
                 |----->   // added at the very end, after finishing typing the "return" keyword in the implementing function. */



    char character = ReadCharacter("Enter a character: "); // No range included as ALL types of characters are accepted (letter characters, digit characters, & special characters) as used may enter any type of character.
    /*          |
                |----> // added at the end after finishing typing the "return" keyword of the implemenmting function. */


    short CountCharacterFrequency = CountCharacter(character, text);
    /*           |
                 |-->   // added at the very end. after finishing typing the "return" keyword of the implementingt function.*/

    cout << "Character '" << character << "' count = " << CountCharacterFrequency << endl;

    return 0;
}

