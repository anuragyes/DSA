
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*Union of Two Sorted Arrays
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.*/

/*Example 1:
Input:
n = 5,m = 5.
arr1[] = {1,2,3,4,5}
arr2[] = {2,3,4,4,5}
Output:
 {1,2,3,4,5}*/

// vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
// {
//     map<int, int> freq;
//     vector<int> Union;
//     for (int i = 0; i < n; i++)
//         freq[arr1[i]]++;
//     for (int i = 0; i < m; i++)
//         freq[arr2[i]]++;
//     for (auto &it : freq)
//         Union.push_back(it.first);
//     return Union;
// }

// int main()
// {
//     int n = 10, m = 7;
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int arr2[] = {2, 3, 4, 4, 5, 11, 12};
//     vector<int> Union = FindUnion(arr1, arr2, n, m);
//     cout << "Union of arr1 and arr2 is " << endl;
//     for (auto &val : Union)
//         cout << val << " ";
//     return 0;
// }

int main()
{
    vector<int> nums = {0, 0, 0, 0, 0};

    int maxcount = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxcount = max(count, maxcount);
        }
        else
            count = 0;
    }
    cout << maxcount << endl;
    return 0;
}