
#include <iostream>
#include <string>
using namespace std;

/* Generally speaking, all programming languages have a built in trim() function
   that takes a string and trims all space(s) off the left and off the right of the string.

   In this example, We'll make our own 3 trim() functionS:
   TrimLeft(), TrimRight(), & trim()

   where trim() does both, the trimming off the left and off the right
   by calling, inside it, Trimleft() and  TrimRight()     
   
   */




   /*
   Problem #38

    Write a program to read a string, then trim:
    - Left spaces
    - Right spaces
    - All surrounding spaces

   Example:

    String Before Trimming =     Mohammed Abu-Hadhoud         (With spaces to the right and to the left )

    Trim Left  = Mohammed Abu-Hadhoud             (Only spaces to the left are trimmed)
    Trim Right =     Mohammed Abu-Hadhoud         (Only spaces to the right are trimmed)
    Trim       = Mohammed Abu-Hadhoud             (Both spaces to the left and to the right are trimmed !)

   */



// The idea: 
// 
// use for-loop to iterate through each and every character of the string.
// when reaching an index belonging to non-space character, 
// then, IMMEDIATELY return a substring from this index of this non-space character and to the end of the string.


string TrimLeft(string sentence)
{
    short length = sentence.length();
    for (short i = 0; i < length; i++)
    {
        if (sentence[i] != ' ')   // if character (element) is a non-space character 
        {
            return sentence.substr(i, length - i);  // the syntax to take the substring starting from a specific index, till the end of the string.
        }
    }

    return ""; // assuming that the string 'sentence' is ALL empty spaces; then the function will still need to return something.
}



string TrimRight(string sentence) // pass by value.
{
    short length = sentence.length(); 
    for (short i = length -1;  i >= 0;  i--)  // iterating from the last index.  // i = 20 , i = 19......i = 0
    {
        if (sentence[i] != ' ') // once you reach a non-space character.
        {
            return   sentence.substr(0, i + 1);    //  you have to add '1' because  substr[ )
        }
    }
 return "";
    // if the return statement enclosed within the if statment is not executed = the if condition is false
    // meaning that, the string 'sentence' is composed of nothing but space(s)
    // then in this case, the function will still have to return something.
    // otherwise, an exception is thrown.
}



string trim(string sentence)   // pass by value.
{
    return TrimLeft(TrimRight(sentence));
}
/*   // inefficient: try to return everything on one shot/on eline

string trim(string sentence)   // pass by value.
{
    string LeftTrimmedString = TrimLeft(sentence);

    return TrimRight(LeftTrimmedString);
}
*/


int main()
{
    string name = "       ";    // or read a string input from user. Here we're expediting the process.

    cout << "String Before Trimming = " << name << endl;

    cout << "Trim Left  = " << TrimLeft(name) << endl;
    cout << "Trim Right = " << TrimRight(name) << endl;
    cout << "Trim  = " << trim(name) << endl;





    return 0;
}

