
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// successfully re-attempted on November 18th

/*
 Problem #37

 Write a program to read a string, then make a function to split
 each word into a vector.

 Sample Run:

 Please Enter Your String?
 Mohammed Abu-Hadhoud @ProgrammingAdvices

 Tokens = 3

 Mohammed
 Abu-Hadhoud
 @ProgrammingAdvices


*/

string ReadStringValue(const string& message)  // pass b y const. ref.
{
    string value;  // what's returned

    cout << message;
    getline(cin, value);
    cout << endl;

    return value;
}


bool ValidateStringInRange(const string& value, short MinLength, short MaxLength)  // pass by const. ref. // ranges ALWAYS passed by value
{
    return (MinLength <= value.length() && value.length() <= MaxLength);
}

string ReadStringInRange(const string& message, short MinLength, short MaxLength) // pass by const. ref.  // Ranges ALWAYS passed by value.
{
    string value;   // what's returned.

    value = ReadStringValue(message);  // 'value' is to be IMMEDIATELY validated against the range, in the condition.

    while (!ValidateStringInRange(value, MinLength, MaxLength))
    {
        cout << "Error - Text entered should be between " << MinLength << " to " << MaxLength;
        value = ReadStringValue(message);
    }

    return value;
    // The block of code above is to be sequentially composed line by line
    // and at the end, implement all the functions above.
}


vector<string> SplitString(string text, const string& delimiter) // text is passed by value. 
{
    vector<string> vWords;  // what's returned.

    short pos = 0;   // goes hand in hand with delimited.
    string sWord = "";  // gies hand in hand with delimter.

    while ((pos = text.find(delimiter)) != std::string::npos)   // true if the delimiter is found.
    {
        sWord = text.substr(0, pos);    // inevitable step ALWAYS: first save each word into the sWord variable
        if (sWord != "")  // because we could have  "Ahmad     Suzan     ALki"
        {
            vWords.push_back(sWord);  // now you process the saved word (ex: printing it out or counting it or saving it in a vector as we've to do here).
        }

        // after the processing is complete, erase from the sentence, from index 0 all the way to the delimiter that comes after the word.
        text.erase(0, pos + delimiter.length());
    }
    // as for the last word that is NORMALLY not followed by the delimiter
    // it can only be added to the vector utilizing the following:

    if (text != "")
    {
        vWords.push_back(text);
    }

    return vWords;
}


void PrintElementsInVector(const vector<string>& vWords)  // pass by const. ref.  // & sign is needed for vectors but can NOT be included for arrays (renders exception).
{
    for (const string& value : vWords)   // pass by const. ref.   // include the name of the dynamic container after the column:
    {
        cout << value << endl;
    }
}

int main()
{
    // we start the program by calling SplitString() function that takes a string and a delimiter as argumwents.
    // // this function returns a vector initialized with words.
    // (unless you want to use the built-in C++ function which is NOT what we seek here for improving our logic and thinking)

    short MinLength = 1;
    short MaxLength = 500;

    string delimiter = " ";  // ONE space only.

    string text = ReadStringInRange("Enter a string: ", MinLength, MaxLength);

    cout << text << endl;

    vector<string> vWords = SplitString(text, delimiter);  // it takes the string & delimiter as arguments.
    /*                   |
                         |---> // added at the very end, after finishing typing the "return" keyword of the implementing function. */

    cout << "\nTokens = " << vWords.size() << endl;
    PrintElementsInVector(vWords);  // the vectror argument is automatically passed along with its address in memory. Hence, in the implementation it is ALWAYS passed by ref.

    return 0;
}


