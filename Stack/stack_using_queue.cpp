#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;
    int size;

    Stack() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int element) {
        // Push element into q2
        q2.push(element);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

        size++;
    }

    int pop() {
        if (isEmpty()) return -1; // Stack underflow
        int topElement = q1.front();
        q1.pop();
        size--;
        return topElement;
    }

    int top() {
        if (isEmpty()) return -1; // Stack underflow
        return q1.front();
    }
};
