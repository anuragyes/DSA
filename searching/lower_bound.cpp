#include <iostream>
using namespace std;

//  lower_bound means if you have given an array 1,2,3,6,8,9 , target = 3;  and n =7; smallest number find ?
//  find the value arr[index]>=7; answer will be 3  index 3

int lower_bound(int arr[], int size, int target)
{
    int start = 0;
    int ans = size;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
        {
            end = mid - 1;
            ans = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 6, 8, 9};
    int size = 5;

    cout << lower_bound(arr, size, 3);
}