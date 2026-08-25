class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int maxEnd = 0;
        int minEnd = 0;
        int total = 0;

        for(int& n : nums){
            total += n;
            maxEnd = max(n, maxEnd + n);
            maxSum = max(maxEnd, maxSum);
            minEnd = min(n, minEnd + n);
            minSum = min(minSum, minEnd);

        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};