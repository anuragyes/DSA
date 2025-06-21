#include <iostream>
#include <queue>
using namespace std;

//  priority queueu always make maxheap   jo sbse bada element hoga usko jada priority milegi 
//  min heap ke leye prioriy queue mai negative value daale ge tb hume min heap milegi 

int main()
{
    priority_queue<int> q;

    q.push(13);
    q.push(12);
    q.push(341);
    q.push(14);
    q.push(16);
    q.push(10000);
    q.push(891);

    int n = q.size();
    // cout << n;

    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    return 0;
}