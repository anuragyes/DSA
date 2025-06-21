#include <iostream>
using namespace std;

void find(int n)
{
    if (n == 0)
        return;

    cout << n << " " << "days are left to my birthday" << endl;
    find(n - 1);
}

void solve(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    solve(n - 1);
}

int sum(int arr[], int n)
{
    int add = 0;
    //  base case
    if (n == 0)
        return  add;

    add = add + arr[n];
    cout << add << endl;

    sum(arr, n - 1);
}
int main()
{
    int n = 5;
    // find(n);
    // solve(55);
    int arr[5] = {2, 3, 4, 5, 6};
    cout << sum(arr, 5);
    return 0;
}