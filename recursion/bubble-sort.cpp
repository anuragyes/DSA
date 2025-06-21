#include <iostream>
using namespace std;

void bubble(int arr[], int size)
{
    //   base case
    if (size == 1)

    {
        return;
    }
    for (int i = 0; i < size ; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // Swap arr[i] and arr[i + 1]
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubble(arr, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {56, 43, 55, 1, 23, 4};
    bubble(arr, 5);
    printArray(arr, 5);

    return 0;
}
