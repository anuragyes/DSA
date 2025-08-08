// #include <iostram>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& arr, int index, vector<int>& temp, vector<vector<int>>& ans) {
        if (index == arr.size()) {
            ans.push_back(temp);  // Add current subset
            return;               // Must return here to stop recursion
        }

        // Include arr[index] in the subset
        temp.push_back(arr[index]);
        backtracking(arr, index + 1, temp, ans);
        temp.pop_back();  // Backtrack

        // Exclude arr[index] from the subset
        backtracking(arr, index + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> temp;
        vector<vector<int>> ans;

        backtracking(arr, 0, temp, ans);

        sort(ans.begin(), ans.end());  // Optional: to keep subsets ordered
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(input);

    cout << "Subsets of {1, 2, 3}:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
