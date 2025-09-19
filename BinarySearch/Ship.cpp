#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr, int mid, int days)
{
    int sum = 0;
    int count = 1; // at least one partition
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            count++;
            sum = arr[i]; // start new partition with current element
            if (count > days)
                return false;
        }
    }
    return true;
}

int Solution::solve(vector<int> &arr, int days)
{
    int start = *max_element(arr.begin(), arr.end()); // min capacity
    int end = accumulate(arr.begin(), arr.end(), 0);  // max capacity
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (ispossible(arr, mid, days))
        {
            ans = mid; // valid, try smaller
            end = mid - 1;
        }
        else
        {
            start = mid + 1; // not valid, need larger capacity
        }
    }

    return ans;
}

