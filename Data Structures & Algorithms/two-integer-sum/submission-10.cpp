class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for(int i = 0; i < nums.size(); i++){
            idx[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
           if(idx.count(diff) && idx[diff] != i){
            return {i, idx[diff]};
           }
        }
        return {0,0};
    }
};
