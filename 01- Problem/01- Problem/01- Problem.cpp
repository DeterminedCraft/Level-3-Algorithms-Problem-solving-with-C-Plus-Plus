
#include <iostream>
#include <cstdlib> // for randomness
#include <iomanip>   // for setw() manipulator


using namespace std;


/*
 Problem #01

 Write a program to fill a 3x3 matrix with random numbers.


 Example Output:

 The following is a 3x3 random matrix:
 16      45      30
 13      51       3
 24      19     100

*/


int GenerateRandomNumberInRange(int from, int to) // passed by value as it was decided.
{
	int RandNumber = rand() % (to - from + 1) + from;
	return RandNumber;
}


void Fill2dArrayWithRandomNumbers(int numbers[3][3], short rows, short columns) // AUTOMATICALLY passed by ref. without including the & sign (including & renders exception).
{
	for (short i = 0; i < rows; i++) // i=0, i=1, i=2      // for rows  // short i (instead of int i) for avoiding comparing mixed data types where the compiler has to perform implicit conversions (from short, back to int)
	{
		for (short j = 0; j < columns; j++)  // j=0, j=1, j=2   // for columns
		{
			numbers[i][j] = GenerateRandomNumberInRange(1, 100);    // our CORE random generator utility.
		}
	}
}

void Print2DimensionalArrayElements(const int numbers[3][3], short rows, short columns) // passed by const. ref. (including the & sign renders exception).
{
	for (int i = 0; i < rows; i++)   // for rows  i=0, i=1, i=2
	{
		for (int j = 0; j < columns; j++)  // for columns j=0, j=1, j=2
		{
		     cout << setw(3) << numbers[i][j] << "     "; //fills the 8 spaces strting from the right
			//cout << numbers[i][j] << " ";
			//printf("%0*d      ", 3, numbers[i][j]); // but this is NOT what is required as you're not asked for 003 or 012 for example. // leaving it for fun
		}

		cout << endl;
	}
}


int main()
{
   srand((unsigned)time(NULL)); // to seed random numbers.

   int numbers[3][3]; 
   Fill2dArrayWithRandomNumbers(numbers,3,3); // an array is passed as an argument along with its address in memory. Thus, it's parameter is ALWAYS passed by reference without the & sign // arguments 3,3 for avoiding hardcoding the ranges in the ensted for loopS conditonS. (that is all)
   // The 2-Dimensional array is now initialized with elements.


   cout << "The following is a 3x3 random matrix" << endl;
   Print2DimensionalArrayElements(numbers,3,3);  // an array is passed as an argument along with its address in memory. Thus, it's parameter is ALWAYS passed by reference without the & sign 


	return 0;
}


