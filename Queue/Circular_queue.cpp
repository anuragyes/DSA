#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor to initialize the queue with a given capacity
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }
    
    // Enqueue operation
    bool enQueue(int value) {
        if (isFull()) {
            return false; // Queue is full, cannot enqueue
        }
        queue[rear] = value;
        rear = (rear + 1) % capacity; // Circular increment
        size++;
        return true;
    }
    
    // Dequeue operation
    bool deQueue() {
        if (isEmpty()) {
            return false; // Queue is empty, cannot dequeue
        }
        front = (front + 1) % capacity; // Circular increment
        size--;
        return true;
    }
    
    // Get the front element
    int Front() {
        if (isEmpty()) {
            return -1; // Return -1 if the queue is empty
        }
        return queue[front];
    }
    
    // Get the rear element
    int Rear() {
        if (isEmpty()) {
            return -1; // Return -1 if the queue is empty
        }
        int rearIndex = (rear - 1 + capacity) % capacity; // Adjust rear index circularly
        return queue[rearIndex];
    }
    
    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue q(3);

    // Testing enqueue and dequeue
    std::cout << "Enqueue 1: " << q.enQueue(1) << std::endl; // true
    std::cout << "Enqueue 2: " << q.enQueue(2) << std::endl; // true
    std::cout << "Enqueue 3: " << q.enQueue(3) << std::endl; // true
    std::cout << "Enqueue 4: " << q.enQueue(4) << std::endl; // false, full

    std::cout << "Front: " << q.Front() << std::endl; // 1
    std::cout << "Rear: " << q.Rear() << std::endl; // 3
    
    std::cout << "Dequeue: " << q.deQueue() << std::endl; // true
    std::cout << "Enqueue 4: " << q.enQueue(4) << std::endl; // true
    
    std::cout << "Front: " << q.Front() << std::endl; // 2
    std::cout << "Rear: " << q.Rear() << std::endl; // 4

    return 0;
}
