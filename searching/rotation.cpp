

#include <bits/stdc++.h>
using namespace std;
//  brute force  approch

int findKRotation(vector<int> &arr)
{

    int ans = INT_MAX;
    int index = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
            index = i;
                }
    }
    return index;
}

//  optimal approch  binary search
// int findKRotation(vector<int> &arr)
// {
//     int low = 0, high = arr.size() - 1;
//     int ans = INT_MAX;

//     int index = -1;
//     while (low <= high)
//     {

//         int mid = (low + high) / 2;
//         //   let us assume we dont have a rotated sorted  array
//         if (arr[low] <= arr[high])
//         {
//             if (arr[low] < ans)
//             {
//                 index = low;
//                 ans = arr[low];
//             }
//             break;
//         }
//         //  let us assume we have rotated sorted array

//         // if left part is sorted:
//         if (arr[low] <= arr[mid])
//         {
//             // keep the minimum:
//             if (arr[low] < ans)
//             {
//                 index = low;
//                 ans = arr[low];
//             }

//             // Eliminate left half:
//             low = mid + 1;
//         }
//         else
//         { // if right part is sorted:

//             // keep the minimum:
//             if (arr[mid] < ans)
//             {
//                 index = mid;
//                 ans = arr[mid];
//             }

//             // Eliminate right half:
//             high = mid - 1;
//         }
//     }
//     return index;
// }

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times" << endl;
    return 0;
}
