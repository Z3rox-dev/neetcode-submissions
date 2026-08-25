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
        int left = 0;
        int right = v.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return v.size() - left;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
