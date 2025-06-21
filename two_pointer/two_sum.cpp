#include <iostream>
using namespace std;

//  brute force approch
int twoSum(int arr[], int size)
{
    int target = 10;

    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        if (arr[start] + arr[end] == target)
        {
            return 1;
        }
        else if (arr[start] + arr[end] > target)
        {
            end--;
        }
        start++;
    }
    return 0;
}

int main()
{
    int arr[] = {3, 4, 5, 6, 9};
    int size = 4;
    cout << twoSum(arr, size);
    return 0;
}