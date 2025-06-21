#include <iostream>
using namespace std;

/*candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.*/

/*

step 1. find the largest number in given arr;
step 2. extraCandies + arr[0] >=largest number return true;
*/

int main()
{
    // int arr[] = {2, 3, 5, 1, 3};
    // int size = 5;
    //  int extra = 3;
    // int arr[] = {12, 1, 12};
    // int extra = 10;
    // int size = 3;

     int arr[] = {12, 1, 12};
    int extra = 10;
    int size = 3;
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] + extra >= max)
        {
            cout << "true" << endl;
            
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}