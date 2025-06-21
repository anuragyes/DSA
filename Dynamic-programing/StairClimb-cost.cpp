#include <iostream>
#include <vector>
using namespace std;
//  dynamic programing

int findd(vector<int> &arr)
{
    int n = arr.size();
    if (n < 0)
        return 0;

    if (n == 0)
        return 0;
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = min(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        int one = arr[i] + dp[i - 1];
        int two = arr[i] + dp[i - 2];
        dp[i] = min(one, two);
    }
    return dp[n - 1];
}

// recursion

// int find(vector<int> &arr, int n)
// {
//     if (n < 0)
//         return 0;

//     if (n == 0)
//         return 0;

//     int onestep = find(arr, n - 1);
//     int twostep = find(arr, n - 2);
//     return min(onestep, twostep);
// }

// int main()
// {
//     vector<int> arr = {10, 15, 20};
//     int size = arr.size();
//     find(arr, size);

//     return 0;
// }
