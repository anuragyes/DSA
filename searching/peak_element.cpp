#include <iostream>
#include <vector>
using namespace std;

//  find the peak element peek element said to be when  the element greater than both of its neighbors.

int peak(vector<int> &arr)
{
    int ans = 0;
    int start = 0;
    int end = arr.size() - 1;

    if (arr.size() == 1)
    {
        return 0;
    }
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
        {
            return mid;
        }

        if (arr[mid - 1] < arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << peak(arr);
    return 0;
}