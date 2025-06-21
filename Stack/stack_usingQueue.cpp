#include <iostream>
#include <stack>
using namespace std;

class stack
{
    int *arr;
    int size;
    int top = -1;

public:
    stack()
    {
        arr = new int[size];
        size = 100;
        top = -1;
    }
};

int main()
{
    return 0;
}