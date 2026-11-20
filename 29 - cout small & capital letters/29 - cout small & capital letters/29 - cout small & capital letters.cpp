
#include <iostream>
#include <string>
using namespace std;

/*
 Problem #29:

 Write a program to read a string from the user, then count
 the number of uppercase (capital) letters and lowercase (small)
 letters in that string.

 Example:

 Input:
 Mohammed Abu-Hadhoud

 Output:

 String Length = 20
 Capital Letters Count = 3
 Small Letters Count = 15


*/
// The LOGIC & IDEAS behind the code are of EXTREME importance.
// 
// This example is USEFUL for full-stack development
// For example - To validate that the user's password meets length requirement, the number of upper & lower cases characters entered.

// This example is solved utilizing enums for strengthening logic and coding abilities.
// Nevertheless, it can be solved without resorting to enums.


// solution: 
// since enums are used, then it's to be coded the FIRST THING EVER on top !.



enum enWhatToCount { LowerCase = 0, UpperCase = 1, All = 2 };
// the enumeration constants (enumerators) that are LowerCase, UpperCase, & ALL are used as labels for the raw values they represent
// so, FORVER FORGET about these raw values and ALWAYS use their labels.

//So far, only enum user-defined data type has been created and nothing more.

string ReadStringValue(const string& message)  // Pass by constant reference.
{
    string value; // what's returned.

    cout << message;
    getline(cin, value);  // ONLY for strings and strings ONLY 
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


short CountLength(const string &text, const enWhatToCount &WhatToCount = enWhatToCount::All)   // it is also said that enums occupy very little space in memory. Therefore, aim for passing it by valu.
{
    short length = text.length();   
    short counter = 0;

    // length is declared as short here because the function is supposed to return a short data type.
    // text.length() returns a size_t data type.
    // An implicit conversion from size_t to short occurs here.
    // Normally this could lead to data loss if the string length
    // exceeds the range of short.
    // In this program the conversion is acceptable because the
    // maximum allowed string length is small (1000 characters),
    // which easily fits within the range of short.
    
    if (WhatToCount == enWhatToCount::All)
    {
        return length;
    }


    for (size_t i = 0; i < length; i++) // starting with for-loops right away without wasting any time !
    {
       
        if (WhatToCount == enWhatToCount::LowerCase && islower(text[i]))
        {
            counter++;    
        }


        else if (WhatToCount == enWhatToCount::UpperCase && isupper(text[i]))
        {
            counter++;
        }

        /* The above is better for readability than:
        
        if (WhatToCount == enWhatToCount::LowerCase)
        {
            if (islower(text[i]))
            {
                counter++;
            }
        }
        */
    }

     return counter;
}

int main()
{
    
    short MinNumOfCharacters = 1;
    short MaxNumOfCharacters = 1000;

    string text = ReadStringInRange("Please enter a string: ", MinNumOfCharacters, MaxNumOfCharacters);
    //           |
    //           |-->  // aded at the very end after finishing typing the "return" keyword of the implementing function. */

    // The MAIN IDEA is that you pass the enum as argument:
    // 


    
     // cout << "\nString Length = " << CountLength(text, enWhatToCount::All) << endl; 
     // works when the implementation is: short CountLength(const string &text, const enWhatToCount &WhatToCount)  
     
    

    cout << "\nString Length = " << CountLength(text) << endl; // If I want text as the only argument.// failure to provide a 2nd argument so the default value is resorted to, in the implementation.

    cout << "Small Letters Count = " << CountLength(text, enWhatToCount::LowerCase) << endl;   // side note: enWhatToCount::LowerCase is merely a label for 0 (or simply =0)
    cout << "Capital Letters Count = " << CountLength(text, enWhatToCount::UpperCase) << endl;  // side note: enWhatToCount::UpperCase is merely a label for 1 (or simply = 1)

    // for the last 2 lines above, the default value in the implementation is overridden with the actual arguments in the calling function.
}











/*

// Below is first-attempt UNOPTIMIZEED solution USING ENUMS:
enum enWhatToCount { LowerCase = 0, UpperCase = 1, All = 2 }; // the enumeration constants (enumerators) that are LowerCase, UpperCase, & ALL
// are used as labels for the raw values they represent. So FOREVER FORGET about these raw values and ALWAYS use the labels instead.

// so far, only an enum user-defined data type has been created. Nothing more; nothing less.



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






short CountLength(const string &text, const enWhatToCount &WhatToCount)
{
    short count = 0;
    size_t length = text.length();;  // added later on top when it was needed for optimization.

    switch (WhatToCount)
    {

    case enWhatToCount::All:
        return length;




    case enWhatToCount::LowerCase:

        for (size_t i = 0; i < length; i++)
        {
            if (islower(text[i]))
            {
                count++;
            }
        }

        return count;



    case enWhatToCount::UpperCase:

        for (size_t i = 0; i < length; i++)
        {
            if (isupper(text[i]))
            {
                count++;
            }
        }

        return count;
       
    }
}



int main()
{
    short MinNumOfCharacters = 1;
    short MaxNumOfCharacters = 1000;

    string text = ReadStringInRange("Please enter a string: ", MinNumOfCharacters, MaxNumOfCharacters);
    //           |
    //           |-->  // aded at the very end after finishing typing the "return" keyword of the implementing function. */


   /*
    cout << "\nString Length = " << CountLength(text, enWhatToCount::All) << endl;
    cout << "Capital Letters Count = " << CountLength(text, enWhatToCount::UpperCase) << endl; 
    // side note: keep in mind that  enWhatToCount::UpperCase is label for the raw value of 1.

    cout << "Small Letters Count = " << CountLength(text, enWhatToCount::LowerCase) << endl;


    return 0;

}



*/
