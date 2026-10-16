class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& curVec = store[key];
        curVec.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = store.find(key);
        if(it == store.end()) return "";
        auto& curVec = it->second;
        for(int i = curVec.size() - 1; i >= 0; i--){
            
            if(curVec[i].first <= timestamp){
                return curVec[i].second;
            }
        }
        return "";
    }
};
