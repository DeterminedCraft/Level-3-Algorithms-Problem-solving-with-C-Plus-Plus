
#include <iostream>
#include <string>
using namespace std;




/*
 Problem #35

 Write a program to read a string then print each word in that string.

 Example:

 Please Enter Your String ?
 Mohammed Abu-Hadhoud @ProgrammingAdvices

 Output:

 The words in your string are:

 Mohammed
 Abu-Hadhoud
 @ProgrammingAdvices

*/
// This example SHOULD be solved taking the "Difficult route" for improving logic and programming skills

// The solution is based on the mental model before it






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




void PrintEachWordInString(string sentence) // pass by value (sometimes you find out so as you progress in implementing the function)
{
    string delimiter = " "; // what we split the words based on //or for example, a 3-letter delimiter. // here it should be a space as spaces are seperating the words we want to store in an sWord variable.

    short pos = 0; // goes hand in hand with the delimiter
    string sWord = " "; // goes hand in hand with the delimiter.

    while ((pos = sentence.find(delimiter)) != string::npos) // true if a delimiter is found 
    {
        sWord = sentence.substr(0, pos);

        if (sWord != " ")  // as we could have  "Ahmad      Sara     Alice"
        {
            cout << sWord << endl;             // then process the word here. // we could for example, add it to a vector.
        }

        // after word has been processed, then we erase it off the sentence PLUS the entire delimiter.
        sentence.erase(0, pos + delimiter.length()); // erase from 0, the entire word [PLUS the delimiter using .length() so it is erased whether it's a one character (like one space here) or multi character string.
    }                                                   // so that the sentence now starts from the second word "sara"

    // at the end, after all erasements, the sentence will only contain one word at the end (stored at sWord)
    // with, normally, no delimiter after it:


    if (sentence != " ")  // the erase that results in one word left in the sentence, 
        // already erased the last processed word plus the delimiter after it.
        // this means that now, there are 2 possibilities: 1- one actual word left with naturally no delimiter after it.
        //                                                 2- one space (could be a possiblity).
        // so we'll only consider #1 (an actual non-empty string)
       // 
    {
        cout << sentence << endl; // process it here
    }

}





int main()
{
    short MinLength = 1;
    short MaxLength = 1000;

    string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
    //           |
    //           |------> Typed at the very end, after finishing typing the "return" keyword in the implementing function.


    PrintEachWordInString(sentence);


    return 0;
}









// One initial attempt using the easy rounte (still buggy):

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







void PrintEachWordInString(const string& sentence)   // pass by const. ref.
{
    size_t length = sentence.length();
    string word = " ";

    for (size_t i = 0; i < length; i++)
    {
        if (sentence[i] != ' ')
        {
            word += sentence[i];
        }

        else
        {
            cout << word << endl;
            word = " ";
        }
    }

}



int main()
{
    short MinLength = 1;
    short MaxLength = 1000;

    string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
    //           |
    //           |------> Typed at the very end, after finishing typing the "return" keyword in the implementing function.


    cout << "The words in your string are: \n";
    PrintEachWordInString(sentence);


    return 0;
}                          */

