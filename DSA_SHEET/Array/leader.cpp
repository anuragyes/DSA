/*Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.*/

/*Leaders in an Array
Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n)
{

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        // Checking whether arr[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i])
            {

                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }

        // Push all the leaders in ans array.
        if (leader == true)
            ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{

    // Array Initialization.
    int n = 5;
    int arr[n] = {10, 4, 2, 4, 1};

    vector<int> ans = printLeadersBruteForce(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}
