
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.*/

/*Input: nums = [1,2,2,4]
Output: [2,3]*/

int main()
{
    vector<int> arr = {1, 2, 2, 4, 5};

    int result = 0;
    int secondresult = 0;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == arr[i + 1])
        {
            result = arr[i + 1];
            secondresult = arr[i + 1] + 1;
        }
          
    }
    cout << " duplicate number is :" << result << "and the missing number is to the given array is  : "  << secondresult << endl;
   

    return 0;
}