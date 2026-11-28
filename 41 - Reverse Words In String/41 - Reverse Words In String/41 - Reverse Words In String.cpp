
#include <iostream>
#include <string>  
#include <vector>   // a MUST for using vectors.
using namespace std;

/*
 Problem #41


 Write a program to read a string and reverse its words.

 Example:

 Please Enter Your String?
 Mohammed Abu-Hadhoud I'm From Jordan

 String after reversing words:
 Jordan From I'm Abu-Hadhoud Mohammed

*/

// The best way of thinking about it is:-
// 
// Call a function named ReverseWordsInString() that returns string
// where in its implementation:-
// 
//   1- call the MENTAL MODEL SplitString() that splits words into a vector.
//   2- then, call the MENTAL MODEL JoinString() that will this time backwardly join the strings.


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
        if (text[i] == character)
        {
            count++;
        }
    }


    return count;
}


void PrintVectorElementsInReverse(const vector<string>& vWords)  // pass by constant reference.
{
    for (int i = vWords.size() - 1; i >=0; i--)
    {
        cout << vWords[i] << " ";
    }
    
    cout << endl;
}


string StringWordsBackwardsInVector(const vector<string> &vWords, const string &delimiter)
{
    // the idea is that you iterate through each one (in reverse this time)while adding the delimiter.
    string sentence; // or string sentence = "";  // be careful, not " "
    for (short i = vWords.size() - 1; i >= 0; i--)
    {
        sentence = sentence + vWords[i] + delimiter;
    }

    return sentence;
}

string ReverseWordsInString( string text) // pass by value as it turned out that we're going to erase from it
{
    vector<string> vWords;

    string delimiter = " ";

    short pos = 0; // it goes hand in hand with the delimiter.
    string sWord = "";  // it goes hand in hand with the delimiter.

    while (( pos = text.find(delimiter)) != string::npos) // if the delimiter exists, then its index will be returned.
    {
        // once the delimiter is found, 
        // take the substring from the 0 index till the delimiter not included and store it inside sWord variable:
        sWord = text.substr(0, pos);

        if (sWord != "")
        {
             // then process it:
            vWords.push_back(sWord);
        }

        // after you finish processing the word:
        // ERASE from the original string: From index 0 and up to including the processed word plus the delimiter length

        text.erase(0, pos + delimiter.length() );
    }

    // we will keep on erasing and erasing till the original sentence 
    // contain only one word fow which the while statement will return false
    // as words normally do not end with a delimiter.

    if (text != "")
    {
        vWords.push_back(text);
    }
    // vWords is now FULLY initialized with elements.

    
    return StringWordsBackwardsInVector(vWords, delimiter);
   

}



int main()
{
    short MinNumOfCharacters = 1;
    short MaxNumOfCharacters = 1000;

    string text = ReadStringInRange("Please Enter Your text: ", MinNumOfCharacters, MaxNumOfCharacters);
    // so far we can read users' input.

    // reverse words in string.
    
    string ReversedSentence = ReverseWordsInString(text);
    cout << ReversedSentence << endl;


    return 0;
}


