
#include <iostream>
using namespace std;


/*
 Problem:

 Using Recursion, write a program to print Fibonacci Series of 10.

 +---+---+---+---+---+---+----+----+----+----+
 | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55 |
 +---+---+---+---+---+---+----+----+----+----+


 Solution:

 Hint: Fibonacci Series ALWAYS begins with two 1's.


    +---+ +---+ +---+
    | 1 | | 1 | | ? |
    +---+ +---+ +---+
      ^     ^
    Prev2  Prev1


    +---+ +---+ +---+
    | 1 | | 1 | | 2 |
    +---+ +---+ +---+
      ^     ^
    Prev2  Prev1





   +---+ +---+ +---+ +---+
   | 1 | | 1 | | 2 | | 3 |
   +---+ +---+ +---+ +---+
          ^     ^
        Prev2  Prev1




   +---+ +---+ +---+ +---+ +---+
   | 1 | | 1 | | 2 | | 3 | | 5 |
   +---+ +---+ +---+ +---+ +---+
                 ^     ^
               Prev2  Prev1





  +---+ +---+ +---+ +---+ +---+ +---+
  | 1 | | 1 | | 2 | | 3 | | 5 | | 8 |
  +---+ +---+ +---+ +---+ +---+ +---+
                      ^     ^
                    Prev2  Prev1





  +---+ +---+ +---+ +---+ +---+ +---+ +----+
  | 1 | | 1 | | 2 | | 3 | | 5 | | 8 | | 13 |
  +---+ +---+ +---+ +---+ +---+ +---+ +----+
                            ^     ^
                          Prev2  Prev1




  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+
  | 1 | | 1 | | 2 | | 3 | | 5 | | 8 | | 13 | | 21 |
  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+
                                  ^      ^
                                Prev2   Prev1






  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+ +----+
  | 1 | | 1 | | 2 | | 3 | | 5 | | 8 | | 13 | | 21 | | 34 |
  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+ +----+
                                        ^       ^
                                      Prev2   Prev1





  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+ +----+ +----+
  | 1 | | 1 | | 2 | | 3 | | 5 | | 8 | | 13 | | 21 | | 34 | | 55 |
  +---+ +---+ +---+ +---+ +---+ +---+ +----+ +----+ +----+ +----+
                                               ^       ^
                                             Prev2   Prev1


 And you stop at 55 because now we have a fibonacci series of 10.

*/

// based on Recursion Mental Model, recursion supercedes the for-loop. The risk of overstack overflow is always present.


void PrintFibonacciSeries(short NumberOfSeries, short Prev2, short Prev1, short sum)
{

    if (NumberOfSeries > 0)
    {

        sum = Prev1 + Prev2;
        cout << sum << "  ";

        Prev1 = Prev2;
        Prev2 = sum;
        PrintFibonacciSeries(NumberOfSeries - 1, Prev2, Prev1, sum); // has to be inside the if statement.Otherwise, the program goes on forever.
    }
    
}


int main()
{
    short Prev2 = 0;
    short Prev1 = 1;
    short sum = 0;

    PrintFibonacciSeries(10, Prev2, Prev1, sum); // Series of 10 elements.


    return 0;
}



// compare it with a normal, risk-free solution where for-loop is used instead of recursion:

/* 
void PrintFibonacciSeries(short NumberOfSeries)   // pass by value as short occupies little space in memory.
{
    short Prev1 = 0;
    short Prev2 = 1;
    short sum = 0;

    for (short i = 0; i < NumberOfSeries; i++)  // short i instead of int i ONLY because 'NumberOfSeries' in the condition is dcxlared as short.
    {
        sum = Prev1 + Prev2;

        cout << sum << "   ";

        Prev2 = Prev1;
        Prev1 = sum;
    }
}

int main()
{

    PrintFibonacciSeries(10);  // Fibonacci Series of 10 numbers



    return 0;
}
*/