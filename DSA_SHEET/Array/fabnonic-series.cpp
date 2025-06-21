
#include <iostream>
using namespace std;

#include <iostream>

int fibonacciRecursive(int n) {
    if (n <= 1 )
        return n;
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    
}

void printFibonacci(int n) {
    for (int i = 0; i < n; ++i) {
       cout << fibonacciRecursive(i) << " ";
    }
}

int main() {
    int n;
  cout << "Enter the number of terms: ";
  cin >> n;
    printFibonacci(n);
    return 0;
}
