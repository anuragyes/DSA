class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        // Min-heap: {sum, index1, index2}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;

        // Initialize heap with first element of nums2 for each nums1[i]
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top(); 
            minHeap.pop();

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};
/*Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]*/