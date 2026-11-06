
#include <iostream>
#include <cstdlib>  // for randomness.
using namespace std;

/*
 Problem #09

 Write a program to fill a 3x3 matrix with random numbers,
 print it, then print the middle row and middle column.

 Example Output:

 Matrix1:
 01   10   07
 10   03   02
 06   03   09

 Middle Row of Matrix1 is:
 10   03   02

 Middle Col of Matrix1 is:
 10   03   03

*/

int GenerateRandomNumberInRange(int from, int to)  // our indispensable CORE random number generator utility
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}


void FillMatrixWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns)  // passing by ref. (including & renders exception) in order to initialize the matrix inside main()
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 10);
        }
    }
}


void PrintElementsInMatrix(const int RandomNumbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            printf("%0*d     ", 2, RandomNumbers[i][j]);
        }

        cout << endl;
    }
}


void PrintMiddleRow(const int RandomNumbers[3][3], short rows, short columns)  // RandomNumbers[1][0]   [1][1]   [1][2]  // j varies (so for-loop for it)     //i is fixed. For middle row, i = rows/2 (integer division)
{
    short i = rows / 2; // integer division

    for (short j = 0; j < columns; j++)
    {
        printf("%0*d     ", 2, RandomNumbers[i][j]);
    }

    cout << endl;
    
}


void PrintMiddleColumn(const int RandomNumbers[3][3], short rows, short columns) // RandomNumbers[0][1]   [1][1]    [2][1]  // i varies (so for-loop for it)   // j is fixed. For middle column, j = columns / 2 (integer division).
{
    short j = columns / 2;  // integer division

    for (short i = 0; i < rows; i++)
    {
        printf("%0*d     ", 2, RandomNumbers[i][j]);
    }
    
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.

    int RandomNumbers[3][3];
    FillMatrixWithRandomNumbers(RandomNumbers, 3, 3);

    // The 2d array (matrix) has been initialized (filled with random numbers)


    cout << "Matrix 1: " << "\n";
    PrintElementsInMatrix(RandomNumbers, 3, 3);


    cout << "\nMiddle Row of Matrix1 is: " << endl;   
    PrintMiddleRow(RandomNumbers, 3, 3);

    cout << "\nMiddle Column of Matrix1: " << endl;
    PrintMiddleColumn(RandomNumbers, 3, 3);




    return 0;
}


