#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumOperations(vector<int> &arr1, vector<int> &arr2, int k)
{
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            sum = arr1[i] + arr2[j];
            pq.push(i);
        }
    }
}

int main()
{

    vector<int> arr1 = {1, 1, 2};
    vector<int> arr2 = {1, 2, 3};
    // cout << minimumOperations(arr1, arr2);

    return 0;
}
