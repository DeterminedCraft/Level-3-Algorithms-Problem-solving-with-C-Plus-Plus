
#include <iostream>
#include <string>    // for using substr()
#include <vector>   // inevitable for vectors
using namespace std;



/***************************************************************
 Problem #40

 Write a program to join a vector of strings into a single string
 using a separator.

 Example output:

 Vector after join:
 Mohammed Faid Ali Maher

 Array after join:
 Mohammed Faid Ali Maher
 ***************************************************************/

 // Overloading IS EXTREMLY IMPORTANT in programming.

 // Implementation demonstrates function overloading:
 // The idea is that, sometimes it's more practical
 // to have more than one function with the EXACT same name
 // but with different imlementations.
 // for example
 // why have a calculator program with the following functions:
 // SumTwoIntegers(), SumTwoDoubles(), SumThreeIntegers() , etc.
 // where you can create one sum() function, overloaded with different implementations.
 //
 // The EXACT idea applies here:
 // Why have JoinStringsInArray  & JoinStringsInVector ??  Just have JoinString() function and life is eASIER.


string JoinString(const string array[4], short length, const string& delimiter) // array automatically passed by ref. Including & renders exception.
{
    string sentence;   // does not store garbage value.  // OR string sentence ="" (no space) // akin to int sum = 0 (routine). But here it's sum for strings (same as string sentence ="")

    for (short i = 0; i < length; i++)
    {
        sentence = sentence + array[i] + delimiter;
    }

    return sentence.substr(0, sentence.length() - delimiter.length());

}

string JoinString(const vector<string>& vWords, string delimiter)
{
    string sentence;
    for (const string& word : vWords)
    {
        sentence = sentence + word + delimiter;
    }

    return sentence.substr(0, sentence.length() - delimiter.length());
}

int main()
{
    string delimiter = " ";

    short length = 4;
    string array[4] = { "Mohammad", "Fadi", "Ali", "Maher" };

    cout << "Array after join : " << endl;
    cout << JoinString(array, length, delimiter) << endl;// array is automatically passed along with its address in memory. Hence it's always passed by ref. without including the & sign (renders exception)


    cout << "\nVector after join : " << endl;
    vector<string> vWords = { "Mohammad", "Fadi", "Ali", "Maher" };
    cout << JoinString(vWords, delimiter) << endl;



    return 0;
}


