
#include <iostream>
#include <cstdlib>  // for randomness
#include <ctime>   // for randomness 
#include <iomanip> // for setw(#)

using namespace std;

/*
 Problem #19

 Write a program to print the Minimum and Maximum Numbers
 in a Matrix.

 Sample Output:

 Matrix1:
 77   5   12
 22  20    6
 14   3    9

 Minimum Number is: 3

 Max Number is: 77

*/



int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}



void FillMatrixWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns) // pass by ref. Including the & sign renders exception.
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 100); // our CORE utility for generating random numbers.
        }
    }
}



void PrintElementsInMatrix(const int RandomNumbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            cout << setw(5) << RandomNumbers[i][j] << "     ";
        }

        cout << endl;
    }
}



int CalculateMinNumber(const int RandomNumbers[3][3], short rows, short columns)
{
    int MinimumNumber = RandomNumbers[0][0];  // consider that the first element in the 2D array is the minimum number.

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (RandomNumbers[i][j] < MinimumNumber)
            {
                MinimumNumber = RandomNumbers[i][j];
            }
        }
    }

    return MinimumNumber;
}


int CalculateMaxNumber(const int RandomNumbers[3][3], short rows, short columns)
{
    int MaximumNumber = RandomNumbers[0][0]; // assume that the maximum number is the first element in the 2D array

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (RandomNumbers[i][j] > MaximumNumber)
            {
                MaximumNumber = RandomNumbers[i][j];
            }
        }
    }

    return MaximumNumber;
}

int main()
{
    srand((unsigned)time(NULL));  // for seeding random numbers.

    int RandomNumbers[3][3];
    FillMatrixWithRandomNumbers(RandomNumbers, 3, 3);
    // The 2D-Array (Matrix) has been filled with random numbers.

    cout << "Matrix1: \n";
    PrintElementsInMatrix(RandomNumbers, 3, 3);


    cout << "\nMinimum number is: " << CalculateMinNumber(RandomNumbers, 3, 3) << endl << endl;
    cout << "Maximum number is: " << CalculateMaxNumber(RandomNumbers, 3, 3) << endl;
    


    return 0;
}

