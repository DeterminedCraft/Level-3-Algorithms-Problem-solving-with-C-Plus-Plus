
#include <iostream>
#include <cstdlib> // for randomness
#include <ctime> // for randomness
using namespace std;

 /****************************************
  Problem #13

  Write a program to check if the matrix is identity matrix or not.

  An identity matrix:
   1-  has a diagonal row consisting of 1's.
   2- the rest of the numbers in the matrix have to be 0's.
 

  Example Output:

  Matrix1:
  1   0   0
  0   1   0
  0   0   1

  YES: Matrix is identity.
 ****************************************/


int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}



void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short columns) // 2D array is passed automatically by ref. Including the & renders exception.
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            matrix[i][j] = GenerateRandomNumberInRange(0, 1);  // our CORE utility for generating random numbers.
        }
    }
}


void PrintElementsInMatrix(int matrix[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "     ";
        }

        cout << endl;
    }
}


bool IsItIdentityMatrix(const int matrix[3][3], short rows, short columns) // It's Identity Matrix when matrix[0][0] = 1, [1][1] = 1, [2][2] = 1     
{                                                                           // AND the rest are 0's    matrix[0][1] = 0, [0][2] = 0, [1][0] = 0,  [1][2] = 0, [2][0] = 0, [2][1] = 0
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }

            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}




int main()
{
    srand((unsigned)time(NULL)); // to seed random number.

    int matrix[3][3];
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    // The 2D array (matrix) is now initialized with numbers that are either 1's or 0's.

    cout << "\nMatrix1: " << "\n";
    PrintElementsInMatrix(matrix, 3, 3);


    // Instead of an if statement, here is an ternary operator (more optimizing):
    (IsItIdentityMatrix(matrix, 3, 3)) ? cout << "\nYes: Matrix is identity.\n" : cout << "\nNOT an identity matrix.\n";



     


    return 0;
}

