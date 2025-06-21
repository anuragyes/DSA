class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> maap;
        for (const string& s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            maap[sortedStr].push_back(s);
        }
    
        vector<vector<string>> ans;
        for (auto& pair : maap) {
            ans.push_back(pair.second);
        }
    
        return ans;
        }
    };