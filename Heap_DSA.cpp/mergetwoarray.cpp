#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> mergedArray;

    // Insert elements from arr1 into mergedArray
    for (int num : arr1)
    {
        mergedArray.push_back(num);
    }

    // Insert elements from arr2 into mergedArray
    for (int num : arr2)
    {
        mergedArray.push_back(num);
    }

    return mergedArray;
}

int main()
{
    vector<int> arr1 = {5, 6, 8, 3, 2, 4};
    vector<int> arr2 = {3, 6, 8, 9, 5, 4, 3, 2, 1, 2, 45, 6};

    vector<int> mergedArray = mergeArrays(arr1, arr2);

    // Print the merged array
    cout << "Merged array: ";
    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
