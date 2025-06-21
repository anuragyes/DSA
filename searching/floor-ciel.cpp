#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> sortedArr, int x)
{

    sort(sortedArr.begin(), sortedArr.end());

    int floorValue = -1;
    int ceilValue = -1;

    // Find floor value
    for (int i = 0; i < sortedArr.size(); i++)
    {
        if (sortedArr[i] <= x)
        {
            floorValue = sortedArr[i];
        }
        else
        {
            break;  // No need to continue if the current value is greater than x
        }
    }

    // Find ceiling value
    for (int i = 0; i < sortedArr.size(); i++)
    {
        if (sortedArr[i] >= x)
        {
            ceilValue = sortedArr[i];
            break;
        }
    }

    cout << "Floor Value: " << floorValue << endl;
    cout << "Ceil Value: " << ceilValue << endl;
}

int main()
{
    int x = 7;
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    solve(arr, x);
    return 0;
}
