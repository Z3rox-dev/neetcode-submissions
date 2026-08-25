class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& profit, vector<int>& weight, int capacity, int idx){
        if(idx >= profit.size()){
            return 0;
        }

        if(memo[idx][capacity] != -1){
            return memo[idx][capacity];
        }

        memo[idx][capacity] = solve(profit, weight, capacity, idx + 1);

        if(capacity - weight[idx] >= 0){
            int p = profit[idx] + solve(profit, weight, capacity - weight[idx], idx + 1);
            memo[idx][capacity] = max(p, memo[idx][capacity]);
        }

        return memo[idx][capacity];
    }
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        memo = vector(profit.size(), vector(capacity + 1, -1));

        return solve(profit, weight, capacity, 0);
    }
};
