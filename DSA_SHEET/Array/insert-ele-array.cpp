#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 2, 3, 4, 6};
    int size = 6;
    int insertIdx = 2;
    int insertElement = 5;

    // Shift elements to make space for the new element
    for (int i = size - 1; i > insertIdx; --i)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the specified index
    arr[insertIdx] = insertElement;
    size++; // Increase the size of the array

    // Display the modified array
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
  

    return 0;
}
