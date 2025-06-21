#include <iostream>
using namespace std;

int searchelemnt(int arr[], int n)
{
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    if (n == 1)
    {
        return arr[0];
    }
    int start = 1;
    int end = n - 2;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid % 2 == 1 && arr[mid] != arr[mid + 1] || mid % 2 == 0 && arr[mid] != arr[mid + 1])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
     return  -1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 8};
    int n = 9;
    cout << searchelemnt(arr, n);
    return 0;
}