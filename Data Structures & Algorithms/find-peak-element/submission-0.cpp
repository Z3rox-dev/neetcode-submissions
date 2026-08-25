class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            if(nums[left] >= nums[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return left;
    }
};