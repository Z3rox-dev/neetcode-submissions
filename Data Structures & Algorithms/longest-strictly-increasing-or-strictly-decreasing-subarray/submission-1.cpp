class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mins = 0;
        int maxs = 0;
        int m = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i+1]){
                m++;
                mins = max(m, mins);
            }
            else{
                m = 0;
            }
        }
        m = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                m++;
                maxs = max(m, maxs);
            }
            else{
                m = 0;
            }
        }
        return max(mins,maxs) + 1;
    }
};