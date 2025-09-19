
// design the class in the most optimal way

#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;  // key -> node
    Node* head;
    Node* tail;

    // Helper function to move node to the front of the list
    void moveToFront(Node* node) {
        deleteNode(node);  // Remove the node from its current position
        addFront(node);    // Add the node to the front of the list
    }

    // Helper function to delete a node from the list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper function to add a node to the front of the list
    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper function to remove the last node (least recently used) from the list
    void popTail() {
        Node* tailPrev = tail->prev;
        deleteNode(tailPrev);
        cache.erase(tailPrev->key);  // Remove the node from the cache map
        delete tailPrev;             // Delete the node from memory
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);  // Create dummy head
        tail = new Node(0, 0);  // Create dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }

        Node* node = cache[key];
        moveToFront(node);  // Move the accessed node to the front
        return node->value; // Return the value
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If the key exists, update the value and move it to the front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // If the key does not exist
            if (cache.size() == capacity) {
                // If the cache is full, remove the least recently used node
                popTail();
            }

            Node* newNode = new Node(key, value);
            cache[key] = newNode;  // Add the node to the cache map
            addFront(newNode);     // Add the node to the front of the list
        }
    }
};
