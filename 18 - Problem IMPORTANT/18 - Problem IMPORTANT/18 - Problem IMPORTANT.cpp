
#include <iostream>
#include <cstdlib> // for randomness
#include <ctime> // for randomness
#include <iomanip> // for setw(#) manipulator.
using namespace std;

/*
 Problem #18

 Write a program to print the intersected numbers in two given matrices.

 Matrix1:
 77     5     12
 22    20      1
 1      0      9


 Matrix2:
 5     80     90
 22    77      1
 10     8     33


 Intersected Numbers are:

 77     5     22     1     1

*/


// solution: Do NOT fall into the logical fallacy of wanting to store the common numbers ( between the 2 matrices)
//           into an array (one or 2D) . This none-sensical, as the number of common numbers is not known,
//           given the fact that an array (fixed-length data structure) requires specifiying the number of elements
//           before runtime.
//
// The only time a container, could be used, to store the common values is one that's dynamic
// such as a vector. As vectors, are dynamic (do not require specifying its size before trun time).

int GenerateRandomNumberInRange(int from, int to)
{
    return rand() % (to - from + 1) + from;
}




void FillMatrixWithRandomNumbers(int RandomNumbersMatrix1[3][3], short rows, short columns) // passing by ref. (Including & renders exception).
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            RandomNumbersMatrix1[i][j] = GenerateRandomNumberInRange(1, 100);  // our CORE indispensible randomness function.
        }
    }
}








void PrintElementsInMatrix(const int matrix[3][3], short rows, short columns)
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



bool IsNumberInMatrix(const int& number, const int RandomNumbersMatrix2[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (number == RandomNumbersMatrix2[i][j])
            {
                return true;
            }
        }
    }

    return false;
}


void PrintCommonNumbersInMatrices(const int RandomNumbersMatrix1[3][3], const int RandomNumbersMatrix2[3][3], short rows, short columns)
{
    short count = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (IsNumberInMatrix(RandomNumbersMatrix1[i][j], RandomNumbersMatrix2, 3, 3)) // the 1st argument is the actual number in Matrix1
            {                                                                            // the second argument is the entire Matrix2
                count++;
                cout << RandomNumbersMatrix1[i][j] << "  ";
            }
        }
    }


    if (count == 0)
    {
        cout << "No common numbers.";
    }

}




int main()
{
    srand((unsigned)time(NULL));   // to seed random numbers.

    int RandomNumbersMatrix1[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix1, 3, 3);
    // The 2D-array 'RandomNumbersMatrix1' is now initialized with random numbers.

    cout << "\nMatrix1: \n";
    PrintElementsInMatrix(RandomNumbersMatrix1, 3, 3);




    int RandomNumbersMatrix2[3][3];
    FillMatrixWithRandomNumbers(RandomNumbersMatrix2, 3, 3);
    // The 2D-array 'RandomNumbersMatrix2' is now initialized with random numbers.

    cout << "\nMatrix2: \n";
    PrintElementsInMatrix(RandomNumbersMatrix2, 3, 3);



    cout << "\nCommon numbers are: \n\n";
    PrintCommonNumbersInMatrices(RandomNumbersMatrix1, RandomNumbersMatrix2, 3, 3);
    cout << endl;

    return 0;

    //system("pause>0");
}


