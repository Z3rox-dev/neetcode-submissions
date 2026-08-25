class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& memo, int end){
        if(i > end){
            return 0;
        }

        int &m = memo[i];
        if(m != -1){
            return m;
        }

        m = max(solve(nums, i + 1, memo, end), nums[i] + (solve(nums, i + 2, memo, end)));

        return m;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums.back();
        vector<int> memo(nums.size(), -1);
        int first = solve(nums, 0, memo, nums.size() - 2);

        vector<int> memo2(nums.size(), -1);
        int second = solve(nums, 1, memo2, nums.size() - 1);

        return max(first, second);
    }
};
