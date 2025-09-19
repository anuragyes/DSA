// void backtracking(vector<int> &arr, vector<vector<int>> &ans, int start) {
//     if (start == arr.size()) {
//         ans.push_back(arr);  // push current permutation
//         return;
//     }

//     for (int i = start; i < arr.size(); i++) {
//         swap(arr[start], arr[i]);              // choose
//         backtracking(arr, ans, start + 1);     // explore
//         swap(arr[start], arr[i]);              // un-choose (backtrack)
//     }
// }

// vector<vector<int>> Solution::permute(vector<int> &arr) {
//     vector<vector<int>> ans;
//     backtracking(arr, ans, 0);
//     return ans;
//}

void backtracking(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &used)
{
    if (temp.size() == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        temp.push_back(arr[i]);
        backtracking(arr, ans, temp, used);
        temp.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> Solution::permute(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used(arr.size(), false);
    backtracking(arr, ans, temp, used);
    return ans;
}
