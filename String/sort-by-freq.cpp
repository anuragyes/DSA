class Solution {
public:
    string frequencySort(string s) {
       // Step 1: Count frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Create a max heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first}); // {frequency, character}
        }

        // Step 3: Build the result string
        string result;
        while (!maxHeap.empty()) {
            auto [freq, charac] = maxHeap.top();
            maxHeap.pop();
            result += string(freq, charac); // Append 'charac' freq times
            // if freq = 3 char 'd'  == 'ddd'
        }

        return result;
    }
};


 Sort Characters By Frequency
//   Example 
 Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.