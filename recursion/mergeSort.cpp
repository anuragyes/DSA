#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end)
{

    int mid = start + (end - start) / 2;

    merge(arr, start, end);
}
void mergeSort(vector<int> arr,int start , int end )
{
    int start = 0;
    int end = arr.size() - 1;
    //    bvase cASE
    if (start > end)
        return;
    int mid = start + (end - start) / 2;

    //    left half
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    vector<int> arr = {1, 2, 1, 4, 6, 8, 9}; // Input array
    vector<int> ans;                         // To store subsequences
    int n = arr.size();
    int target = 2;

    cout << mergeSort(arr);
    return 0;
}