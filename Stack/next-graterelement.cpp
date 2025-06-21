#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//  example  int arr[] = {7, 12, 1, 20}; the answer will be 12 because gretest element is 20 ande second 12

int findFloor(int arr[], int n, int x)
{
    // sort(arr, arr + n);
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // look on the right
        }
    }
    return ans;
 }

int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    int n = 7;
    int size = 8;
    
   
    return 0;
}