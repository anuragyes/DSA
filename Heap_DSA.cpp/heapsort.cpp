#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Initialize root as largest
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify affected subtree
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max heap   we start i = n/2-1 they are all leaf  because all the leaf nodes are already heaps
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root to end
        heapify(arr, i, 0);     // Call max heapify on reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
