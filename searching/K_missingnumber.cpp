#include <iostream>
using namespace std;

// int missing_count(int arr[], int size, int count)
// {

//     int start = 0;
//     int end = size - 1;
//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         int missing = arr[mid] - (mid + 1);

//         if (missing < count)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
//     return count + end + 1;
// }

// int main()
// {
//     int arr[5] = {2, 3, 4, 7, 11};
//     int count = 5;
//     int size = 5;
//     cout << missing_count(arr, count, size);
//     return 0;
// }

int missing_count(int arr[], int size, int count)
{

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if ( arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
          else if(arr[start]>arr[mid]){
            end = mid-1;
          }else
           start = mid+1;
    }
}

int main()
{
    int arr[7] = {2, 4, 6, 8, 10, 8, 5};
    int count = 5;
    int size = 7;
    cout << missing_count(arr, count, size);
    return 0;
}