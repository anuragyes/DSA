class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int subarray = 0;
        int count = 1; // length of current alternating streak

        // simulate circular by iterating n + k - 1 elements
        for (int i = 1; i < n + k - 1; i++) {
            if (colors[i % n] != colors[(i - 1) % n]) {
                count++;
            } else {
                count = 1; // reset streak
            }

            if (count >= k) subarray++;
        }

        return subarray;

    }
};

/*There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 */