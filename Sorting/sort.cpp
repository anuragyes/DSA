#include <iostream>
#include <map>
using namespace std;

/*Example 1 of 0's 1's 2's

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]*/

// int main()
// {
//     int arr[] = {2, 0, 2, 1, 1, 0};
//     int size = 6;

//     int start = 0;
//     int mid = 0;
//     int end = size - 1;
//     while (mid <= end)
//     {
//         if (arr[mid] == 0)
//         {
//             swap(arr[mid], arr[start]);
//             start++;
//             mid++;
//         }
//         else if (arr[mid] == 1)
//         {
//             mid++;
//         }
//         else
//         {
//             swap(arr[mid], arr[end]);
//             end--;
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << endl;
//     }
//     return 0;
// }

// int main()
// {
//     // int arr[] = {0, 3, 0, 4, 5, 0};
//     int arr1[] = {2, 3, 4, 1};
//     int arr2[] = {6, 7, 8, 9, 3};
//     int n = 4;
//     int m = 5;
//     int ans[n + m];

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; i < m; j++)
//         {
//             if (arr1[i] != arr2[j])
//             {
//                 ans[n + m] = arr1[i], arr2[j];
//             }
//         }
//     }
//     for (int i = 0; i < n + m; i++)
//     {
//         cout << ans[i] << endl;
//     }
// }
