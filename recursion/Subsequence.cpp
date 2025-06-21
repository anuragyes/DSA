#include <iostream>
#include <vector>
using namespace std;

// Function to print subsequences using recursion
void sub(vector<int> &arr, int n, vector<int> &ans, int index)
{
    // If index reaches the end, print the current subsequence
    if (index == n)
    {
        cout << "[ ";
        for (int num : ans)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
        return;
    }

    // Include the current element and recurse
    ans.push_back(arr[index]);
    sub(arr, n, ans, index + 1);

    // Exclude the current element and recurse
    ans.pop_back();
    sub(arr, n, ans, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4}; // Input array
    vector<int> ans;                // To store subsequences
    int n = arr.size();

    cout << "Subsequences are:" << endl;
    sub(arr, n, ans, 0); // Start from index 0
    return 0;
}
