
#include <iostream>
#include <string>  // needed for substr()
#include <vector>   // inevitable for using vectors.
using namespace std;

// The JoinStrings() function that takes a vector full of words that we want to joing together & the separator (delimiter, but here we call it separator)

/* According to the 35 - Mental Model:

           So far, we've been splitting words in a string based on a delimiter

                where we save each word into an sWord variable > 

                make sure that the value is not an empty string, 
                so that we can process it by , for example, pushing it into a vector.


    Now, for joining strings together, we do the exact opposite of that:

    where, we declare a vector to save these strings that we want to join together.

     meaning that the JoinStrings() function is the opposite of the split() function.

            - it takes 2 arguments: this vector & the separator(delimiter).
              where it iterates through each & every element adding the separator between them

              so that a complete string containing separators between each word IS RETURNED.
           
           */



/***************************************************************
 Problem #39

 Write a program to join a vector of strings into a single string
 using a separator.

 Example output:

 Vector after join:
 Mohammed Faid Ali Maher

 // or also try
 Mohammed###Ali###Fadi
 ***************************************************************/




string JoinStrings(vector<string> vWords, const string& separator)   // vector passed by value     
{
    string sentence = ""; // or simply  string sentence; (strings here will not store garbage value). akin to  int sum = 0;   //routine. except that, here we're dealing with strings
                          
    for (const string &word : vWords)   
    {
        sentence = sentence + word + separator;
    }

    return sentence.substr(0, sentence.length() - separator.length()); // -1 only removes the last element in the string. so what if the3 delimiter got more than one charadcter ? (for example ##)
    //return sentence.substr(0, sentence.length() - 1);  // will not work, ex: try a seperator that is '##'
    // this is bad because if the separator is more than one character, then it is not going to work as only the first character of the separator will be deleted..
    // 
    // we can not use erase() as we have to provide 2 arguments: (assuming that erase can not take one argument which is incorrect)
 //  - an index from where you start erasing.
 //  - the number of elements to erase starting from the index in the first argument.                                                   // since .length() starts from 1.
}

int main()
{
    string separator = "###";  // or " "; how the question demands.
    vector<string> vWords = { "Mohammed", "Ali", "Fadi" };

    string sentence = JoinStrings(vWords, separator); // reminder : so only an array, when passed as argument to the calling function, is automatically passed along with its address in memory. this applies to arrays and not vectors
/*           |
             |---> // added at the very end, after finishing typing the "return' keyword of the implementing function.


*/
    cout << "\nVector after join: \n";
    cout << sentence << endl;


    return 0;
}


