class Solution {
public:
    string frequencySort(string s) {
          // Step 1: Count frequency of characters
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Max Heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto &it : freq) {
            maxHeap.push({it.second, it.first}); // freq first so it sorts by frequency
        }

        // Step 3: Build answer string
        string ans = "";
        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            char ch = maxHeap.top().second;
            maxHeap.pop();

            while (count--) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};