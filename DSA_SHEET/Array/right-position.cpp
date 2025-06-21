

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*iven a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4*/

void rightposition(int nums[], int size, int target)
{

    int index = 0;

    while (index < size && nums[index] < target)
    {
        index++;
    }

    cout << index;
}

int main()

{

    int arr[] = {1, 2, 5, 6};
    int size = 3;
    int target = 3;
    rightposition(size, arr, target);

    return 0;
}