
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Find First and Last Position of Element in Sorted Array*/

/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].*/

/*Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/

int main()
{
    vector<int> arr = {5, 7, 9, 8, 8, 8, 10};
    int key = 8;
    int size = arr.size();
    int start = -1;
    int end = -1;
    // sort(arr.begin(), arr.end());
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] == key)
    //     {
    //         start = i;
    //         break;
    //     }
    // }
    // for (int i = size - 1; i >= 0; i--)
    // {
    //     if (arr[i] == key)
    //     {
    //         end = i;
    //         break;
    //     }
    // }

    cout << " staring position is : " << start << " ending position is : " << end << endl;
}
