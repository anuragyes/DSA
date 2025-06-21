#include <iostream>
#include <vector>
using namespace std;

//  brute force approch
void prefixSum(int arr[], int n)
{
    vector<int> ans(n);

    ans[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + arr[i];
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int arr[] = {6, 4, 5, -1, 2, 8};
    int size = 6;
    prefixSum(arr, size);

    return 0;
}