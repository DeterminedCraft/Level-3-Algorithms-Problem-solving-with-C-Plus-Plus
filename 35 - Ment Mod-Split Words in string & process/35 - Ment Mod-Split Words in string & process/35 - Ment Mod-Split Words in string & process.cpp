#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 ### 1: This is the BIGGEST PRE-REQUISITE to understanding the actual mental model which is section # 2 of this specific file 
 ******************************************************************************************************************************
 Pre-requisite: Simply understand the following:

 Words in a text are splitted based on a space.
 
 For example:

 string text = "Ahmad E-Aina is studying programming at programming Advices."

 so based on the space we will split the words

 - The first word is stored into 'sWord' variable. 
   then, we check that this word is not an empty space so we can process it (to be printed out or counted or added to a container, etc.).

 - The second word will be stored into the same sWord variable (overriding the first word/value).then we check that
   its value is not an empty space so that we can process it. etc. etc.

   and this process of storing each word into sWord variable and then IMMEDIATELY ensuring that its value is not 
   an empty space so we cdould process it AS REQUIRED
   is a MANDATORY / FIXED/ COMMON step no matter what the problem is.


   Similarly,
   Words in a sentence can also be splitted based on, for example, a 3-letter substring or any other substring you need.
   WHERE ALL WHAT'S MENTIONED ABOVE APPLIES.

   *** This space or the 3-letter substring, for example, is called a "delimiter".

   so, one could have:

   string delimiter = " "; // Have ONE space only . We'll elaborate on why this is.

   or

   string delimiter = "ghy"  // or based on any other character(s) you choose to do the splitting.


   side note:  The String class contain the methods 
   
   .substr(index, count of characters to take starting from & including the index)   // crucial to comprehend.
   .erase()      
   .find()   // Example   .find("N")   // returns the index of the first N character it encounters.

  
  Examples:

  substring(2, 5)     // starting from index 2, take a substring of 5 characters.
  // = takes characters from index 2 (included) to index (2 + 5 - 1) = 6 (included)

  erase(13, 20)       // starting from index 13, erase 20 characters.
  // = erases characters from index 13 (included) to index (13 + 20 - 1) = 32 (included)


               A practical example:

               string name = "Ahmad El-Aina";  // one space between 2 words.
               
               // to print the first name only:
               cout << name.substr(0,5) << endl; // starting from index 0 where A is, take 5 characters starting from & including index 0,
                                                  // this will result in "Ahmad" printed out.
                                        // again according to the formula: 
                                        // 5 here is the count of characters taken in the substring starting from index 0

                                        // separately speaking - 5 as an index, happens to be the index of the space.
                                        // SO THAT, the substring does NOT include it. But it does for the character before it.

               // However, the above line is considered hardcoding,
               // as the string value may change or come from an external source (database or user-input & what have you).

               // so make it dynamic:
               cout << name.substr(0, name.substr(name.find(" ")) << endl;

 ******************************************************************************************************************************

 Mental Model: The following code snippet is a FIXED INEVITABLE:

               Which is, again, to split each word based on the delimiter,
               store it into an sWord variable. 
               Then, make sure its value is not an empty space so that it could be processed
               according to the what the problem dictates.


               string text = "This is Ahmad studying at Programming Advices";
               // or instead, have a reading function that reads the user input.

               string delimiter = " "; // HAS to be ONE space (investigate it, I doubt it). will explain this as we progress though.

               short pos = 0; // accompanies the delimiter.

               string sWord = ""; // accompanies the delimiter. // no space.


               Now the fun part. let's break it down into pieces and then combine them together:

               text.find(delimiter) // this method returns the index that the delimiter starts with

               // for example, if the delimter = " "       , then the index of the space is returned.
               //              if the delimeter = "abc"    , then the index that 'a' only occupied is returned.

               // Moreover - if the delimiter is NOT found, then a huge number is returned
               // such as
               // 18446744073709551615 which is,
    //some long ass random number since " " or "abc" does NOT exist in the string.
    // .And because it's too long, C++ saves it in a reserved variable called string::npos :

    //  text.find(delimiter) !=  std::string::npos   
    //ensures that .find() function does NOT return some long ass number = delimiter exists as its index is found.


    // while(  ( pos = text.find(delimiter)   )  !=  std::string::npos)     // true as long as pos stores the index of the delimiter = delimter is found.
              🔼                             🔼
              🔼                             🔼 // these opening and closing brackets () are EXTREMLY IMPORTANT. Otherwise, error is rendered.

     Order of execution:
          1. text.find(delimiter)
          2. result assigned to pos
          3. pos compared against std::string::npos
          4. if comparison is true → execute loop body
          5. repeat.

          so if the while condition is true (index of the delimiter is found):

           // then in this case, take the substring of the first word ONLY:

            MANDATORY STEP---> string sWord = substr(0, pos) 

            // Takes a substring starting from index 0 of length pos.
           // Equivalent to taking characters from index 0 up to (but not including) index pos.

            MANDATORY STEP---> if (sWord != "") // we do not want empty spaces stored in sWord.  Imaging having "Ahmad      El-Aina    from         advices"
                               {
                                // do the processing here. For example:

                               //      cout << sWord << endl;

                               // or:  count ++; // to start counting the words.   (after declaring short count)

                               // or:  vWords.push_back(sWord)                     (after declaring a vector)

                               }

            MANDATORY STEP--->      AFTER  1- storing the individual word in sWord.
                                           2- making sure its value is not an empty space so
                                              then, we can process this specific individual word.

                                    we ERASE, ALWAYS from 0,
                                    this word PLUS the entire delimiter that comes after it:

                                    erase(0, pos + delimiter.length()) n// ensures that the individual word is erased plus the delimiter that comes after.



             MANDATORY STEP--->    After keeping on erasing from the text/sentence/original string,
                                   we'll reach a stage where it only contains one last word that is
                                   natuarally/ normally not followed by a delimiter


                                   Then in this case, the while statement would return false as no delimiter is found.

                                   while( (pos = text.find(delimiter)) !=  std::string::npos)

                                   In order to process this last word ( no need to store it in sWord which is done via substring(0, pos))


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

  
 ////Note: The above section # 1 is CRUCIAL to understand this actual mental model.

/*  ################################################################ 2: The Actual Mental Model ##########################################################

    So, how to put all this information together ?    Answer: It depends on how you want to do the processing:


    1- To Print the words in a text:      Then simply call the procedure:    PrintEachWordInString()  */

  //Inside MAIN() have:

  int main()
  {
      short MinLength = 1;
      short MaxLength = 1000;
      string sentence = ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);

      //unless you want to hardcode the text or feed it into the code from somewhere else.

      PrintEachWordInString(sentence);  

      return 0;

  }
    

   // Where the implementation is:

