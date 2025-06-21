
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// rotate the first element and set the last

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int k = 3;

    int temp[] = {1, 2, 3};
    //  shifting
    for (int i = k; i < size; i++)
    {
        arr[i - k] = arr[i];
    }
    int j = 0;
    for (int i = size - k; i < size; i++)
    {
        arr[i] = temp[j];
        j++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
