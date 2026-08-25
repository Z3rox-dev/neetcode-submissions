class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -1;
        int left = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(temp < 0){
                temp = nums[i];
                left = i;
            }
            else{
                temp += nums[i];
            }
            res = max(temp, res);
        }
        return res;
    }
};
