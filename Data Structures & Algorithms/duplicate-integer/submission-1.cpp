class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , int> duplicates;
        for(const auto& num : nums){
            duplicates[num]++;
            if(duplicates[num] > 1){
                return true;
            }
        }
        return false;
    }
};