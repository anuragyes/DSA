#include <iostream>
#include <vector>
#include <queue>    
using namespace std;

// Function to get maximum value in arr[]
int getMax(vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        mx = max(mx, arr[i]);
    return mx;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] so it contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to sort arr[] using Radix Sort
void radixSort(vector<int>& arr) {
    int m = getMax(arr);

    // Do counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

// Driver code
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    radixSort(arr);

    cout << "Sorted array:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n";

    return 0;
}
