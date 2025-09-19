#include <bits/stdc++.h>
using namespace std;


void backtracking(vector<int> &arr, vector<vector<int>> &ans, int target, int start, vector<int> &temp) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        // skip duplicates
        if (i > start && arr[i] == arr[i-1]) continue;

        if (arr[i] > target) break; // pruning (since arr is sorted)

        temp.push_back(arr[i]);
        backtracking(arr, ans, target - arr[i], i, temp); // allow reuse
        temp.pop_back();
    }
}

vector<vector<int>>combinationSum(vector<int> &arr, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(arr.begin(), arr.end()); // ✅ sort for pruning + duplicates handling
    backtracking(arr, ans, target, 0, temp);

    return ans;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 4;

    cout <<combinationSum(arr, target) << endl; // Output = 2 ( [2,2,3] and [7] )
}
