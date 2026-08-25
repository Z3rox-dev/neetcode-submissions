class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int left = 0;
       int right = 0;

       while(right < nums.size()){
        if(nums[left] == nums[right]){
            right++;
            continue;
        }
        else{
            left++;
            nums[left] = nums[right];
        }
       }
    return left + 1;
    }
};