#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void arrange(string str)
{
    unordered_map<char, int> umap;
    for (auto x : str)
    {
        umap[x]++;
    }

    priority_queue<pair<char, int>> p;

    for (auto x : umap)
    {

        p.push(make_pair(x.second, x.first));
    }

    string ans = ""; // ans for storing the answer
    while (!p.empty())
    {
        auto top = p.top();
        p.pop();
        ans += string(top.second, top.first); // Append characters based on frequency
    }
    cout << ans;
}

int main()
{
    string str = "tree";
   arrange(str);
}