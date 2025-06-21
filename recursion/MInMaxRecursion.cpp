#include <iostream>
#include <vector>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

void find(vector<int> &arr, int &maxi, int &mini, int index)
{
    // Base case: when we reach the end of the array
    if (index == arr.size())
    {
        return;
    }

    // Update the maximum and minimum values
    if (arr[index] > maxi)
    {
        maxi = arr[index];
    }
    if (arr[index] < mini)
    {
        mini = arr[index];
    }

    // Recur for the next index
    find(arr, maxi, mini, index + 1);
}

pair<int, int> count(vector<int> &arr)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    find(arr, maxi, mini, 0); // Start recursion from index 0
    return make_pair(maxi, mini);
}

int main()
{
    vector<int> arr = {1, 5, 6, 3, 8, 9};
    // Get the maximum and minimum values
    pair<int, int> result = count(arr);
    cout << "Maximum value: " << result.first << endl;
    cout << "Minimum value: " << result.second << endl;
    return 0;
}
