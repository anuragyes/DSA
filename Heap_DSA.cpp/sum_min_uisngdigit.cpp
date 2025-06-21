#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*Min sum formed by digits
 */

/*Input:
N = 6
arr[] = {6, 8, 4, 5, 2, 3}
Output:
604
Explanation:
The minimum sum is formed by numbers
358 and 246*/

// slow  and fast method uisng linked list
/*
int minSum(int arr[], int n)
{
//    better approch
    sort(arr, arr + n);

    long first = 0;
    long second = 0;

    for (int i = 0; i < n; i += 2)
    {
        first = (first * 10) + arr[i];
    }
    for (int i = 1; i < n; i += 2)
    {
        second = (second * 10) + arr[i];
    }



    return first + second;
}
*/

int minSum(int arr[], int n)
{
    //   optimal  approch

    long long int num1 = 0;
    long long int num2 = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]); // push all the element in priority_queue
    }

    while (!pq.empty())
    {
        num1 = num1 * 10 + pq.top();
        pq.pop();
        if (pq.empty())
            break;
        num2 = num2 * 10 + pq.top();
        pq.pop();
    }
    return (num1 + num2);
}
int main()
{
    int arr[6] = {6, 8, 4, 5, 2, 3};
    int size = 6;
    cout << minSum(arr, size);
}