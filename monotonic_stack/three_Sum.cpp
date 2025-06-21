#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool ThreeSum(vector<int> arr)
{
    int n = arr.size();

    int x = 13;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int find = x - arr[i];
        int start = i + 1;
        int end = n - 1;
        while (start <= end)
        {
            if (arr[start] + arr[end] == find)

                return 1;

            else if (arr[start] + arr[end] > find)

                end--;

            else

                start++;
        }
    }
    return 0;
}

int main()
{
    vector<int> numbers = {1, 4, 45, 6, 10, 8};

    cout << ThreeSum(numbers);
    return 0;
}