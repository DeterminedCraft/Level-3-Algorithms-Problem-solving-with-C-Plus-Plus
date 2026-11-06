
#include <iostream>
using namespace std;



/*
 Problem #15

 Write a program to count given number in matrix.

 Matrix1:
 9    1    12
 0    9     1
 0    9     9

 Enter the number to count in matrix?: 9

 Number 9 count in matrix is 4

*/



void  PrintElementsInMatrix(const int matrix[3][3], short rows, short columns)
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


int ReadIntegerNumber(const string& message)   // pass by const. ref.
{
    int number; // what's returned

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}



bool ValidarePositiveOrEqualZeroInteger(const int& number)  // pass by const. ref. since 'number' is ONLY used to be validated against the range.
{
    return (number >= 0);
}



int ReadPositiveOrEqualZeroInteger(const string& message) // pass by const. ref.
{
    int number; // what's returned.

    do
    {
        number = ReadIntegerNumber(message);  // 'number' is to be IMMEDIATELY validated against the range, in the condition.

    } while (!ValidarePositiveOrEqualZeroInteger(number));

    return number;

    // The above block is to be sequentially composed line by line.
    // at the end, implement all the functions.
}


short FrequenyOfNumberInMatrix(const int& number, const int matrix[3][3], int rows, int columns)
{
    short counter = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (matrix[i][j] == number)
            {
                counter++;
            }
        }
    }

    return counter;
}


int main()
{
    int matrix[3][3] = { { 9, 1, 12 },{ 0, 9, 1 },{ 0, 9, 9 } }; // initializing directly just how      int number = 5


    cout << "\nMatrix1: " << endl;
    PrintElementsInMatrix(matrix, 3, 3);


    int number = ReadPositiveOrEqualZeroInteger("\nEnter the number to count in matrix: "); // Range not included as its value is NOT intrinsic.
    /*        |
              |---> // to be added at the very end, after finishing typing the "return" keyword of the implementing function.  */

    cout << "Number " << number << " frequency in matrix is " << FrequenyOfNumberInMatrix(number, matrix, 3, 3) << endl;



    return 0;
}


