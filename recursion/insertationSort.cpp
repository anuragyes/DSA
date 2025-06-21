#include <iostream>
using namespace std;

//  insertation sort by using recursion

void insertationSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[] = {12, 11, 3, 45, 67, 7};

    int size = sizeof(arr) / sizeof(arr[0]);
    insertationSort(arr, 6);
    return 0;
}