
#include <iostream>
using namespace std;

// NEEDS FINALIZATION/ DECISSIVENESS:
// 
// Examine the following:
// There are 2 different final conclusions/ point of views:


/*


 When iterating backwards through a string, be careful when using size_t.

 text.length() returns a size_t data type.

 size_t is an unsigned integer type, which means it cannot store negative values.

 This becomes important in loops such as:

 for (size_t i = length - 1; i >= 0; i--)

 because eventually:

 i = 0

 and then:

 i--

 would mathematically produce:

 -1

 However, size_t cannot store -1.

 Instead, the value wraps around to a very large positive number
 (for example 18446744073709551615 on many 64-bit systems).

 As a result:

 i >= 0

 remains true forever, causing the loop to continue and potentially
 access invalid indexes.

 The problem is NOT that length() returns size_t.

 The problem is using backward-loop logic that assumes the index
 can become negative.

 Therefore, the preferred solution is usually to keep the value as
 size_t and write the loop differently, for example:

 for (size_t i = length; i > 0; i--)
 {
     // access element using i - 1
 }

 Bottom line:

short length = text.length();

 // always store the length() value into a short variable.
 // We should be ok with the compiler's implicit conversion
 // from size_t to short even though size_t has a wider value range.
 // Reason is, because generally speaking, .length() will always
 // return a small value anyway, so no data will be lost during
 // the implicit conversion from size_t to short.


 // NONETHELESS, the other point fo view is:

  Bottom line:

 Do not convert length() to short simply to avoid this issue.

 text.length() returns size_t for a reason.

 The preferred solution is to store the return value in a size_t
 variable and write the loop condition correctly for an unsigned
 type.

*/


int main()
{
    

    return 0;
}


