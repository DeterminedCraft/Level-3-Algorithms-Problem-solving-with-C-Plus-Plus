
#include <iostream>
#include <iomanip> // for setw(#)   (set width manipulator)
using namespace std;


/*
 Problem #16

 Write a program to check if the matrix is Sparse or not.
 A sparce matrix contains more zeros than none-zero values.


 Example 1:

 Matrix1:
 10    0    12
 20   15     1
 0     0     9

 No: It's NOT Sparse



 Example 2:

 Matrix1:
 0     0    12
 0     0     1
 0     0     9

 Yes: It is Sparse

*/

void  PrintElementsInMatrix(const int matrix[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            cout << setw(5) << matrix[i][j] << "     ";
        }

        cout << endl;
    }
}

bool IsMatrixSparce(const int matrix[3][3], int rows, int columns)
{
    short ZerosCount = 0;
    short NonZerosCount = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
            {
                ZerosCount++;
            }

            else
            {
                NonZerosCount++;
            }
        }
    }

    if (ZerosCount > NonZerosCount)
    {
        return true;
    }

    return false;
}



int main()
{
    int matrix[3][3] = { { 0, 0, 10000 },{ 0, 0, 1 },{ 0, 0, 84933 } };

    cout << "\Matrix: \n";
    PrintElementsInMatrix(matrix, 3, 3);

    (IsMatrixSparce(matrix, 3, 3)) ? cout << "\nYES: Matrix is sparce " << endl : cout << "\nNO: Matrix is NOT sparce." << endl;

    return 0;
}


