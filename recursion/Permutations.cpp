#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int> &nums, vector<vector<int>> &ans, int index)
{
    // Base case: if index equals the size of the array, we have a complete permutation
    if (index == nums.size())
    {
        ans.push_back(nums); // Add the current permutation to the result
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);         // Swap the current index with i
        permutations(nums, ans, index + 1); // Recursively generate the rest of the permutations
        swap(nums[index], nums[i]);         // Swap back to the previous state
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    permutations(nums, ans, 0); // Call the function to generate permutations

    // Output the permutations
    for (const auto &perm : ans)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
