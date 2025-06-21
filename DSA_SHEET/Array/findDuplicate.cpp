
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/

/*Input: nums = [1,3,4,2,2]
Output: 2*/

int main()
{
    vector<int> arr = {1, 5, 3, 4, 8, 2, 8};

    int size = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            continue;
        }
        else
        {
            cout << arr[i] << endl;
        }
    }

    return 0;
}