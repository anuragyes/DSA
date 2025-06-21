#include <iostream>
#include <vector>
using namespace std;

//  this code is right

vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> result;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
        }
        else
        {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // Copy the remaining elements from both arrays, if any
    while (i < arr1.size())
    {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 67, 68, 67, 90};

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : mergedArray)
    {
        cout << num << " ";
    }

    return 0;
}
