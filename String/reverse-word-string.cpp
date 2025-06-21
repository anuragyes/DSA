class Solution {
public:
    string reverseWords(string str) {
        // code here
        int n = str.length();
        vector<string> temp;
        string word = "";

        for (int i = 0; i < n; i++) {
            if (str[i] == ' ') {
                if (!word.empty()) {  // Only add non-empty words
                    temp.push_back(word);
                    word = "";
                }
            } else {
                word += str[i];
            }
        }

        // Add the last word if it's not empty
        if (!word.empty())
            temp.push_back(word);

        reverse(temp.begin(), temp.end());
        string ans = "";

        for (int i = 0; i < temp.size(); i++) {
            ans += temp[i];
            if (i < temp.size() - 1) {
                ans += ' '; // Add space between words
            }
        }

        return ans; // Resulting string will not have leading or trailing spaces
    }
};