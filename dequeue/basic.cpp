#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back(34);
    d.push_back(14);
    d.push_back(24);
    d.push_back(44);
    d.push_back(40000);
    d.push_front(100);
    // d.pop_front();
    d.pop_back();

   deque<int>::iterator it;
    for (it = d.begin(); it != d.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
