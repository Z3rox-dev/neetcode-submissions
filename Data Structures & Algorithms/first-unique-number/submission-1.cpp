class FirstUnique {
public:
    list<int> ll;
    unordered_map<int, int> mp;

    FirstUnique(vector<int>& nums) {
        for(auto n : nums){
            mp[n]++;
            ll.push_back(n);
        }
    }
    
    int showFirstUnique() {
        auto it = ll.begin();
        while(it != ll.end()){
            int top = *it;
            if(mp[top] == 1){
                return top;
            }
            it = next(it);
        }
        return -1;
    }
    
    void add(int value) {
        mp[value]++;
        ll.push_back(value);       
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
