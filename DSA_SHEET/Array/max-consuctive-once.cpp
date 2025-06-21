

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//  Max Consecutive Ones

/*Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2*/

int main()
{

    // int arr[] = {1, 1, 0, 1, 1, 1};
    int arr[] = {1, 0, 1, 1, 0, 1};

    int max_cnt = 0, cnt = 0;
    for (auto n : arr)
    {
        //  cout << n << endl;
        if (n == 1)
            max_cnt = max(++cnt, max_cnt);
        else
            cnt = 0;
    }
    cout << max_cnt;
}

// note :nums[i] is either 0 or 1.