// Split an array into two equal Sum subarrays

//  keep in mind // If total sum is odd, we can't split into two equal parts

#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &arr)
{
    int totalSum = 0;
    for (int num : arr)
    {
        totalSum += num;
    }

    // If total sum is odd, we can't split into two equal parts
    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;
    int currentSum = 0;

    // Traverse through the array and check if we can find a split point
    for (int num : arr)
    {
        currentSum += num;
        if (currentSum == target)
        {
            return true;
        }
    }

    return false;
}
bool canSplit(vector<int> &arr)
{
    cout << find(arr);
}