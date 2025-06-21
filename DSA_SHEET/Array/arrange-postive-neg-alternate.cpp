#include <iostream>
#include <vector>
using namespace std;

//  brute force approch 
void posAndNeg(vector<int> &arr)
{
     vector<int> positive;
        vector<int> negative;

        // Separate positive and negative numbers
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= 0) {
                positive.push_back(arr[i]);
            } else {
                negative.push_back(arr[i]);
            }
        }

        arr.clear(); // Clear the original array

        int i = 0, j = 0;

        // Alternate between positive and negative elements
        while (i < positive.size() && j < negative.size()) {
            arr.push_back(positive[i]);
            i++;
            arr.push_back(negative[j]);
            j++;
        }

        // Add remaining positive elements (if any)
        while (i < positive.size()) {
            arr.push_back(positive[i]);
            i++;
        }

        // Add remaining negative elements (if any)
        while (j < negative.size()) {
            arr.push_back(negative[j]);
            j++;
        }
}



// optimal apprcoh 
void rearrange(vector<int>& arr) {
    vector<int> positive, negative;

    // Separate positive and negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {  // 0 is considered positive
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }

    arr.clear();  // Clear the original array

    int i = 0, j = 0;

    // Fill arr with alternating positive and negative elements
    while (i < positive.size() && j < negative.size()) {
        arr.push_back(positive[i++]);  // First positive
        arr.push_back(negative[j++]);  // Then negative
    }

    // Append remaining positive elements, if any
    while (i < positive.size()) {
        arr.push_back(positive[i++]);
    }

    // Append remaining negative elements, if any
    while (j < negative.size()) {
        arr.push_back(negative[j++]);
    }
}

int main() {
    vector<int> arr = {1, 2, -3, -1, -2, 3, 0, -4};  // Example input
    rearrange(arr);

    // Output the rearranged array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