void PrintEachWordInString(string sentence)
{
    string delimiter = " "; // declared inside the procedure as the name of the procedure implies that the delimiter can not be anything other
                             // than a space. Therefore, there is no reason to pass the space delimiter as an argument to this procedure call (why complicate things ?)
    short pos = 0;
    string sWord = " ";

    while ((pos = sentence.find(delimiter)) != string::npos)
    {
        sWord = sentence.substr(0, pos);

        if (sWord != " ")
        {
            cout << sWord << endl;
        }

        sentence.erase(0, pos + delimiter.length());
    }

    if (sentence != " ")
    {
        cout << sentence << endl;
    }
}

 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2- To count the words in a text:       then, simply call the function  CountWordsInString()

// Inside MAIN() have:

int main()
{
    short MinLength = 1;
    short MaxLength = 1000;

    string sentence =ReadStringInRange("Please Enter Your String: \n", MinLength, MaxLength);
    // unless you want to hardcode the string or fed it to the code from somewhere else.

    CountWordsInString(sentence);  // and off course you need to capture the returned value in a variable.
       
}



// where the implementation is:
short CountWordsInString(string sentence)
{
    short count = 0;

    string delimiter = " ";
    short pos = 0;

    string sWord = " ";

    while ((pos = sentence.find(delimiter)) != string::npos)
    {
        sWord = sentence.substr(0, pos);

        if (sWord != "")
        {
            count++;
        }

        sentence.erase(0, pos + delimiter.length());
    }

    if (sentence != "")
    {
        count++;
    }

    return count;
}



// THE MOST IMPORTANT OF THEM ALL:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3- To Push the words in a text into a vector, simply call the function  SplitString() that takes 2 arguments:  1- The string  2- The delimiter.

// this is also used when we need, for example, to print [but in reverse] the words in a text, 
// where you iterate in reverse over the words that have been pushed into the vector.
// 
// (where number 1 above is not used unless you want to modify it (and do not do it)).
// 
// OR if you simply want to save the words into a vector first as an intermediary step before printing them
// out even in order.

vector<string> SplitString(string sentence, const string& delimiter)
{
    vector<string> vWords;

    short pos = 0;
    string sWord = "";

    while ((pos = sentence.find(delimiter)) != string::npos)
    {
        sWord = sentence.substr(0, pos);

        if (sWord != "")
        {
            vWords.push_back(sWord);
        }

        sentence.erase(0, pos + delimiter.length());
    }

    if (sentence != "")
    {
        vWords.push_back(sentence);
    }

    return  vWords;
}



void PrintElementsInVector(const vector<string>& vWords)
{
    for (const string& value : vWords)
    {
        cout << value << endl;
    }
}




int main()
{
    string sentence = "Mohammed Abu Hadhood @ProgrammingAdvices";  // unless you need user input or for the string to be fed to the code by a diff. mean.
    string delimiter = " ";

    vector <string> vWords = SplitString(sentence, delimiter);
/*                    | 
                      |------>   // to be included at the ebnd, after finishing typing the "return" keyword of the implementing function. */
    

    // and then you can, for example, print out the elements inside the vector.
    PrintElementsInVector(vWords);

    return 0;
}































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

/* So you split each word in the string based on a delimiter (a single space in this example).
* 
   Then, you save each word into an 'sWord' variable,
   then you ensure that its value is not an empty space(s) so that it could be processed
   either via printing its value to the screen, or counting it, or adding it into a container such as vector.

   Where IMMEDIATELY, after each processing operation,
   we erase from the string starting, [starting from index 0], the processd word plus the delimiter that entails it.





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
