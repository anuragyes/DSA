#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateParenthesesHelper(vector<string> &result, string current, int open, int close, int max)
{
    // Base case: If the length of the current string is equal to 2*n, it's a valid combination
    if (current.size() == 2 * max)
    {
        result.push_back(current);
        return;
    }

    // Add an opening parenthesis if there are remaining openings
    if (open < max)
    {
        generateParenthesesHelper(result, current + '(', open + 1, close, max);
    }

    // Add a closing parenthesis if there are more openings than closings
    if (close < open)
    {
        generateParenthesesHelper(result, current + ')', open, close + 1, max);
    }
}

vector<string> generateParentheses(int n)
{
    vector<string> result;
    generateParenthesesHelper(result, "", 0, 0, n);
    return result;
}

int main()
{
    int n = 3; // Number of pairs of parentheses

    vector<string> parentheses = generateParentheses(n);

    // Print the generated parentheses
    cout << "Generated Parentheses for n = " << n << ":" << endl;
    for (const auto &p : parentheses)
    {
        cout << p << endl;
    }

    return 0;
}
