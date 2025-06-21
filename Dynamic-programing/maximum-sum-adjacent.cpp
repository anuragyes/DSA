#include <iostream>
#include <vector>
using namespace std;

//  best solution forever
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int find(int *arr, int n)
    {
        if (n == 1)
            return arr[0];
        if (n == 0)
            return 0;

        vector<int> dp(n);

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // Fill the DP num say using the recurrence relation
        for (int i = 2; i < n; ++i)
        {
            dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
        }

        // The result is the maximum sum of non-adjacent elements
        return dp[n - 1];
    }
    int findMaxSum(int *arr, int n)
    {
        return find(arr, n);
    }
};

//  using tabluation

int find(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        int left = dp[i - 2] + arr[i];
        int right = dp[i - 1] + 0;
        dp[i] = max(left, right);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {10, 5, 6, 4, 5};

    return find(arr);

    return 0;
}

//  using dynamic programing

// int find(int index, vector<int> &arr, vector<int> &dp)
// {

//     if (index < 0)
//         return 0;
//     if (index == 0)
//         return arr[index];

//     if (dp[index] != -1)
//         return dp[index];

//     int left = arr[index] + find(index - 2, arr, dp);
//     int right = find(index - 1, arr, dp) + 0;

//     dp[index] = max(left, right);
//     return dp[index];
// }

// int main()
// {
//     vector<int> arr = {10, 5, 6, 4, 5};
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     return find(n - 1, arr, dp);

//     return 0;
// }

/*
//  uisng recusion
int find(int index, vector<int> &arr)
{

    if (index < 0)
        return 0;
    if (index == 0)
        return arr[index];
    int left = arr[index] + find(index - 2, arr);
    int right = find(index - 1, arr) + 0;
    return max(left, right);
}

int main()
{
    vector<int> arr = {10, 5, 6, 4, 5};
    int n = arr.size();
    int ans = find(n, arr);
    cout << ans;
    return 0;
}
*/