
#include <bits/stdc++.h>
using namespace std;

int SumOfSubArray(int arr[], int k, int n)
{

    int cnt = 0; // Number of subarrays:

    for (int i = 0; i < n; i++)
    { // starting index i
        for (int j = i; j < n; j++)
        { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n = 4;
    int arr[] = {3, 1, 2, 4};
    int k = 6;
    cout<<SumOfSubArray(arr, k, n);

    return 0;
}
