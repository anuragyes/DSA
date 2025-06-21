#include <iostream>
#include <vector>
using namespace std;

//  select the minimum value and just swap

//  step 1: select the min value  and just swap it

void selection(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < size ; j++)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {12, 43, 56, 3, 6, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection(arr, size);
    return 0;
}
