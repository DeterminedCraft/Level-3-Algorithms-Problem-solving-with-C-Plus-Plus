
#include <iostream>
#include <iomanip>
using namespace std;

/*
 Problem #06

 Write a program to fill a 3x3 matrix with ordered numbers.


 Output:


 The following is a 3x3 ordered matrix:
 1  2  3
 4  5  6
 7  8  9

*/


void FillArrayWithOrderedNumbers(int OrderedNumbers[3][3], short rows, short columns) // passing by constant reference. Including the & renders exception.
{
    short counter = 0;

    for (short i = 0; i < rows; i++)  // i=0, i=1, i=2
    {
        for (short j = 0; j < columns; j++)   // j=0, j=1, j=2
        {
            counter++;  // counter = counter + 1
            OrderedNumbers[i][j] = counter;
 
        }
    }
}

void PrintElementsInArray(const int OrderedNumbers[3][3], short rows, short columns) // passing by const. ref. Including & renders exception.
{
    for (short i = 0; i < rows; i++)  // i=0, i=1, i=2
    { 
        for (short j = 0; j < columns; j++) // j=0, j=1, j=2
        {
            cout << OrderedNumbers[i][j] << " ";  // enough for this specific problem even though the commented line below works the best for scalability.
           // cout << setw(3) << OrderedNumbers[i][j] << "     "; // this is more of a scalable solution, should the ordered numbers change so that each have 4 digits.
        }

        cout << endl;
    }
}


int main()
{
    int OrderedNumbers[3][3];
    FillArrayWithOrderedNumbers(OrderedNumbers, 3, 3); // rows and columns are passed as arguments, ONLY & ONLY to prevent hardcoding the conditions of the inner and out for-loops.


    // The matrix (multi-dimensional array) has now been initialized (filled with ordered numbers).

    cout << "\nThe following is a 3x3 ordered matrix: " << endl;
    PrintElementsInArray(OrderedNumbers, 3,3);  // rows and columns are passed as arguments, ONLY & ONLY to prevent hardcoding the conditions of the inner and out for-loops.

    return 0;
}


