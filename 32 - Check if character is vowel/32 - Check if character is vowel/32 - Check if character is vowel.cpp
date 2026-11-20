
#include <iostream>
using namespace std;


/*
 Problem #32

 Write a program to read a character, then check if it is a vowel or not (Vowels are: a, e, i, o, u).

 Example:


 Please Enter a Character?
 a

 YES Letter 'a' is vowel.

*/


char ReadCharacterValue(const string& message) //pass by const. ref.
{
	char character; // what's returned.

	cout << message;
	cin >> character;
	cout << endl;

	return character;
}



bool ValidateCharacterInRange(const char& character, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter)  // pass by const. ref. as 'character' is ONLY used for comparison againstr the range (no need to create a spearate memory space for it just to compare it with ramnges)
{
	return ((MinCapitalLetter <= character && character <= MaxCapitalLetter) || (MinSmallLetter <= character && character <= MaxSmallLetter));
}



char ReadCharacterInRange(const string& message, short MinCapitalLetter, short MaxCapitalLetter, short MinSmallLetter, short MaxSmallLetter) // pass by const. ref.  // ranges ALWAYS passed by value.
{
	char character;  // what's returned.

	character = ReadCharacterValue(message);  // 'character' is to be IMMEDIATELY validated against the range, in the while condition.

	while (!ValidateCharacterInRange(character, MinCapitalLetter, MaxCapitalLetter, MinSmallLetter, MaxSmallLetter))
	{
		cout << " Error- No Numeric/Special Characters allowed. ";
		character = ReadCharacterValue(message);
	}

	return character;
}


bool IsCharacterVowel(const char& character)  // pass by const. ref.
{
	char character = toupper(character); // so that case sensitivity is NOT a factor.

	return ( (character == 'A') || (character == 'E') || (character == 'I') || (character == 'O') || (character == 'U')); // or small letters for .tolower()
}

	/*  // an UNOPTIMIZED solution because if the first statement does not return true, then .toupper() has to execute again AT LEAST for one more time.
	   //  also, used the actual letter instead of their ASCII representation in table (= readable and deems the code much less prone to error).

	return (  toupper(character) == 65 || toupper(character) == 69 
		   || toupper(character) == 73 || toupper(character) == 79 
	       || toupper(character) == 85 || toupper(character) == 89); 
	
	*/




int main()
{
	char MinCapitalLetter = 'A';
	char MaxCapitalLetter = 'Z';

	char MinSmallLetter = 'a';
	char MaxSmallLetter = 'z';

	char character = ReadCharacterInRange("Enter a letter: ", MinCapitalLetter, MaxCapitalLetter,
		                                                      MinSmallLetter, MaxSmallLetter);
	/*       |
             |-------->  // added atr the very end after finishing typing the "return" keyword in the implementing function.  */

	if (IsCharacterVowel(character))
	{
		cout << "Yes, letter \'" << character << "\'" << " is a vowel \n";
	}

	else
	{
		cout << "NO, letter '" << character << "' is NOT a vowel\n";
	}

	// The ternary operator this time is NOT good for readability.
	//(IsCharacterVowel(character)) ? cout << "Yes, letter \'" << character << "\'" << " is a vowel \n"   :  cout << "NO, letter '" << character << "' is NOT a vowel\n";




	return 0;
}

