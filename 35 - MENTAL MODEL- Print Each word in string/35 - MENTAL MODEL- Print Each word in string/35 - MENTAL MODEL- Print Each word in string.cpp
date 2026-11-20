#include <iostream>
#include <string>
using namespace std;


/*
 Mental Model:
 ******************************************************************************************************************************
 Pre-requisite: Simply understand the following:

 Words in a text are splitted based on a space.

 For example:

 string text = "Ahmad E-Aina is studying programming at programming Advices."

 so based on the space we will split the words

 - The first word is stored into sWord variable and then processed (to be printed out or counted or added to a container, etc.)
 - The second word will be stored into the same sWord variable (overriding the first word/value) and then processed.
   etc. etc.

   and this process of storing each word into sWord variable and then processing it (processing as required)
   is a MANDATORY / FIXED/ COMMON step no matter what the problem is.


   Similarly,
   Words in a sentence can be splitted based on, for example, a 3-letter substring.
   And all what is mentioned above applies.

   This space or the 3-letter substring, for example, is called a "delimiter".

   so, one could have:
   string delimiter = " "; // Have ONE space only . We'll elaborate on why this is.

   or

   string delimiter = "ghy"  // or based on any other character(s) you choose to do the splitting.

   side note:

   example:    substring(2,5)   = [0,5)     // takes a substring from index 2 up to index 5 not included.
               erase(13, 20)    =[13, 20)   // erases substring from index 13 up to index 20 not included.

 ******************************************************************************************************************************

 Mental Model: The following code snippet is a FIXED INEVITABLE part of the code
               Which is, again, to split each word based on the delimiter,
               store it into an sWord variable, and then process that variable according to the what the problem dictates.


               string text = "This is Ahmad studying at Programming Advices";
               // or instead, have a reading function that reads the user input.

               string delimiter = " "; // HAS to be ONE space. will explain this as we progress though.

               short pos = 0; // accompanies the delimiter.

               string sWord = ""; // accompanies the delimiter. // no space.


               Now the fun part. let's break it down into pieces and then combine them together:

               text.find(delimiter) // this method returns the index that the delimiter starts with

               // for example, if the delimter = " "       , then the index of the space is returned.
               //              if the delimeter = "abc"    , then the index that 'a' only occupied is returned.

               // Moreover - if the delimiter is NOT found, then a huge number is returned
               // such as
               // //18446744073709551615 which is,
    //some long ass random number since " " or "abc" does NOT exist in the string.
    // and because it's too long, C++ saves it in a reserved variable called npos :

    //  text.find(delimiter) !=  std::string::npos   // make sure that an index is returned = the delimiter is found.

    // while( (pos = text.find(delimiter)) !=  std::string::npos)     // true as long as pos stores the index of the delimiter = delimter is found.


           // then in this case, take the substring of the first word ONLY:

            MANDATORY STEP---> string sWord = substr(0, pos) // [0, pos) = takes a substring from index 0 to delimiter's index (not included).

            MANDATORY STEP---> if (sWord != "") // we do not empty spaces stored in sWord.  Imaging having "Ahmad      El-Aina    from         advices"
                               {
                                // do the processing here. For example:

                               //      cout << sWord << endl;

                               // or:  count ++; // to start counting the words.   (after declaring short count)

                               // or:  vWords.push_back(sWord)                     (after declaring a vector)

                               }

            MANDATORY STEP--->      AFTER  1- storing the individual word in sWord  2-processing this specific individual word
                                    we ERASE, ALWAYS from 0,
                                    this word PLUS the entire delimiter that comes after it:

                                    erase(0, pos + delimiter.length()) n// ensures that the individual word is erased plus the delimiter that comes after.



             MANDATORY STEP--->    After keeping on erasing, so that the text string variable reaches a state where
                                   it only contains the last word that is normally not followed by a delimiter


                                   Then in this case, the while statement would return false as no delimiter is found.

                                   while( (pos = text.find(delimiter)) !=  std::string::npos)

                                   In order to process this last word ( no need to store it in sWord which is done via substring(0, pos))
                                   as the text string we kept erasing from is already storing the last word:


                                   So outside the while statement have the following:


                                   if(text != "")
                                   {
                                     // simply process it here (print it out, count it, or add it to a container such as vector, etc.)

                                   }



 In Summary:

   Mental Model:

 1. Find the delimiter.
 2. Extract everything before it into sWord.
 3. Process sWord.
 4. Erase the processed portion plus the delimiter.
 5. Repeat until no delimiter exists.
 6. The remaining text is the final token; process it separately.

 The delimiter may be a space character, another character, or a string.

 This pattern remains the same whether we are:
 - Printing words
 - Counting words
 - Storing words in a vector
 - Replacing words
 - Searching for words

 Only the "processing step" changes.







*/

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

// The common FIXED them is that:
// Each word in the string is going to be stored in an sWord variable. This is an inevitable part. Using the delimiter technique.
// 
// then,
// the stored variable is processed, either by printing it out or, for example, adding it to a container to be processed further
//
// 




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


    if (sentence != " ")
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
