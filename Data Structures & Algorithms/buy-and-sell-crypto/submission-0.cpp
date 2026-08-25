class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); i++){
            buy = std::min(buy, prices[i]);
            int sell = prices[i];
            int profit = sell - buy;
            maxProfit = std::max(maxProfit, profit);
        }
        return maxProfit;
    }
};
