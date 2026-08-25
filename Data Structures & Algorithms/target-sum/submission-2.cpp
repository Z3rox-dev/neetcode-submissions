class Solution {
public:
    int offset;
    int target;
    int solve(vector<int>& nums, int cur, int idx, vector<vector<int>>& memo){
        if(idx == nums.size()){
            if(cur == target){
                return 1;
            }
            return 0;
        }

        int key = offset + cur;
        int &m = memo[idx][key];
        if(m != -1){
            return m;
        }

        m = solve(nums, cur + nums[idx], idx + 1, memo) + solve(nums, cur - nums[idx], idx + 1, memo);

        return m;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int max = accumulate(nums.begin(), nums.end(), 0);
        offset = max;
        this->target = target;
        vector<vector<int>> memo(nums.size(), vector(max * 2 + 1, -1));

        return solve(nums, 0, 0, memo);
    }
};
