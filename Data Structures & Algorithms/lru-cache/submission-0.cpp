class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator>_map;
    list<pair<int, int>> lru;
    int capacity = 0;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = _map.find(key);
        if(it == _map.end()){
            return -1;
        }
        lru.splice(lru.begin(), lru, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = _map.find(key);
        if(it != _map.end()){
            it->second->second = value;
            lru.splice(lru.begin(), lru, it->second);
            return;
        }

        if(capacity == lru.size()){
            auto& node = lru.back();
            _map.erase(node.first);
            lru.pop_back();
        }

        lru.emplace_front(key, value);
        auto iterator = lru.begin();
        _map[key] = iterator;

    }
};
