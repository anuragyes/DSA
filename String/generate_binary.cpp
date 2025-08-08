#include <iostream>
#include <vector>
using namespace std;

// Don't add consecutive 1's
class Solution
{
public:
    void generate(int n, string temp, vector<string> &ans)
    {
        if (n == 0)
        {
           
            ans.push_back(temp);
       
            return;
             
        }

        // Always add '0'
        generate(n - 1, temp + '0', ans);

  

        // Add '1' only if last character is not '1'
        if (temp.empty() || temp.back() != '1')
        {
            generate(n - 1, temp + '1', ans);
        }
    }

    vector<string> generateBinaryStrings(int n)
    {
        vector<string> ans;
        generate(n, "", ans);
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution obj;

    vector<string> result = obj.generateBinaryStrings(n);

    // Print result
    // for (string s : result)
    // {
    //     cout << s << endl;
    // }



  
    return 0;
}
