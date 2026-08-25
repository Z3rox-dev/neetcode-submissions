class Solution {
public:
    int n = 0;
    vector<int> nums;
    int solve(int i, vector<int>& memo){
        if(i >= n - 1){
            return 0;
        }

        int &res = memo[i];
        if(res != -1){
            return res;
        }

        int jumps = min(n-1, i + nums[i]);
        res = 1e9;
        for(int idx = i + 1; idx <= jumps; idx++){
            res = min(res, 1 + solve(idx, memo));
        }

        return res;
    }
    int jump(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        vector<int> memo(n, -1);

        return solve(0, memo);
    }
};
