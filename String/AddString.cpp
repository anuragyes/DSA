// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int index1 = num1.size() - 1;
        int index2 = num2.size() - 1;
        int carry = 0;
        //  answer
        string ans;

        while (index1 >= 0 || index2 >= 0 || carry > 0)
        {
            int sum = carry; // Start with carry

            if (index1 >= 0)
            {
                sum += num1[index1] - '0'; // Add digit from num1
                index1--;
            }
            if (index2 >= 0)
            {
                sum += num2[index2] - '0'; // Add digit from num2
                index2--;
            }

            carry = sum / 10; // Calculate new carry

            ans += (sum % 10) + '0'; // Append the digit to result
        }

        reverse(ans.begin(), ans.end()); // Reverse the result string
        return ans;
    }
};
