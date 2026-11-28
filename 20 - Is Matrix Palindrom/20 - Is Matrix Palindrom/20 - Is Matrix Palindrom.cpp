
#include <iostream>
#include <cstring>
#include <iomanip>  // for setw(#) manipulator.
using namespace std;

/*************************************************
 Problem #20

 Write a program to check if the matrix is
 Palindrome or not.

 Sample 1:

 Matrix1:
 1   2   1
 5   5   5
 7   3   7

 Yes: Matrix is Palindrome


 Sample 2:

 Matrix1:
 1   2   1
 5   5   5
 7   3   8

 No: Matrix is NOT Palindrome

 Note: A palindrome matrix is that where each row is a palindorme.
*************************************************/


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



bool IsMatrixPalindrome(const int numbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)  // i=0, i=1, i=2
    {
        for (short j = 0; j < columns / 2; j++) // j=0, j=1, j=2
        {
            if (numbers[i][j] != numbers[i][columns - 1 - j])
            {
                return false;
            }
        }
    }

    return true;
}




int main()
{
    int numbers[3][3] = { { 1, 2, 1 },{ 5, 5, 5 },{ 7, 3, 7 } };

    cout << "Matrix: \n";
    PrintElementsInMatrix(numbers, 3, 3);



    (IsMatrixPalindrome(numbers, 3, 3)) ? cout << "\nYES- it's a palidrome.\n" : cout << "\nNO- it's NOT a palindrome\n";


    return 0;
}


