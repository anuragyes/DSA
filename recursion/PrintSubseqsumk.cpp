#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &nums, int n, int sum, int &count, int index, int target)
{

    // base case
    if (index == n)
    {
        if (sum == target)
        {
            count++; // if the sum is less than or equal to the target, increment count
        }
        return;
    }

    // include the current element
    sum += nums[index];
    helper(nums, n, sum, count, index + 1, target);

    // backtrack and exclude the current element
    sum -= nums[index];
    ans.pop_back();
    helper(nums, n, sum, count, index + 1, target);
}

int numSubseq(vector<int> &nums, int target)
{
    int n = nums.size();
    int count = 0;
    int sum = 0;
    helper(nums, n, sum, count, 0, target);
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 1}; // Input array
    vector<int> ans;             // To store subsequences
    int n = arr.size();
    int target = 2;

    cout << numSubseq(arr, target); // Start from index 0
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// void helper(vector<int> &nums, int n, int sum, int &count, int index, int target, vector<int> &ans)
// {
//     // base case
//     if (index == n)
//     {
//         if (sum == target)
//         {
//             // If sum equals target, store the subsequence
//             count++;
//             // For debugging, let's print the subsequence
//             cout << "Subsequence: ";
//             for (int num : ans)
//             {
//                 cout << num << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     // include the current element in the subsequence
//     ans.push_back(nums[index]);
//     sum = sum + nums[index];
//     helper(nums, n, sum + nums[index], count, index + 1, target, ans);

//     // backtrack, remove the last added element, and exclude it from the subsequence
//     sum = sum - nums[index];
//     ans.pop_back();
//     helper(nums, n, sum, count, index + 1, target, ans);
// }

// int numSubseq(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int count = 0;
//     int sum = 0;
//     vector<int> ans; // To store subsequences
//     helper(nums, n, sum, count, 0, target, ans);
//     return count;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 1}; // Input array
//     int target = 2;              // The target sum for subsequences

//     cout << "Total subsequences with sum equal to target: " << numSubseq(arr, target) << endl;
//     return 0;
// }
