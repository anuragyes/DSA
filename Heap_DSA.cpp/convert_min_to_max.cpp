

#include <iostream>
#include <vector>

void maxHeapify(std::vector<int>& arr, int i, int n) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        maxHeapify(arr, largest, n);
    }
}

void convertMinHeapToMaxHeap(std::vector<int>& arr) {
    int n = arr.size();

    // Start from the last non-leaf node and heapify all nodes in reverse level order
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}

int main() {
    std::vector<int> minHeap = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Min heap before conversion: ";
    for (int num : minHeap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Convert min heap to max heap
    convertMinHeapToMaxHeap(minHeap);

    std::cout << "Max heap after conversion: ";
    for (int num : minHeap) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
