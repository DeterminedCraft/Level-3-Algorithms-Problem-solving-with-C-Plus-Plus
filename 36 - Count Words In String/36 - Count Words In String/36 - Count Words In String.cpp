
#include <iostream>
#include <string>
using namespace std;


/*
 Problem #36

 Write a program to read a string, then count the number of words in that string.

 Example:

 Please Enter Your String?
 Mohammed Abu-Hadhoud @ProgrammingAdvices

 The number of words in your string is: 3

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



// using our mental model, we HAVE TO store each word in sWord variable 
// and then process it (The fixed part). 
// Processing as in: printing out each word, storing each word in a container & process further, or counting them ( for this program).
// The delimiter concept is used as base to achieve that.

short CountWordsInString(string sentence)   // pass  by value.
{
    short count = 0;

    string delimiter = " ";  // ONE space only.
    short pos = 0;  //goes hand in hand with delimiter.

    string sWord = " "; // initialiying it (that's all). //goes hand in hand with delimiter.

    while ((pos = sentence.find(delimiter)) != string::npos) // true if delimiter is found so you can store the word.
    {
        sWord = sentence.substr(0, pos);

        if (sWord != "")   // if tou have for example "Omar    Bassem      Suha"
        {
            count++;
        }

        // we processed the word (counting it). Now, we need to erase from 0 index plus the word we counted plus the delimiter that follows it.
        sentence.erase(0, pos + delimiter.length()); 
    }
    
    // now after all the erasing, we will end up with string sentence containing the last word only
    // and normally without any delimiter entailing it.
    // so let us count it too

    if (sentence != "") // as long as sentence does not contain a space  // why not a space buT "" ?
    {
        count++;    // incrfease the count by 1.
    }

    return count;
}

/*
 if(sentence != "")  // is very general: as long as sentence has value no matter what it is.

 if(sentence != " ") // more specific: as long as sentence has a value that is not an empty space.




*/




int main()
{
    short MinLength = 1;
    short MaxLength = 1000;

    string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
    //           |
    //           |------> Typed at the very end, after finishing typing the "return" keyword in the implementing function.

    cout << "The number of words in your string is: " << CountWordsInString(sentence) << endl;
    

}