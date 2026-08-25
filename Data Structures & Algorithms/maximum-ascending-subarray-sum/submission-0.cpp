class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int cur = nums[0];
        int longest = cur;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                cur += nums[i];
                longest = max(cur, longest);
            }
            else{
                cur = nums[i];
            }
        }
        return longest;
    }
};