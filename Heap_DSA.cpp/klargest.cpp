class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        while (!q.empty() && k > 1) { // pop until k-th largest
            q.pop();
            k--;
        }

        if (!q.empty())
            return q.top(); // k-th largest
        return -1;          // if k is larger than nums.size()

    }
};