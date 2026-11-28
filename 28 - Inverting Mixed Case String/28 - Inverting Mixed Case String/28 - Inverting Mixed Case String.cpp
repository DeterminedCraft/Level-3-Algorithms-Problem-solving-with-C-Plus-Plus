
#include <iostream>
#include <string>
using namespace std;


/*
 Problem 28:

 Write a program to read a mixed-case string, then invert the case of all its letters
 and print the result.

 Sample Output:

 Please Enter Your String?
 mohammed ABU-HADHOUD

 String after Inverting All Letters Case:
 MOHAMMED abu-hadhoud


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



char InvertALetterCase(char character) // pass by value
{
    return isupper(character) ? tolower(character) : toupper(character);
}


string InvertingAllLettersCases(string sentence) // pass by value
{
    for (short i = 0; i < sentence.length(); i++)  // iterating through each & every letter of the string sentence (= strings are also arrays).
    {
        sentence[i] = InvertALetterCase(sentence[i]); // our Mental Model InvertALetterCase() 
    }

    return sentence;
}

int main()
{
    short MinLength = 1;
    short MaxLength = 50;

    string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);


    cout << "String after Inverting All Letters Case: " << endl;
    cout << InvertingAllLettersCases(sentence) << endl;


    return 0;
}


// Observe the retarded unoptimized solution below:
/* 
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


bool IsLetterCapital(char character)  // pass by value.
{
    return (65 <= character && character <= 90);
}


string InvertingCasesInSentence(string sentence) // pass by value.
{
    for (short i = 0; i < sentence.length(); i++)  // iterating through every single charcter in the string ( a string is an array too).
    {
        sentence[i] = (IsLetterCapital(sentence[i])) ? tolower(sentence[i]) : toupper(sentence[i]);  // declared in the parameter already.
    }

    return sentence;
}


int main()
{
    short MinLength = 1;
    short MaxLength = 50;

    string Sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
   


    cout << "String after Inverting All Letters Case: " << endl;
    cout << InvertingCasesInSentence(Sentence) << endl;


    return 0;
} */


