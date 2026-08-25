class Solution {
public:
    unordered_map<int, int> memo;

    int dp(vector<int>& nums, int index){
        if(index >= nums.size()){
            return 0;
        }

        auto it = memo.find(index);
        if(it != memo.end()){
            return it->second;
        }

        
        memo[index] += max(dp(nums,index + 1), (nums[index] + dp(nums,index + 2)));

        return memo[index];
    }
    int rob(vector<int>& nums) {
        return dp(nums, 0);
    }
};
