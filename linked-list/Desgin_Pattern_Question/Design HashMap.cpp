// Design HashMap 

class MyHashMap {
public:
    vector<int> st;

    MyHashMap() {
        // Initialize keys [0..1,000,000] with -1 (meaning "not present")
        st.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        st[key] = value;   // store value at index key
    }
    
    int get(int key) {
        return st[key];    // return value (or -1 if not present)
    }
    
    void remove(int key) {
        st[key] = -1;      // mark as removed
    }
};