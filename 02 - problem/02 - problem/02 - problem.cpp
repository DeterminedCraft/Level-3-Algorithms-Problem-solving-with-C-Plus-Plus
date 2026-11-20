
#include <iostream>
#include <cstdlib>  // for randomness.
#include <iomanip>  // for setw(#) manipulator.
using namespace std;

/*

 Problem #2:

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


*/

int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;

    return RandomNumber;
}


void Fill2dArrayWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns)  // shorts are passed by value because their size in memory is so tiny.
{
    for (short i = 0; i < rows; i++) // i=0, i=1, i=2
    {
        for (short j = 0; j < columns; j++)  // j=0, j=1, j=2
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 100);
        }
    }
}


void Print2DArray(const int RandomNumbers[3][3], short rows, short columns)   // passing by constant reference. Including the & renders exception. // shorts passed by value as the memory space designated for shorts is tiny.
{
    for (short i = 0; i < rows; i++)   // i =0, i=1, i=2
    {
        for (short j = 0; j < columns; j++)
        {
            cout << setw(3) << RandomNumbers[i][j] << "     ";
        }

        cout << endl;
    }
}

int SumOfRow(const int RandomNumbers[3][3], short i)
{
    int sum = 0;
    
    for (short j = 0; j < 3; j++)
    {
        sum = sum + RandomNumbers[i][j];  // at the beginning (i =0)  RandomNumbers[0][0], [0][1], [0][2] so all iterations end, and sum is returned for this specific row.
                                          // then, sum is reset to 0
    }                                     // then for i = 1           RandomNumbers[1][0], [1][1], [1][2] so all iterations end, and sum is returned for this specific row.  and so on.

    return sum;
}

int SumOfRow(const int RandomNumbers[3][3], short i, short columns) // pass by const. ref. also, here the elements are not changed as we simply add them up to print them out to the screen .& alone implies mutation. 
{
    int sum = 0;

    for (short j = 0; j < columns; j++) // for i = 0, all the iterations will finish for RandomNumbers[0][0], [0][1], [0][2] and then the value of sum is returned
    {                                   // and then for i = 1, all the iterations will finish for RandomNumbers[1][0], [1][1], [1][2] and then the value of sum is returned
        sum += RandomNumbers[i][j];      // and so on.
    }

    return sum;
}

void PrintSumOfEachRowInMatrix(const int RandomNumbers[3][3], short rows, short columns) // passed by const. ref (only passing by reference implies mutation). Including the & sign renders exception.
{                                                                                        // rows & colums passed by value as space in memory designated for short is tiny.
    for (short i = 0; i < rows; i++)
    {
        cout << " Sum of row " << i + 1 << " = " << SumOfRow(RandomNumbers, i, columns) << endl; // 'columns' argument is for the columns inner for-loop that we chose to include inside SunOfRow() function instead of here to optimize our code.
    }                                                  // 'i' argument is for RandomNumbers[i][j] inside the inner for-loop that's inside the SumOfRow(),
}


int main()
{ 
    srand((unsigned)time(NULL)); // for seeding random numbers. Not including it here & ONLY 6 ONLY in main will generate random numbers for the 1st time ONLY and the next timeS the same random values persist.

    int RandomNumbers[3][3]; 
    Fill2dArrayWithRandomNumbers(RandomNumbers, 3, 3); // also passing the number of rows and columns in order to avoid hardcoding them in the conditionS of the nested for loopS. 
                                                       // the array argument is, by-default, always passed along with its address in memory. hence, in the implementation is always passed by ref without including the & sign.
    

   // the 2-D array has been initialized with random numbers.

    cout << "\n The following is a 3x3 random matrix:" << endl << endl;
    Print2DArray(RandomNumbers, 3,3); // the array is passed as an argument along with its address in memory. Hence, in the implementation its ALWAYS passed by ref. without including the & sign.


    cout << "\n The following are the sum of each row in the matrix:" << endl <<endl;
    PrintSumOfEachRowInMatrix(RandomNumbers, 3, 3); // the array is passed as an argument automatically along with its address in memory. Hence, the parameter is passed automatically by reference without including the & sign.
                                                          // the number of rows and columns are included as arguments ONLY to avoid hardcoding therm in the for-loop conditionS.  
    return 0;
}







/* The unoptimized way is:


 ****** Calling ****** :
 PrintSumOfEachRowIn2DArray(RandomNumbers, 3,3); // the array is passed as an argument along with its address in memory. Hence, in the implementation its ALWAYS passed by ref. without including the & sign. 
                                            // numbers of rows is passed as an argument ONLY TO AVOID hardcoding it in the condition of the rows for-loop.




 ****** Implementing ******:

 void PrintSumOfEachRowIn2DArray(const int RandomNumbers[3][3], short rows, short columns) // pass by constant ref. (inclufing & renders exception) as passing by ref. only implies mutation (not the case as the elements of the 2D arrays remain the same (we're only adding up the values in each row and printing them out to the screen)=
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0; // for each new row, re-set sum to 0
        for (int j = 0; j < columns; j++)
        {
            sum = sum + RandomNumbers[i][j]; // on the first i = 0,    RandomNumbers[0][0], RandomNumbers[0][1], RandomNumbers[0][2]  // so the first row is summed up.
        }

        cout << "Row " << i + 1 << " sum = " << sum << endl;
    }
}





*/