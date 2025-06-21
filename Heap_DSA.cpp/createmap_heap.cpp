#include <iostream>
using namespace std;

class Maxheap
{
    int *arr;
    int size;       // number of heap present in heap
    int total_size; // total size of heap

public:
    Maxheap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insertElement(int val)
    {

        if (total_size == size)
        {
            cout << "maxheap is overflow" << endl;
            return;
        }
        arr[size] = val; // insert the element in last
        int index = size;
        size++;
        //  compare with thier parents

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {

            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into the heap " << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Maxheap h1(10);
    h1.insertElement(20);
    h1.insertElement(10);
    h1.insertElement(23);
    h1.insertElement(12);
    h1.insertElement(13);
    h1.insertElement(11);

    h1.print();

    return 0;
}