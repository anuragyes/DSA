#include <iostream>
#include <vector>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i;
    int rightchild = 2 * i + 1;

    if (leftchild <= n && arr[largest] < arr[leftchild])
    {
        largest = leftchild;
    }
    if (rightchild <= n && arr[largest] < arr[rightchild])
    {
        largest = rightchild;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 0)
    {
        swap(arr[size], arr[0]); // swap last element and root element 
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{

    int arr[6] = {1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n-1 / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    heapsort(arr, n);

    cout << "printing the heap sort " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}