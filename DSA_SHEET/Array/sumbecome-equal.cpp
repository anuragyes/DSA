

/*Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int findSwapValues(int a[], int n, int b[], int m)
{
    // Your code goes here

    sort(a, a + n);
    sort(b, b + m);

    int sumA = 0;
    for (int i = 0; i < n; i++)
        sumA += a[i];

    int sumB = 0;
    for (int i = 0; i < m; i++)
        sumB += b[i];

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (sumA - a[i] + b[j] == sumB - b[j] + a[i])
            return 1;
        else if (sumA - a[i] + b[j] > sumB - b[j] + a[i])
            i++;
        else
            j++;
    }
    return -1;
}

int main()
{
    int arr1[] = {4, 1, 2, 1, 1, 2};
    int n = 6;
    int arr2[] = {3, 6, 3, 3};
    int m = 4;
    cout << findSwapValues(arr1, n, arr2, m);
}