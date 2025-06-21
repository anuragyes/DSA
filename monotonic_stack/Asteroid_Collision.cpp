
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//  negative sign indicate the direction of stone

vector<int> aCollision(vector<int> &a)
{
    stack<int> stk;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (stk.empty() || a[i] > 0)
        {
            stk.push(a[i]);
        }
        else
        {
            while (!stk.empty() && stk.top() > 0 && stk.top() < abs(a[i]))
            {
                stk.pop();
            }
            if (stk.empty() || stk.top() < 0)
            {
                stk.push(a[i]);
            }
            else if (stk.top() == abs(a[i]))
            {
                stk.pop();
            }
        }
    }
    vector<int> result;
    while (!stk.empty())
    {
        result.insert(result.begin(), stk.top());
        stk.pop();
    }
    return result;
}

int main()
{
    vector<int> as = {-1, -2, 1, 2};
    vector<int> remainingas = aCollision(as);
    cout << "Remaining as: ";
    for (int a : remainingas)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}