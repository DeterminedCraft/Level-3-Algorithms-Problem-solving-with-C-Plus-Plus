
#include <iostream>
using namespace std;

/****************************************
 Problem #12

 Write a program to compare two matrices
 and check if they are identical or not.

 Example Output:

 Matrix1:
 06  03  06
 04  05  09
 03  04  04

 Matrix2:
 08  09  06
 06  08  06
 09  03  05

 No: matrices are NOT identical.
****************************************/




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



void PrintElementsInMatrix(int RandomNumbersMatrix[3][3], short rows, short columns)
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


bool AreTheTwoMatricesIdentical(const int RandomNumbersMatrix1[3][3], const int RandomNumbersMatrix2[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (RandomNumbersMatrix1[i][j] != RandomNumbersMatrix2[i][j])
            {
                return false;
            }
        }
    }

    return true;
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


    /*      // Below is perfectly fine. Yet, a ternary operator is more optimizing.

    if (AreTheTwoMatricesIdentical(RandomNumbersMatrix1, RandomNumbersMatrix2, 3, 3))
    {
        cout << "\nThe two matrices ARE IDENTICAL. " << "\n";
    }
    else
    {
        cout << "\nThe 2 matrices are NOT identical" << "\n";
    }
    // this if statement block is to be constructed sequentially. & at the end, implement the function(s).


    */



    // more optimized:
    (AreTheTwoMatricesIdentical(RandomNumbersMatrix1, RandomNumbersMatrix2, 3, 3)) ? cout << "\nThe two matrices ARE IDENTICAL. " << "\n": cout << "\nThe 2 matrices are NOT identical" << "\n";

    return 0;
}



