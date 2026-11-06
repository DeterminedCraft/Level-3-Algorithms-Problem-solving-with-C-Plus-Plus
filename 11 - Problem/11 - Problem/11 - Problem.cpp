
#include <iostream>
#include <cstdlib> // for randomness
#include <ctime>  // for randomness
using namespace std;

/*
 Problem #11

 Write a program to compare two matrices and check if the sum of the first matrix equals the sum of the second one.

 Example Output:

 Matrix1:
 06  03  06
 04  05  09
 03  04  04

 Matrix2:
 08  09  06
 06  08  06
 09  03  05

 No: matrices are NOT equal.

*/



int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}



void  FillMatrixWithRandomNumbers(int RandomNumbersMatrix1[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbersMatrix1[i][j] = GenerateRandomNumberInRange(1, 10); // our CORE indispensable utility.
        }
    }
}



void PrintElementsInMatrix(const int RandomNumbersMatrix[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            printf("%0*d     ", 2, RandomNumbersMatrix[i][j]);
        }

        cout << endl;
    }
}



int SumOfMatrix(const int RandomNumbersMatrix[3][3], short rows, short columns)
{
    int sum = 0;  // routine

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            sum += RandomNumbersMatrix[i][j];
        }
    }

    return sum;
}



bool AreSumsOfTheTwoMatricesEqual(const int RandomNumbersMatrix1[3][3], const int RandomNumbersMatrix2[3][3], short rows, short columns)
{
    return(SumOfMatrix(RandomNumbersMatrix1, 3, 3) == SumOfMatrix(RandomNumbersMatrix2, 3,3));
}



int main()
{
    srand((unsigned)time(NULL));  // to seed random numbers

    int RandomNumbersMatrix1[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix1, 3, 3);
    // RandomNumbersMatrix1 has been initialized (filled with random numbers).

    int RandomNumbersMatrix2[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix2, 3, 3);
    // RandomNumbersMatrix2 has been initialized (filled with random numbers). 


    cout << "Matrix1: " << endl;
    PrintElementsInMatrix(RandomNumbersMatrix1, 3, 3);


    cout << "\nMatrix2: " << endl;
    PrintElementsInMatrix(RandomNumbersMatrix2, 3, 3);



    if (AreSumsOfTheTwoMatricesEqual(RandomNumbersMatrix1, RandomNumbersMatrix2, 3, 3))
    {
        cout << "\nSums of the two matrices ARE EQUAL.\n";
    }
    else
    {
        cout << "\nSums are NOT equal.\n";
    }



    return 0;
}


