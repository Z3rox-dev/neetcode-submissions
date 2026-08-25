class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int con = 0;
        int s = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                con = 0;
            }
            else{
                con++;
            }
            s = max(s, con);
        }
        return s;
    }
};