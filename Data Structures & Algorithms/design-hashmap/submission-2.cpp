class MyHashMap {
public:
    vector<list<pair<int,int>>> container;

    MyHashMap() : container(1000) {

    }

    void put(int key, int value) {
        int hash = key % 1000;
        auto& temp = container[hash];
        auto it = temp.begin();
        if(temp.empty()){
            temp.push_back(make_pair(key, value));
            return;
        }
        while(it != temp.end()){
            if(it->first == key){
                it->second = value;
                return;
            }
            it = next(it);
        }
        if(it == temp.end()){
            temp.push_back(make_pair(key, value));
        }
    }

    int get(int key) {
        int hash = key % 1000;
        auto it = container[hash].begin();
        while(it != container[hash].end()){
            if(it->first == key){
                return it->second;
            }
            it = next(it);
        }
        return -1;
    }

    void remove(int key) {
        int hash = key % 1000;
        auto it = container[hash].begin();
        while(it != container[hash].end()){
            if(it->first == key){
                container[hash].erase(it);
                return;
            }
            it = next(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */