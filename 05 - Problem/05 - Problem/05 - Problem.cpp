
#include <iostream>
#include <cstdlib>  // for randomness
#include <iomanip> // for setw(#) manipulator
using namespace std;

/*
 Problem #05

 Write a program to fill a 3x3 matrix with random numbers,
 then sum each column and place the sums inside an array (fixed-length data structure) and print them.

 Example Output:

 The following is a 3x3 random matrix:

   5   1  87
  46  12   2
  87   2  68

 The following are the sums of each column in the matrix:

 Col 1 Sum = 138
 Col 2 Sum = 15
 Col 3 Sum = 157

 so, instead of printing out the sums directly:
     FIRST, add all the column sums inside an array (fixed-length) data strucure
     ,AND THEN iterate through this array printing out the sums one by one (The most proper & scalable approach)
*/


int GenerateRandomNumberInRange(int from, int to)
{
    int RandomNumber = rand() % (to - from + 1) + from;
    return RandomNumber;
}



void Fill2DarrayWithRandomNumbers(int RandomNumbers[3][3], short rows, short columns) // arrays are automatically passed by ref. Including & renders exception.  // both passed by value as shorts occupy little space in memory.
{
    for (short i = 0; i < rows; i++)  // i=0, i=1, i=2
    {
        for (short j = 0; j < columns; j++) // j=0, j=1, j=2
        {
            RandomNumbers[i][j] = GenerateRandomNumberInRange(1, 100);
        }
    }
}


void PrintElementsIn2dArray(const int RandomNumbers[3][3], short rows, short columns) // passing by constant reference. // both passed by value as shorts occupy little space in memory.
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


int CalculateSumOfEachColumn(short rows, const int RandomNumbers[3][3], short j)
{
    int sum = 0; //routine

    for (short i = 0; i < rows; i++) // ACTING AS THE INNER LOOP
    {
        sum += RandomNumbers[i][j];    //   on j = 0 : RandomNumbers[0][0], [1][0], [2][0]
    }                                  //   on j = 1 : RandomNumbers[0][1], [1][1], [2][1]  
                                       //   on j = 2 : RandomNumbers[0][2], [1][2], [2][2]
    return sum;
}



void FillArrayWithSumsOfColumns(int SumsOfColumns[3], const int RandomNumbers[3][3], short rows, short columns) // the one dimensional array HAS to be passsed by ref so its values are stored ion the array that is in main
{                                                                                                         // and the 2D-array is passed by const. ref.
    for (short j = 0; j < columns; j++) // ACTING AS THE OUTER LOOP
    {
        SumsOfColumns[j] = CalculateSumOfEachColumn(rows, RandomNumbers, j);
    }
}



void  PrintTheStoredSumsOfColumns(const int SumsOfColumns[3], short NumberOfElements) // pass by const. ref. (arrays are by default, whether you like it or not, are passed by ref. Including the & sign renders exception).
{
    for (int i = 0; i < NumberOfElements; i++)
    {
        cout << "Column " << i + 1 << " sum = " << SumsOfColumns[i] << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));  // to start seeding random numbers. // if you mess it up on this line, then radom nubers will only be generated once; making the program use the exact same values from that point forward.
    
    int RandomNumbers[3][3];
    Fill2DarrayWithRandomNumbers(RandomNumbers, 3, 3); // numbers of rows & columns added ONLY & ONLY to avoid hardcoding them in the conditionS ôf the nested for-loops (noth inner & outer).

    // The 2D array has been filled with random numbers.

    cout << "\nThe following is a 3x3 random matrix:" << "\n";
    PrintElementsIn2dArray(RandomNumbers, 3, 3); // again- the number of rows and columns are passed as arguments for ONLY & ONLY avoiding to hardcode them in both of the conditions of the outer and inner for loops.



    // so the proper way of thinking is to declare an array and fill it with the sum of each column.
    // and once the array would've been filled, then use a for-loop to go through each and every element, in the array, printing it out in the process.

    int SumsOfColumns[3];
    FillArrayWithSumsOfColumns(SumsOfColumns, RandomNumbers, 3, 3);

    // The array ' SumsOfColumns' is now initialized with values each representing the sum of each column in the 2D-array.

    // Now to print out the elements in the single dimensional array ( = each element represents the sum of each column in the 2D array)
    cout << "\nThe following are the sums of each column in the matrix :" << endl;
    PrintTheStoredSumsOfColumns(SumsOfColumns, 3); // from now and on, even for a 1-d array, pass the number of elements as an argument as this is ONLY & ONLY to avoid hardcoding it in the condition of the for-loop)


    return 0;
}


