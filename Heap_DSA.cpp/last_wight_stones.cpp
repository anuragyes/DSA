#include <bits/stdc++.h>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int firsttop = pq.top();
            pq.pop();
            int secondtop = pq.top();
            pq.pop();
            int diff = abs(firsttop - secondtop);
            pq.push(diff);
        }
         return pq.top();
    }
};