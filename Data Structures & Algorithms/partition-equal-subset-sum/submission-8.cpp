class Solution {
public:
    bool solve(vector<int>& nums, int target, int cur, int idx, vector<vector<int>>& memo){
        if(idx >= nums.size()){
            return false;
        }
        if(cur > target){
            return false;
        }
        if(cur == target){
            return true;
        }

        int m = memo[idx][cur];
        if(m != -1){
            return memo[idx][cur];
        }

        m = solve(nums, target, cur + nums[idx], idx + 1, memo) || solve(nums, target, cur, idx + 1, memo);
        
        return m;
        
    }
    bool canPartition(vector<int>& nums) {
        int n = accumulate(nums.begin(), nums.end(), 0);
        if(n % 2) return false;
        int target = n * 0.5;
        vector<vector<int>> memo(nums.size(), vector(n + 1, -1));

        return (solve(nums, target, 0, 0, memo));

    }
};
