#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMax(vector<int> &v)
{
    int maxi = INT16_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calcuatehour(vector<int> &v, int hour)
{
    int totaltime = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        totaltime = totaltime + ceil((double)v[i] / (double)hour);
    }
    return totaltime;
}

int Banana(vector<int> &v, int h)
{

    int start = 1;
    int end = findMax(v);

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int totalh = calcuatehour(v, mid);
        if (totalh <= h)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
};

int main()
{
    vector<int> arr = {3, 6, 7, 11};

    cout << Banana(arr, 8);
    return 0;
}