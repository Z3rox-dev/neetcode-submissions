class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int>& prices, int index, int hold){
        if(index == prices.size()){
            return 0;
        }
        if(memo[index][hold] != -1){
            return memo[index][hold];
        }
        if(hold){
            memo[index][hold] = max(prices[index] + solve(prices, index + 1, 0), solve(prices, index + 1, 1));
        }
        else{
            memo[index][hold] = max(-prices[index] + solve(prices, index + 1, 1), solve(prices, index + 1, 0));
        }

        return memo[index][hold];
    }
    int maxProfit(vector<int>& prices) {
        memo = vector(prices.size(), vector(2, -1));
        return solve(prices, 0, 0);
    }   
};