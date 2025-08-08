// All Paths From Source to Target

class Solution {
public:
    void dfs(int node ,  vector<vector<int>>&ans ,vector<int>&temp,vector<vector<int>>& graph) {
        temp.push_back(node);

        // base case
        if (node ==  graph.size() - 1) {
            ans.push_back(temp);
           
        } else {
            for (auto element : graph[node]) {
                dfs(element, ans, temp, graph);
            }
        }
        //    backtracking 
          temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp; // make a vector to store every level
            vector<vector<int>>
                ans;
        dfs(0, ans, temp, graph);
        return ans;
    }
};

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.