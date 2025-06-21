class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
       // If the array has fewer than 2 elements, second largest can't exist
    if (arr.size() < 2) {
        return -1;
    }

    // Sort the array in non-decreasing order
    sort(arr.begin(), arr.end());
    
    // Start from the end to find the largest distinct element
    int largest = arr[arr.size() - 1];

    // Traverse from the second last element to find the second largest distinct element
    for (int i = arr.size() - 2; i >= 0; --i) {
        // If we find a distinct element that is smaller than the largest, return it
        if (arr[i] < largest) {
            return arr[i];
        }
    }

    // If no second largest distinct element is found, return -1
    return -1;
    }
};