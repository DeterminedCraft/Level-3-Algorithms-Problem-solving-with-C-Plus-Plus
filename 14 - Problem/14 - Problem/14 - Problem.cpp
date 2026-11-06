
#include <iostream>
using namespace std;

/*
 Problem #14

 Write a program to check if the matrix is Scalar or not.

 Example:

 Matrix1:

 9  0  0
 0  9  0
 0  0  9

 Output:
 YES: Matrix is scalar.

 A scalar matrix must satisfy: All elements on the main diagonal ARE EQUAL. All elements outside the main diagonal are 0.
 
*/


bool IsMatrixScalar(int matrix[3][3], short rows, short columns)  // matrix[0][0] = same value , [1][1] = same value , [2][2] = same value   //AND the rest are all 0's : matrix[0][1]=0  ,[0][2]=0 ,[1][0] =0, [1][2]=0,[2][0]=0, [2][1]=0
{    
    int FirstDiagonalElement = matrix[0][0];
                                       
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
         
            if (i == j  &&  matrix[i][j] != FirstDiagonalElement)
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
    int matrix[3][3] = { { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 10 } }; // declaring a 2D array and initializing it directly.

    // More optimizing than the ordinary if..else statement.
     (IsMatrixScalar(matrix, 3, 3)) ? cout << "YES: Matrix is scalar. \n" : cout << "NO: Matrix is NOT scalar. \n";



    return 0;
}


