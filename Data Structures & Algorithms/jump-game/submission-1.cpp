class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        int idx = 0;
        while(idx < nums.size()){
            jump = max(jump, nums[idx]);
            
            if(idx + jump >= nums.size()-1){
                return true;
            }
            if(jump <= 0){
                return false;
            }
            jump--;
            idx++;
        }
        return false;
    }
};
