#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// int firstoccurance(int arr[], int size, int element)
// {
//     int first = -1;
//     int start = 0;
//     int end = size - 1;
//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         if (arr[mid] == element)
//         {
//             first = mid;
//             end = mid - 1;
//         }
//         if (arr[mid] < element)
//         {
//             start = mid + 1;
//         }
//         else

//             end = mid - 1;
//     }
//     return first;
// }

// int lastoccurance(int arr[], int size, int element)
// {
//     int last = -1;
//     int start = 0;
//     int end = size - 1;
//     while (start <= end)
//     {
//         int mid = (start + end) / 2;
//         if (arr[mid] == element)
//         {
//             last = mid;
//             start = mid + 1;
//         }
//         else if (arr[mid] < element)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
//     return last;
// }

// int main()
// {
//     int arr[7] = {1, 2, 3, 4, 5, 5, 5};
//     cout << " the first occurance start at index ";
//     cout << firstoccurance(arr, 7, 5);
//     cout << endl;
//     cout << " the last occurance  at index ";
//     cout << lastoccurance(arr, 7, 5);
//     return 0;
// }

int main()
{
    // int arr[7] = {1, 2, 3, 4, 5, 6, 8};
    char arr[] = {'w', 'r', 't', 'y', 'a'};
    int size = 5;
    int start = 0;
    int end = size - 1;

    
    // while (start <= end)
    // {
    //     swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    // }

    // for (int i = 0; i < size; i++)
    // {

    //     cout << arr[i] << endl;
    // }
}
