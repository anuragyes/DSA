

/*Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.

Examples

Input: n = 10
Output: 3 7
Explanation: There are two possiblities 3, 7 & 5, 5 are both prime & their sum is 10, but we'll pick 3, 7 as 3 < 5.
Input: n = 3
Output: -1 -1
Explanation: There are no solutions to the number 3.*/

/*#include <vector>
#include <cmath> // For sqrt function

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        // Check from 2 to sqrt(num) if num is divisible by any number
        for (int i = 2; i*i<=num; ++i) {
            if (num % i == 0) {
                return false; // Found a divisor, hence not prime
            }
        }
        return true; // No divisors other than 1 and itself, hence prime
    }

    vector<int> getPrimes(int n) {
    vector<int> ans;

        // Iterate through numbers from 2 to n/2 to find two primes whose sum is n
        for (int i = 2; i <= n ; ++i) {
            if (isPrime(i) && isPrime(n - i)) {
                ans.push_back(i);
                ans.push_back(n - i);
                return ans;
            }
        }

        // If no such pair found, return {-1, -1} as per your original requirement
        return {-1, -1};
    }
};
*/