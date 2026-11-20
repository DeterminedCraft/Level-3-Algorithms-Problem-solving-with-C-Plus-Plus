
#include <iostream>
#include <vector>  // inevitable for vectors.
#include <string>  

using namespace std;

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
 
// A buit-in splitting function do exist in most programming languages.
// However, you NEED TO UNDERSTAND the logic behind it by implementing this function by yourself.
// 
// The concept behind it:
//
// to create a function called [SPlitString] that takes the 1) entire string 2) PLUS the delimiter
// 
// where you return a vector, initialized with the splitted words, to the calling function inside main().
// then you can do whtever you wish with this vector ( a piece of cake).
// that is all.

// CRUCIAL  :   Whether with a built-in function or a user-implemented one,
//              one of the common scenarios is having a string value containing words seperated by a comma
// for example:  "Ahmad, Samer, Maha, sally"
// where you split based on the comma ','
// which, in our own implemented function, we'll have:     string delimiter = ","
// however, this example is slightly deifferent.


vector<string> SplitString(string sentence, const string& delimiter)  // passing the vector by references in order to initialize it inside main(). Including the & is mandatory unlike arrays (fixed-length dta structure).
{   
    vector<string> vWords;  // what's returned.

    // as  usual, we will d operations on 'sentence' so it has to be passed by value.
    short pos = 0;  // goes hand in had with th delimited.
    string sWord = ""; //goes hand in hand with delimiters.  // simply initializing it here.

    while ((pos = sentence.find(delimiter)) != string::npos)  // if true, then the position(index) of the delimiter is found
    {
        sWord = sentence.substr(0, pos); // INEVITABLE step of storing the word in sWord variable

        if (sWord != "")      // and as long as it is not empty,
        {
            vWords.push_back(sWord);  // then, we can process it by, in this example, pushing it into a vector instead of just printing it out or counting it.
        }

        // after processing the value stored in sWord, erase everything in the sentence from 0 and up to including the entire delimiter that comes after the word.

        sentence.erase(0, pos + delimiter.length());
    }

    // now the sentence will be erased to the point of only having one last word that is normally not followed by a delimiter
    // so to push it into the vector:

    if (sentence != "")
    {
        vWords.push_back(sentence); // it adds the last word in the string
    }

    return  vWords;
}


void PrintElementsInVector(const vector<string>& vWords)
{
    for (const string &value: vWords)  // vWords must  be a dynamic container.
    {
        cout << value << endl;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    string sentence = "Mohammed Abu Hadhood @ProgrammingAdvices";

    short MinLength = 1;
    short MaxLength = 500;

    string delimiter = " ";   // ONE space only.
    vector <string> vWords = SplitString(ReadStringInRange("Enter a string: ", MinLength, MaxLength),  delimiter);
/*                    |
*                     |---> // typing it at the very end, after finishing typing the "return" keyword of the implementing fnction.
*/
    // the vector has been filled with the splitted words.



    cout << "Tokes = " << vWords.size() << endl << endl;


    PrintElementsInVector(vWords);


    return 0;
}



/*
// works but the question asked you to implement a FUNCTION; not a procedure 
void FillVectorWithSplittedWords( string sentence, vector<string>& vWords, const string &delimiter)  // passing the vector by references in order to initialize it inside main(). Including the & is mandatory unlike arrays (fixed-length dta structure).
{   // as  usual, we will d operations on 'sentence' so it has to be passed by value.
    short pos = 0;  // goes hand in had with th delimited.
    string sWord = ""; //goes hand in hand with delimiters.  // simply initializing it here.

    while ((pos = sentence.find(delimiter)) !=   string::npos)  // if true, then the position(index) of the delimiter is found
    {
        sWord = sentence.substr(0, pos); // INEVITABLE step of storing the word in sWord variable

        if (sWord != "")      // and as long as it is not empty,
        {
            vWords.push_back(sWord);  // then, we can process it by, in this example, pushing it into a vector instead of just printing it out or counting it.
        }

        // after processing the value stored in sWord, erase everything in the sentence from 0 and up to including the entire delimiter that comes after the word.

        sentence.erase(0, pos + delimiter.length());
    }

    // now the sentence will be erased to the point of only having one last word that is normally not followed by a delimiter
    // so to push it into the vector:

    if (sentence != "")
    {
        vWords.push_back(sentence);
    }
} 


void PrintElementsInVector(const vector<string>& vWords)
{
    size_t size = vWords.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << vWords[i] << endl;
    }
}

int main()
{
    string sentence = "Mohammed Abu Hadhood @ProgrammingAdvices";

    string delimiter = " ";   // ONE space only.
    

    vector<string> vWords; 
    FillVectorWithSplittedWords(sentence, vWords, delimiter);
    
    // the vector has been filled with the splitted words.



    cout << "Tokes = " << vWords.size() << endl << endl;


    PrintElementsInVector(vWords);


    return 0;
}

*/  
