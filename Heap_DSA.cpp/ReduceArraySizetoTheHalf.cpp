// Reduce Array Size to The Half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
         int n = arr.size();

        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (auto element : arr) {
            freq[element]++;
        }

        // Step 2: Max Heap (frequency first)
        priority_queue<int> maxHeap;
        for (auto& it : freq) {
            maxHeap.push(it.second);
        }

        // Step 3: Remove elements until half array is gone
        int removed = 0;
        int total = 0;
        while (total < n / 2) {
            total += maxHeap.top();  // remove most frequent
            maxHeap.pop();
            removed++;
        }

        return removed;
    }
};