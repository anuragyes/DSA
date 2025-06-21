#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findDays(vector<int> &arr, int capacity)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + load > capacity)
        {
            days += 1;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return days;
}

int leastwieght(vector<int> &arr, int d)
{
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int numberdays = findDays(arr, mid);
        if (numberdays <= d)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << leastwieght(arr, 5);
    return 0;
}