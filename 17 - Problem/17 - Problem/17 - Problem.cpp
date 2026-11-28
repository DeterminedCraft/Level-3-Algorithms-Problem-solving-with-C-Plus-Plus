

#include <iostream>
#include <iomanip>  // for setw(#) manipulator
using namespace std;

/*
Problem #17

 Write a program to check if a given number exists in matrix or not.

 Example:

 Matrix1:
 77      5      12
 22     20       1
 1       0       9

 Please Enter the number to look for in matrix: 77

 Yes it is there.

*/


void PrintElementsInMatrix(int matrix[3][3], short rows, short columns)
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


int ReadIntegerNumber(const string& message)
{
    int number; // what is returned.

    cout << message;
    cin >> number;
    cout << endl;

    return number;
}


bool ValidateIntegerInRange(const int& number, int min, int max)  // pass by const. ref. since 'number' is ONLY used for comparison against the range. // ranges ALWAYS passed by value.
{
    return (min <= number && number <= max);
}



int  ReadIntegerInRange(const string& message, int min, int max) // passing by const. ref.  // ranges ALWAYS passed by value.
{
    int number; // what's returned.

    short counter = 0;
    do
    {
        counter++;

        if (counter > 1)
        {
            cout << "Error. Number entered must be within the range of " << min << " & " << max << endl;
        }

        number = ReadIntegerNumber(message);  //'number' is to be IMMEDIATELY validated against the range, in the condition.
        
       
    } while (!ValidateIntegerInRange(number, min, max));

    return number;

    // The above block of code is composed line by line. & at the end, implement all the functions one by one.
}


bool IsNumberInArray(const int& number, const int matrix[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (number == matrix[i][j])
            {
                return true;
            }
        }
    }

    return false;
}


/* //// Not optimized. Check main() for explanation.
* 
short CountNumberInMatrix(int number, int matrix[3][3], short rows, short columns)
{
    short count = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (number == matrix[i][j])
            {
                count++;
            }
        }

    }

    return count;
}
*/


int main()
{
    int matrix[3][3] = {{77, 5, 12},{22, 20, 1},{1, 0, 9}};  // initializing the matrix directly.

    PrintElementsInMatrix(matrix, 3, 3);

    int min = -1000000;
    int max =  1000000;

    int number = ReadIntegerInRange("\nPlease Enter the number to look for in matrix: ", min, max);
/*        |
          | --->    // to be typed at the end, after finishing typing the "return" keyword in the implementing function.*/



    (IsNumberInArray(number, matrix, 3, 3)) ? cout << "\nYES: Number is in Matrix.\n" : cout << "\nNO: Number in NOT in the matrix.\n";


    // PATHETIC: Will work but not optimized. Because, we will have to iterate through every and each element of the array.
    //(CountNumberInMatrix(number, matrix, 3, 3) > 0) ? cout << "\nYes: Number is in Matrix.\n" : cout << "\nNO: Number is NOT in matrix.\n";

    return 0;
}


