class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sums;

        for(int i = 0; i < nums.size(); i ++){
            sums[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            if(sums.find(t) != sums.end() && i != sums[t]){
                return {i, sums[t]};
            }
        }
        return{-1, -1};
    }
};
