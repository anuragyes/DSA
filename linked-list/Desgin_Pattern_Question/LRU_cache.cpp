#include <unordered_map>
using namespace std;
/*
class Node
{
public:
    int key, value;
    Node *prev;
    Node *next;
    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void moveToFront(Node *node)
    {
        removeNode(node);
        addFront(node);
    }

    void removeNode(Node *node)
    {
        if (!node || node == head || node == tail)
            return; // Safety check
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addFront(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void popTail()
    {
        Node *last = tail->prev;
        if (last == head)
            return; // Nothing to remove
        removeNode(last);
        cache.erase(last->key);
        delete last;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache()
    {
        Node *curr = head;
        while (curr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        Node *node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return; // Prevent invalid ops

        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToFront(node);
        }
        else
        {
            if (cache.size() >= capacity)
            {
                popTail();
            }
            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            addFront(newNode);
        }
    }
};



*/

/*





 unordered_map<int,Node*>maap;


   Node*  head =  new Node(0);
    Node* tail = new Node(0);


     Node* start = head;
     Node* end = tail;



       start->next = tail;
       tail->prev = start;

          void put(int key , int value){
             if(maap.size()>=capacity)  {

                 deletefromtail();
             }


                   if(maap.find(key)!=maap.end()){

                    Node* newnode = maap[key];;
                    maap[key] = newNode;
                    //   add into starting head
                    addFront(newnode);
                    return
                    }else{
                    Node* newnode = new Node(key,value);
                    maap[key] = value;
                    }

          }












*/