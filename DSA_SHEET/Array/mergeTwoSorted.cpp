#include <iostream>
using namespace std;

/*xample 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 */

void merge(int arr1[], int n, int arr2[], int m)
{
    int totalsize = n + m;
    int merged[totalsize];
    for (int i = 0; i < n; i++)
    {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        merged[n + i] = arr2[i];
    }

    // Print the merged array
    cout << "Merged Array: ";
    for (int i = 0; i < totalsize; ++i)
    {
        cout << merged[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 0, 0, 0, 0};
    int n = 4;

    int arr2[] = {5, 6};
    int m = 2;
    merge(arr1, n, arr2, m);

    return 0;
}