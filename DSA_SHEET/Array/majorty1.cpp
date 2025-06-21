#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
vector<int> countTheNumber(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> freqMap;
    vector<int> result;

    // Step 1: Count frequencies of each element in arr
    for (int i = 0; i < n; i++)
    {
        freqMap[arr[i]]++;
    }

    // Step 2: Calculate the threshold
    int threshold = n / k;

    // Step 3: Collect elements whose frequency is >= threshold
    for (auto it : freqMap)
    {
        if (it.second >= threshold)
        {
            result.push_back(it.first);
        }
    }

    // Step 4: Return the result vector
    return result;
}
int main()
{
    vector<int> ans = {1, 2, 3, 3, 3, 3, 4, 4, 4, 1, 2, 0};
    int k = 4;
    int n = 12;
    countTheNumber(ans, n, k);
    return 0;
}