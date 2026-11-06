
#include <iostream>
#include <cstdlib> // for randomness
#include <ctime>  // for randomness
using namespace std;

/*
 Problem #10

 Write a program to fill two 3x3 matrices with random numbers,
 then write a function to sum all numbers in each matrix and
 print the result.

 Example Output:

 Matrix1:
 04   08   14
 03   10   07
 08   08   10

 Sum of Matrix1 is: 64

*/


int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}


void FillMatrixWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns)  // passing by ref. for the 2D array (Including & renders exception)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 100); // our CORE indispensable utility.
        }
    }
}


void printElementsInMatrix(int RandomNumbers[3][3], short rows, short columns)
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



int CalculateSumOfMatrix(const int RandomNumbers[3][3], short rows, short columns)
{
    int sum = 0; // routine

    for (short i = 0; i < rows; i++)  // i=0, i=1, i=2
    {
        for (short j = 0; j < columns; j++)  // j=0, j=1, j=2
        {
            sum += RandomNumbers[i][j];
        }
    }

    return sum;
}


int main()
{
    srand((unsigned)time(NULL)); // to seed random numbers.
    
    int RandomNumbers[3][3];
    FillMatrixWithRandomNumbers(RandomNumbers, 3, 3);

    // The matrix (2D array) has been filled (initialized) with random numbers.

    
    cout << "Matrix1:" << "\n";
    printElementsInMatrix(RandomNumbers, 3, 3);
   

    cout << "\nSum of Matrix is: " << CalculateSumOfMatrix(RandomNumbers, 3, 3) << endl;

    return 0;
}


