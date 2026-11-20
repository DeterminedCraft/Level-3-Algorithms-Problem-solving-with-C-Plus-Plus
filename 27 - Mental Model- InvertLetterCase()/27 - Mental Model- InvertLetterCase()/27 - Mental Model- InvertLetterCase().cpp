
#include <iostream>
using namespace std;


/* Mental Model: InvertALetterCase()

   It inverts a single letter case and returns it. Here is the implementation:



   char InvertALetterCase(char character) // pass by value
   {

     return isupper(character) ?  tolower(character) : toupper(character);  // ALL 3 functions here are C++ built-in ones.

   }

*/
//============================================================================================================================================

/*
 Problem 27:

 Write a program to read a character, then invert its case
 (uppercase becomes lowercase and lowercase becomes uppercase),
 and print the result.

 Sample Output:


 Please Enter a Character?
 a

 Char after inverting case:
 A

*/



char ReadCharacterValue(const string& message)
{
    char c;  // what's returned.

    cout << message;
    cin >> c;
    cout << endl;

    return c;
}



bool ValidateCharacterInRange(char c, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter)
{
    return ((MinCapitalLetter <= c && c <= MaxCapitalLetter) || (MinSmallLetter <= c && c <= MaxSmallLetter)); // no need for (int)c explicit conversion in this case when handling characters.
}



char ReadCharacterInRange(const string& message, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter) // ranges ALWAYS passed value.
{
    short count = 0;
    char c;  // what's returned.

    do
    {
        count++;

        if (count > 1)
        {
            cout << "Only one letter is allowed.\n";
        }

        c = ReadCharacterValue(message);  // 'c' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateCharacterInRange(c, MinCapitalLetter, MaxCapitalLetter, MinSmallLetter, MaxSmallLetter));

    return c;

    // the above lines of code are to be sequentially composed line by line. At the end, implement all functions one by one.
}



char InvertALetterCase(char character)  // pass by value.
{
    return isupper(character) ? tolower(character) : toupper(character);
}





int main()
{
    //65 - 90 for A to Z
    //97- 122 for a to z
    short MinCapitalLetter = 65;
    short MaxCapitalLetter = 90;

    short MinSmallLetter = 97;
    short MaxSmallLetter = 122;

    char character = ReadCharacterInRange("Please enter a letter character: ", MinCapitalLetter, MaxCapitalLetter,
        MinSmallLetter, MaxSmallLetter);
    // now, the variable 'character' is storing a letter character ONLY anywhere for A to Z    or a to z. As validation of the input is implemented.


    cout << "Character after inverting case: \n";
    cout << InvertALetterCase(character) << endl;


    return 0;
}



//=======================================The following is some PRIMITIVE & an UNOPTIMIZED solution===================================================
/*

char ReadCharacterValue(const string& message)
{
    char c;  // what's returned.

    cout << message;
    cin >> c;
    cout << endl;

    return c;
}



bool ValidateCharacterInRange(char c, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter)
{
    return ((MinCapitalLetter <= c && c <= MaxCapitalLetter) || (MinSmallLetter <= c && c <= MaxSmallLetter)); // no need for (int)c explicit conversion in this case when handling characters.
}



char ReadCharacterInRange(const string& message, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter) // ranges ALWAYS passed value.
{
    short count = 0;
    char c;  // what's returned.

    do
    {
        count++;

        if (count > 1)
        {
            cout << "Only one letter is allowed.\n";
        }

        c = ReadCharacterValue(message);  // 'c' is to be IMMEDIATELY validated against the range, in the while condition.

    } while (!ValidateCharacterInRange(c, MinCapitalLetter, MaxCapitalLetter, MinSmallLetter, MaxSmallLetter));

    return c;

    // the above lines of code are to be sequentially composed line by line. At the end, implement all functions one by one.
}




bool IsCharacterCapital(char character, short MinCapitalCharacter, short MaxCapitalLetter)
{
    return (MinCapitalCharacter <= character && character <= MaxCapitalLetter);
}




char InvertLetterCase(char character, short MinCapitalLetter, short MaxCapitalLetter)  // pass by value
{
     return IsCharacterCapital(character, MinCapitalLetter, MaxCapitalLetter) ? tolower(character) : toupper(character);
}
    // the below is a good approach. Nevertheless, unoptimized (Nevertheless, even the above line is itself remains unoptimized too).
    /*
    if (IsCharacterCapital(character, MinCapitalLetter, MaxCapitalLetter))
    {
        return tolower(character);
    }

    return toupper(character);






int main()
{
    //65 - 90 for A to Z
    //97- 122 for a to z
    short MinCapitalLetter = 65;
    short MaxCapitalLetter = 90;

    short MinSmallLetter = 97;
    short MaxSmallLetter = 122;

    char character = ReadCharacterInRange("Please enter a character: ", MinCapitalLetter, MaxCapitalLetter,
                                                                        MinSmallLetter, MaxSmallLetter);


    cout << "Character after inverting case: \n";
    cout << InvertLetterCase(character, MinCapitalLetter, MaxCapitalLetter) << endl;
    // if compiler is to reach the line above, then this means that the character value passed as argument
    //has to be either A to Z    or a to z   as the user input is validated to ONLY be within the ranges of these values.
    return 0;
}

*/
