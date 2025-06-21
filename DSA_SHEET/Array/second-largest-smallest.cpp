#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*

 better approch  without sorting
 */

// void secondlargest(int arr[], int size)
// {
//     // first find the largest number
//     int max = arr[0];
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     int secondlarge = -1;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > secondlarge && arr[i] != max)
//         {
//             secondlarge = arr[i];
//         }
//     }
//     cout << "the maximum number of given array is :" << max << "and the second largest value is : " << secondlarge << endl;
// }

// int main()
// {
//     int arr[] = {1, 4, 7, 8, 34, 67};
//     int size = 6;
//     secondlargest(arr, 6);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

/*
void solve(int arr[], int n)
{
    int temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
*/

int remove(int nums[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {

        if (nums[start] == 0 && nums[end] != 0)
        {
            swap(nums[start], nums[end]);
        }
        else if (nums[start] != 0 || nums[end] != 0)
        {
            start++;
            end--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }
}
int main()
{

    int arr[] = {1, 0, 2, 0, 3};
    int n = 5;
    cout << remove(arr, n);
    return 0;
}