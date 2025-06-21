#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumOperations(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    int x = 0;
    int count = 0;
    while (!pq.empty())
    {
        if (pq.top() == 0)
        {
            pq.pop();
            continue;
        }
        ++count;
        x = pq.top();

        while (!pq.empty() && pq.top() <= x)
        {
            pq.pop();
        }
    }
    return count;
}

int main()
{

    vector<int> arr = {1, 5, 0, 3, 5};
    cout << minimumOperations(arr);

    return 0;
}
