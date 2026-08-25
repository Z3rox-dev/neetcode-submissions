class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> see;
        for(auto num : nums){
            if(see.count(num)){
                return true;
            }
            see.insert(num);
        }
        return false;
    }
};