class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> maap;
        for (int x : hand)
            maap[x]++;

        sort(hand.begin(), hand.end());

        while (!maap.empty()) {
            int curr = maap.begin()->first; // number maap.second means freq

            for (int i = 0; i < groupSize; i++) {
                if (maap[curr + i] == 0) {
                    return false; // curr not presetn
                }
                maap[curr + i]--;
                if (maap[curr + i] < 1) {
                    maap.erase(curr + i);
                }
            }
        }
        return true;
    }
};
