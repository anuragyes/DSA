#include <iostream>
using namespace std;

int binarySearch(int arr[], int size)
{
    int find = 2;
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == find)
        {
            return mid;
            break;
        }
        if (arr[mid] < find)
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    cout << binarySearch(arr, size);
}