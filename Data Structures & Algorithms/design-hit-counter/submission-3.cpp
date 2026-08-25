class HitCounter {
public:
    HitCounter() {
        
    }
    vector<int> v;
    void hit(int timestamp) {
       v.push_back(timestamp); 
    }
    
    int getHits(int timestamp) {
        int target = timestamp - 299;
        auto it = lower_bound(v.begin(), v.end(), target);

        return v.end() - it;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
