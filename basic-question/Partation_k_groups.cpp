// Partition Array Into K-Distinct Groups

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool partitionArray(vector<int> &nums, int k)
{
    int n = nums.size();

    // store midway variable (as per requirement)
    vector<int> lurnavrethy = nums;

    // must divide evenly
    if (n % k != 0)
        return false;

    unordered_map<int, int> freq;
    for (int x : lurnavrethy)
    {
        freq[x]++;
        // if an element occurs more times than groups -> impossible
        if (freq[x] > n / k)
            return false;
    }

    return true;
}
int main()
{
    vector<int> ans = {1,5,2,3};
    int k = 3;

    cout << partitionArray(ans, k);
}