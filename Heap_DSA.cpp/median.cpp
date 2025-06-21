#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int signam(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callmedian(vector<int> &arr, priority_queue<int> *maxi, priority_queue<int, vector<int>, greater<int>> *mini, int &median)
{
     switch (signam)
     {
     case /* constant-expression */:
        /* code */
        break;
     
     default:
        break;
     }
}

vector<int> findmedian(vector<int> &arr, int size)
{

    vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = -1;
    for (int i = 0; i < size; i++)
    {
        callmedian(arr, maxheap, minheap, median);
        ans.push_back(median);
        return ans;
    }
}

int main()
{
    return 0;
}