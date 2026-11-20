
#include <iostream>
#include <cstdlib>  // for randomness
using namespace std;

/************************************************************
 Problem #08

 Write a program to fill TWO 3x3 matrices with random
 numbers and then multiply them into a 3rd matrix and
 print it.

 Expected Output:

 Matrix1:

 08    07    07
 01    06    10
 10    01    09

 Matrix2:

 04    05    06
 04    05    08
 06    08    01

 Results:

 32    35    42
 04    30    80
 60    08    09

************************************************************/


int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}



void FillMatrixWithRandomNumbers(int RandomNumbersMatrix1[3][3], int rows, int columns)  // passed by ref (including & renders exception).
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbersMatrix1[i][j] = GenerateRandomNumberInRange(1, 10);
        }
    }
}


void FillMatrixWithMultiplyResults(int MultiplyResultsMatrix[3][3], const int RandomNumbersMatrix1[3][3], const int RandomNumbersMatrix2[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            MultiplyResultsMatrix[i][j] = RandomNumbersMatrix1[i][j] * RandomNumbersMatrix2[i][j];
        }
    }
}


void PrintElementsInMatrix(int Matrix[3][3], short rows, short columns)  // unifying the parameter's name.
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            printf("%0*d     ", 2, Matrix[i][j]);
        }

        cout << endl;
    }
}



int main()
{
    srand((unsigned)time(NULL));  // to seed random numbers.


    int RandomNumbersMatrix1[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix1, 3, 3);
    // the matrix 'RandomNumbersMatrix1' has been filled with random numbers.

    //Printing elements in Matrix 1:
    cout << "Matrix 1: " << endl;
    PrintElementsInMatrix(RandomNumbersMatrix1, 3, 3);







    int RandomNumbersMatrix2[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix2, 3, 3);
    // the matrix 'RandomNumbersMatrix2' has been filled with random numbers.

    //Printing elements in Matrix 2:
    cout << "\nMatrix 2: " << endl;
    PrintElementsInMatrix(RandomNumbersMatrix2, 3, 3);





    int MultiplyResultsMatrix[3][3];
    FillMatrixWithMultiplyResults(MultiplyResultsMatrix, RandomNumbersMatrix1, RandomNumbersMatrix2, 3,3);

    //Printing elements in Multiplication Results Matrix :
    cout << "\nMultiplication Result: " << endl;
    PrintElementsInMatrix(MultiplyResultsMatrix, 3, 3);





    return 0;
}


