
#include <iostream>
using namespace std;



/*
 Problem 7:

 Write a program to fill a 3x3 matrix with ordered numbers
 and print it, then TRANSPOS the matrix and print it.

 
 Expected Output:



 The following is a 3x3 ordered matrix:

 1    2    3
 4    5    6
 7    8    9

 The following is the transposed matrix:

 1    4    7
 2    5    8
 3    6    9

*/


void FillArrayWithOrderedNumbers(int OrderedNumbers[3][3], short rows, short columns)
{
	int counter = 0;

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			counter++; // counter = counter + 1
			OrderedNumbers[i][j] = counter;
		}
	}
}


void PrintElementsInMatrix(const int OrderedNumbers[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << OrderedNumbers[i][j] << "     ";
		}
		cout << endl;
	}
}


void FillTransposedMatrixWithElements(int TransposedMatrix[3][3], int OrderedNumbers[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			TransposedMatrix[i][j] = OrderedNumbers[j][i];
		}
	}
}


int main()
{
	int OrderedNumbers[3][3];
	FillArrayWithOrderedNumbers(OrderedNumbers, 3, 3);

	// The array 'OrderedNumbers' is now initialized with ordered numbers.

	cout << "\nThe following is a 3x3 ordered matrix: " << endl;
	PrintElementsInMatrix(OrderedNumbers, 3, 3);


	// To creatre a transposed matrix (do not overwrite the original one - Best Practice):
	int TransposedMatrix[3][3];
	FillTransposedMatrixWithElements(TransposedMatrix, OrderedNumbers,3,3 );

	// The array 'TransportMatrix' is now initialized with elements.



	// Printing the transposed matrix:
	cout << "\nThe following is the transposed matrix: " << endl;
	PrintElementsInMatrix(TransposedMatrix, 3, 3);


	return 0;
}

