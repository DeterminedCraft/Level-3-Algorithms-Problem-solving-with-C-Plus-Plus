

/*  Mental Model: CountNumberInMatrix()

    This function is a mental model on it's own.
    It should be used whenever it is possible & logical to do so.
    As this is conducive to capitalizing on the Divide & Conquer Stategy.






    int CountNumberInMatrix( const int number, const int matrix[3][4], short rows, short columns) // rows & columns pased by value as shorts occupy a little space in memory.
    {
      short count = 0:

      for (short i = 0; i < rows; i++)
      {
         for (short j = 0; j < columns; j++)
         {
           if( number == matrix[i][j])
           {
              count ++;
           }
         }
      }

      return count;

    }



    int main()
    {

       // some code

       CountNumberInMatrix( number, matrix, 3, 4):  // for example, 3 rows & 4 columns matrix.
                              |
                              |---> // the number whose count (frequency) in matrix is to be found out.
    }



    Furthermore,
    to know if the frequency/count of a number is more (or even less if needed) than the other values in matrix, then consider the following solution:

    short rows = 3;
    short columns = 3;

    short HalfTheNumberOfElementsInMatrix = floor((float)(rows * columns)) / 2;

    (CountNumberInMatrix(0, matrix, rows, columns) > HalfTheNumberOfElementsInMatrix) ? cout << "\nIt's a Sparce matrix.\n" : cout << "\nNOT a Sparce Matrix.\n";
                         |
                         |--> // or any other number.

     //the above line only:
     if the count of 0's is more than half of the numbers of the elements in the matrix.

 =================================================================================================================================================
 =================================================================================================================================================

    ALSO, Here is a pre-requisite for the bove:


 If both x and y are integer types (int, short, long, long long,
 and their unsigned versions), then integer division is performed.

 int x = 9;
 int y = 2;

 x / y                           // 4    (integer division)

 To perform normal division where a decimal value may appear in the
 final answer (floating-point division), at least one operand must be
 converted to a floating-point type (float or double).

 (float)x / y                    // 4.5
 float(x) / y                    // 4.5

 Modern C++ preferred form:

 static_cast<float>(x) / y       // 4.5

 To round the result up to the next whole number:

 ceil((float)x / y)              // 5.0

 Additional notes:

 - double can also be used instead of float, especially (but not always)
   when greater precision is desired.

 - More precisely, double stores significantly more precision than float.
   This becomes especially useful when calculations involve many significant
   digits or when minimizing rounding errors is important.

 Examples:

 (double)x / y                   // 4.5
 static_cast<double>(x) / y      // 4.5

 Casting methods:

 (float)x                        // C-style cast (older syntax)
 float(x)                        // Function-style cast
 static_cast<float>(x)           // Preferred modern C++ cast


*/





// An example on this metal model


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


short CountNumberInMatrix(const int& number, const int matrix[3][3], int rows, int columns)
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

    cout << "Number " << number << " frequency in matrix is " << CountNumberInMatrix(number, matrix, 3, 3) << endl;



    return 0;
}


