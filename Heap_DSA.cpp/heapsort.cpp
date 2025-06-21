#include <iostream>
#include <vector>
using namespace std;
//  there are following step to solve the given  name called heap sort
//  step first:  make a max heap using given array heapifiy
// second step : make a loop and swap the element first element to last element

#include <iostream>
using namespace std;

//  setep second make heapify function

// void heapify(int arr[], int index, int size)
// {
//     int largest = index;
//     int left = 2 * index + 1;
//     int right = 2 * index + 2;

//     if (left < size && arr[left] > arr[largest])
//     {
//         largest = left;
//     }
//     if (right < size && arr[right] > arr[largest])
//     {
//         largest = right;
//     }
//     if (largest != index)
//     {
//         swap(arr[largest], arr[index]);
//         heapify(arr, largest, size);
//     }
// }

// //    build heap first step

// void build(int arr[], int size)
// {
//     for (int i = size - 1 / 2; i >= 0; i--)
//     {
//         heapify(arr, i, size);
//     }
// }

// //  second step  sort given max heap

// void heapSort(int arr[], int size)
// {
//     for (int i = size - 1; i > 0; i--)
//     {
//         swap(arr[i], arr[0]);  // swap last element from first element 
//         heapify(arr, 0, i);
//     }
// }
void heapifiy(int arr[], int index, int size)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(arr[smallest], arr[index]);
        heapifiy(arr, smallest, size);
    }
}

void minheap(int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        heapifiy(arr, i, size);
    }
}
void MinHeapSort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
     heapifiy(arr, 0, i);
    }
}
void printheap(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[8] = {20, 30, 12, 43, 2, 56, 78, 99};
    int size = 8;
    // build(arr, size);
    // cout << "this is maxheap " << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout << "after sorting the heap" << endl;
    // heapSort(arr, 8);
    // printheap(arr, 8);
    cout << "given array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "min heap " << endl;
    minheap(arr, 8);
    printheap(arr, size);
     cout<<endl;
    cout << "Sort min heap" << endl;
    MinHeapSort(arr, size);
    printheap(arr, size);

    return 0;
}