class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxSum = nums[0];
        int currSum = 0;
        
        for(int& n : nums){
            currSum = max(n, currSum + n);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
