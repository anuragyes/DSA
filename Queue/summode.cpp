#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
    
        int n = arr.size();
        if (k <= 0 || k > n) return 0;

        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> maxHeap; // {freq, -value}
        int sum = 0, left = 0;

        for (int right = 0; right < n; right++) {
            // Add new element
            int x = arr[right];
            freq[x]++;
            maxHeap.push({freq[x], -x});

            // Shrink window if needed
            if (right - left + 1 > k) {
                int y = arr[left++];
                freq[y]--;
                maxHeap.push({freq[y], -y}); // push updated freq (may be 0)
            }

            // When window size == k, get mode
            if (right - left + 1 == k) {
                while (!maxHeap.empty()) {
                    int f = maxHeap.top().first;
                    int v = -maxHeap.top().second;
                    if (f == freq[v]) { // valid entry
                        sum += v;
                        break;
                    } else {
                        maxHeap.pop(); // stale entry
                    }
                }
            }
        }
     return sum;
        // TLE 
        /*
        unordered_map<int,int> maap;
        int sum = 0;
        int start = 0;
        int left = 0;
         
        while (start < arr.size()) {

            // add current element
            maap[arr[start]]++;

            // if window size exceeds k, shrink it
            if (start - left + 1 > k) {
                maap[arr[left]]--;
                if (maap[arr[left]] == 0) {
                    maap.erase(arr[left]);
                }
                left++;
            }

            // if window size == k, find mode
            if (start - left + 1 == k) {
                int mode = INT_MAX;
                int maxFreq = 0;

                for (auto &it : maap) {
                    if (it.second > maxFreq) {
                        maxFreq = it.second;
                        mode = it.first;
                    } 
                    else if (it.second == maxFreq) {
                        mode = min(mode, it.first);
                    }
                }
                sum += mode;
            }

            start++;  // ✅ move to next element
        }
        
        return sum;
        */
        
    }
    
};
