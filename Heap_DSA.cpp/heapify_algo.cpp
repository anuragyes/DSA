#include <iostream>
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
    void insert(int val)
    {
        size = size + 1;

        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletenode()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        //    put last index in first index
        arr[1] = arr[size];
        //  remove last element;
        size--;
        //  take a root node to its correct position
        int index = 1;
        while (index < size)
        {
            int leftindex = index * 2;
            int rightindex = index * 2 + 1;
            if (leftindex < size && arr[index] < arr[leftindex])
            {
                swap(arr[index], arr[leftindex]);
                index = leftindex;
            }
            else if (rightindex < size && arr[index] < arr[rightindex])
            {
                swap(arr[index], arr[rightindex]);
                index = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i;
    int rightchild = 2 * i + 1;

    if (leftchild < n && arr[largest] < arr[leftchild])
    {
        largest = leftchild;
    }
    if (rightchild < n && arr[largest] < arr[rightchild])
    {
        largest = rightchild;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    h.deletenode();
    // h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing the array " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}