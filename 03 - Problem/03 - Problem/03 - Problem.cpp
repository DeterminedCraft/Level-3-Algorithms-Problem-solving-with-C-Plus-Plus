
#include <iostream>
#include <cstdlib> // for randomness.
#include <iomanip> // for setw(#) manipulator.
using namespace std;

/*

 Problem #3:

 Write a program to fill a 3x3 matrix with random numbers,
 then print each row sum.


 Example Output:


 The following is a 3x3 random matrix:

 53      43      6
 65      83      48
 64      30      36

 The following are the sum of each row in the matrix:

 Row 1 Sum = 102
 Row 2 Sum = 196
 Row 3 Sum = 130

 // Note: But this time, instead of printing the sums directly onto the screen:
          FIRST, save them into an array (fixed-length data structure), 
          AND THEN, start printing them out to the screen.

          (Proper way of thinking as this array could be used for something else later, other than just merely printing)

*/


int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from; // causing negative number -1 to appear.
    return RandomNumber;
}


void Fill2dArrayWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++) // i=0, i=1, i=2
    {
        for (short j = 0; j < columns; j++) // j=0, j=1, j=2
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 100);
        }
    }
}

void PrintNumbersIn2dArray(const int RandomNumbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            cout << setw(3) << RandomNumbers[i][j] << "     ";
        }

        cout << endl;
    }
}


int CalculateSumOfEachRow(short columns, const int RandomNumbers[3][3], short i)
{
    int sum = 0; // routine

    for (short j = 0; j < columns; j++)  // j=0, j=1, j=2
    {
        sum += RandomNumbers[i][j]; // for i = 0 (in outer loop),  we'll have RandomNumbers[0][0], [0][1], [0][2] and then sum of the first row is returned.
    }                                   // then sum is re-set to 0
                                    // for i = 1 (in outer loop),  we'll have RandomNumbers[1][0], [1][1], [1][2] and then sum of the first row is returned
    return sum;                        // then sum is re-set to 0   and so on . 
}


void FillingArrayWithSumsOfRows(int SumsOfRows[3], int RandomNumbers[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)  // i=0,  i=1, i=2
    {
        SumsOfRows[i] = CalculateSumOfEachRow(columns, RandomNumbers, i);
    }
}


void PrintSumsOfRowsInArray(const int SumsOfRows[3], short NumberOfElements)
{
    for (int i = 0; i < NumberOfElements; i++)
    {
        cout << "Row " << i + 1 << " sum= " << SumsOfRows[i] << endl;
    }
}

int main()
{

    srand((unsigned)time(NULL));   // to seed random numbers.

    int RandomNumbers[3][3];
    Fill2dArrayWithRandomNumbers(RandomNumbers, 3, 3); // number of rows and columns passed as arguments to simply and only avoid hardcoding the conditionS in both the outer & inner for-loops. THAT'S ALL.

    // The array 'RandomNumbers' is now initialized with random numbers.

    cout << "The following is a 3x3 random matrix: \n";
    PrintNumbersIn2dArray(RandomNumbers, 3, 3); // again -number of rows & columns passed as arguments for ONLY avoiding hardcoding the condition in both the outer & inner for-loopS.

    int SumsOfRows[3];
    FillingArrayWithSumsOfRows(SumsOfRows, RandomNumbers, 3, 3); // again, including number of rows and colums ONLY & ONLY toa void hardcoding the conditionS in both the outer & inner for loopS. And nothing more.

    // The array 'SumsOfRows' is now initialized with numbers, each representing sums of each row in the 2D array.

    // Now, we'll interate through each single element of the array 'SumsOfRows', printing every single one out in the process.
    cout << "\nThe following are the sum of each row in the matrix: " << "\n";
    PrintSumsOfRowsInArray(SumsOfRows, 3); // '3' (number of elements in the array) passed as argument ONLY & ONLY to avoid hardcoding it in the condition of the for-loop

    return 0;
}

