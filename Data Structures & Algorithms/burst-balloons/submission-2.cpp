class Solution {
public:
    vector<int> a;

    int solve(int i, int j, vector<vector<int>>& memo){
        if (i + 1 >= j){
            return 0;
        }

        int &res = memo[i][j];
        if(res != -1){
            return res;
        }
        res = 0;
        for(int k = i + 1; k <= j - 1; k++){
            res = max(res, a[i] * a[k] * a[j] + solve(i, k, memo) + solve(k, j, memo));
        }

        return res;
    }
    int maxCoins(vector<int>& nums) {
        this->a = vector(nums.size() + 2, 1);
        for(int i = 0; i < nums.size(); i++){
            a[i + 1] = nums[i];
        }

        int m = (int)a.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        return solve(0, a.size()-1, memo);
    }
};
