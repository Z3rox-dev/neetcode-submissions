class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int high = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            high = max(prices[i] - min, high);
            min = std::min(prices[i], min);
        }
        return high;
    }
};
