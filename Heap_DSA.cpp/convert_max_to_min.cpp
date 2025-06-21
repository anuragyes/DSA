#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> &arr, int i, int n) // n  means number of edges
{
    int smallest = i;      // Initialize smallest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is smaller than rootbb 
    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected subtree
        minHeapify(arr, smallest, n);
    }
}

void convertMaxHeapToMinHeap(vector<int> &arr)
{
    int n = arr.size();

    // Start from the last non-leaf node and heapify all nodes in reverse level order
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        minHeapify(arr, i, n);
    }
}

int main()
{
    vector<int> maxHeap = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Max heap before conversion: ";
    for (int num : maxHeap)
    {
        cout << num << " ";
    }
    cout << endl;

    // Convert max heap to min heap
    convertMaxHeapToMinHeap(maxHeap);

    cout << "Min heap after conversion: ";
    for (int num : maxHeap)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
