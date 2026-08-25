class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int best = 0;

        for(const int& price : prices){
            minimum = min(minimum, price);
            best = max(best, price - minimum);
        }
        return best;
    }
};
