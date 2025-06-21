#include <iostream>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    // sort the given array

    // for (int i = 0; i < size - 1; ++i)
    // {
    //     for (int j = 0; j < size - i - 1; ++j)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             // Swap arr[j] and arr[j+1]
    //             int temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //         }
    //     }

    // }

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int ans = n - arr[mid];

        if (arr[mid] == ans)
        {
            return 1;
        }
        else if (arr[mid] <= ans)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {20, 50, 70, 80, 90};
    int size = 5;
    int n = 45;
    cout << findPair(arr, size, n);
    return 0;
}