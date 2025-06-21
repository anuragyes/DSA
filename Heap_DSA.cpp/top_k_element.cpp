#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{

    unordered_map<int, int> umap;
    for (auto x : nums)
    {
        umap[x]++; // element comes with pairs
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p; // min heap with pair

    for (auto x : umap)
    {
         //first value indicate the count and second value indicate the element 
        p.push(make_pair(x.second, x.first)); // when we push the pair into any dsa use make_pair key word
        if (p.size() > k)
            p.pop();
    }

    vector<int> ans; // ans for storing the answer
    while (!p.empty())
    {
        pair<int, int> temp = p.top();

        p.pop();

        ans.push_back(temp.second);
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 3};

    int k = 2;
    topKFrequent(arr, k);

    return 0;
}