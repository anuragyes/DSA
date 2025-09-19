// Find All Lonely Numbers in the Array

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Traverse and check lonely condition
        for (int i = 0; i < n; i++) {
            bool leftDifferent = (i == 0 || nums[i] != nums[i - 1] + 1 &&
                                                nums[i] != nums[i - 1]);
            bool rightDifferent = (i == n - 1 || nums[i] != nums[i + 1] - 1 &&
                                                     nums[i] != nums[i + 1]);

            if (leftDifferent && rightDifferent) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
        //         //   make unorder map to store value  and thier frequency
        //         unordered_map<int, int> maap;
        //         for (auto element : nums) {
        //             maap[element]++;
        //         }
        //     // make a vector ans to store lonly number
        //          vector<int>ans;
        // //    walk through the maap and check the given condition
        //         for (auto element : maap) {
        //             int firstvalue = element.first;  // by value
        //             int secondvalue = element.second ; // by frequency

        //                               if (secondvalue == 1 &&
        //                                   maap.find(firstvalue + 1) ==
        //                                   maap.end() && maap.find(firstvalue
        //                                   - 1) == maap.end()){
        //                                     ans.push_back(firstvalue);
        //                                   }
        //         }

        //     // return the answer
        //          return ans;
    }
};