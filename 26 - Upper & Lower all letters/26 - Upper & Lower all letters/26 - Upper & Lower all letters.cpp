
#include <iostream>
#include <string> // for getline(cin, )
using namespace std;

/*
 Problem 26:

 Write a program to read a string, then convert all letters to uppercase,
 THEN convert all letters to lowercase, and print the results.

 Sample Output:

 Please Enter Your String?
 mohammed Abu-Hadhoud

 String after Upper:
 MOHAMMED ABU-HADHOUD

 String after Lower:
 mohammed abu-hadhoud

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



string UpperAllLettersInSentence(string sentence) // pass by value
{
    for (short i = 0; i < sentence.length(); i++)  // iterating through every element in the string (strings are also arrays)
    {
        sentence[i] = toupper(sentence[i]);  // declaration is in the parameter.
    }

    return sentence;
}


string LowerAllLettersInSentence( string sentence)  // pass by value
{
    for (short i = 0; i < sentence.length(); i++) // iterating through each and every letter in the string as strings are also arrays.
    {
        sentence[i] = tolower(sentence[i]);
    }

    return sentence;
}




int main()
{
    short MinLength = 1;
    short MaxLength = 40;

    string sentence = ReadStringInRange("Please enter a string: \n", MinLength, MaxLength);  
/*            |
              |-- > // to be typed at the very end after finishing typing the "return" keyword and implementing the functions above it.*/



    cout << "String after uppering all of its letters: \n";
    cout << UpperAllLettersInSentence(sentence) << endl;

    cout << "\nString after lowering all of its letters: \n";
    cout << LowerAllLettersInSentence(sentence) << endl;

    return 0;
}


