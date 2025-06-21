#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countWays(string &digits)
    {
        int n = digits.size();

        // Edge case: if digits is empty, no decodings are possible
        if (n == 0)
            return 0;

        // dp[i] will store the number of ways to decode the first i characters
        vector<int> dp(n + 1, 0);

        // There's one way to decode an empty string
        dp[0] = 1;

        // The first character must be non-zero to be decodable
        dp[1] = (digits[0] != '0') ? 1 : 0;

        // Iterate over the digits starting from index 1 (second character)
        for (int i = 2; i <= n; ++i)
        {
            // Check the current single digit
            if (digits[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }

            // Check if the last two digits form a valid letter (i.e., 10 to 26)
            int two_digit = stoi(digits.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }

        // The result is stored in dp[n], which contains the number of ways to decode the entire string
        return dp[n];
    }
};

int main()
{
    Solution sol;
    string digits = "226";
    cout << "Total number of ways to decode: " << sol.countWays(digits) << endl;
    return 0;
}
