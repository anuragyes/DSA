#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {1, 2, 3};

    // Printing all the greater permutations
    // of the current vector
    do
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    } 
    
    while (next_permutation(v.begin(), v.end()));

    return 0;
}