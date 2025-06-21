#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> check;
    vector<vector<int>> op;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++)
    {
        int j = i + 1;
        int k = size - 1;
        while (j < k)
        {
            int summ = nums[i] + nums[j] + nums[k];
            if (summ == 0)
            {
                check.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (summ >= 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    for (auto a : check)
    {
        op.push_back(a);
    }
    return op;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    for (auto triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
