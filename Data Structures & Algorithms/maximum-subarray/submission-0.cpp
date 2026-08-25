class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxSum = nums[0];
        int currSum = 0;
        int guard = nums[0];
        for(int& n : nums){
            guard = max(guard, n);
        }
        if(guard < 0 ){
            return guard;
        }
        for(int& n : nums){
            currSum += n;
            currSum = max(currSum, 0);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
