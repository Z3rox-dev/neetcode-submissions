class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map <int, int> duplicate;
        for(int num : nums){
            duplicate[num]++;
            if(duplicate[num] >= 2){
                return true;
            }
        }
        return false;
    }
};
