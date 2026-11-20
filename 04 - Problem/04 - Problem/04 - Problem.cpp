
#include <iostream>
#include <cstdlib>  // for randomness 
#include <iomanip>  // for setw(#)
using namespace std;


/*

 Problem #4:

 Write a program to fill a 3x3 matrix with random numbers,
 then print each column sum.

 Example Output:


 The following is a 3x3 random matrix:

   5      1      87
  46     12       2
  87      2      68


 The following are the sum of each column in the matrix:

 Col 1 Sum = 138
 Col 2 Sum = 15
 Col 3 Sum = 157


*/

int GenerateRandomNumbersInRange(int from, int to)
{
	int RandomNumber = rand() % (to - from + 1) + from;
	return RandomNumber;
}



void Fill2DarrayWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns) // array automatically passed by ref. Including & renders esception. // passed by value as shoers occupy little space in memory.
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			RandomNumbers[i][j] = GenerateRandomNumbersInRange(1, 100);
		}
	}
}


void PrintElementsIn2Darray(const int RandomNumbers[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << setw(3) << RandomNumbers[i][j] << "     ";
		}

		cout << endl;
	}
}

int SumOfNumbersInEachColumn(const int RandomNumbers[3][3], short rows, short j)
{
	int sum = 0;

	for (short i = 0; i < rows; i++)
	{
		sum += RandomNumbers[i][j];
	}

	return sum;
}


void PrintSumOfEachColumn(const int RandomNumbers[3][3], short rows, short columns)
{
	for (short j = 0; j < columns; j++)
	{
		cout << "Column " << j << " sum = " << SumOfNumbersInEachColumn(RandomNumbers, rows, j) << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL)); // to seed random numbers.

	int RandomNumbers[3][3];
	Fill2DarrayWithRandomNumbers(RandomNumbers, 3, 3); // number of rows and columns passed as arguments ONLY & ONLY to avoid hardcoding them in the outer & inner nested for-loops.

	// The array 'RandomNumbers' has been filled with random numbers.

	cout << "\nThe following is a 3x3 random matrix:" << endl;
	PrintElementsIn2Darray(RandomNumbers, 3, 3); // again, the number of rows and columns passed as arguments ONLY & ONLY to avoid hardcoding the conditionS in the outer and inner for-loopS.

	cout << "\nThe following are the sum of each column in the matrix: " << "\n";
	PrintSumOfEachColumn(RandomNumbers, 3, 3); // the number of rows and columns are passed as arguments to ONLY & ONLY precent hardcoding them in the conditionS of the outer & inner for-loopS.


	return 0;
}


