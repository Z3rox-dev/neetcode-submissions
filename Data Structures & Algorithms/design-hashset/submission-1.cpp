class MyHashSet {
public:
    vector<list<int>::iterator> store;
    list<int> ll;

    MyHashSet() {
        store = vector<list<int>::iterator>(1000000, ll.end());
    }

    void add(int key) {
        if(store[key] == ll.end()){
            ll.push_back(key);
            store[key] = prev(ll.end());
        }

    }
    
    void remove(int key) {
        if(store[key] == ll.end()) return;
       auto it = store[key];
       ll.erase(it);
       store[key] = ll.end();
    }
    
    bool contains(int key) {
        if(store[key] != ll.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */