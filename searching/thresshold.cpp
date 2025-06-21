#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int finddivisior(vector<int> &arr, int div)
{
    int size = arr.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int thrhold(vector<int> &arr, int limit)
{

    int start = 1, end = *max_element(arr.begin(), arr.end());

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (finddivisior(arr, mid) <= limit)
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
    vector<int> arr = {1, 2, 5, 9};
    int limit = 6;

    cout << thrhold(arr, limit);
    return 0;
}