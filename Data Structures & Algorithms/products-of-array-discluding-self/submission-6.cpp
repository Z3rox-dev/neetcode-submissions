class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> forward = vector(nums.size(), 1);
        vector<int> backward = vector<int>(nums.size(), 1);

        for(int i = 1 ; i < nums.size(); i++){
            forward[i] = forward[i-1] * nums[i - 1];
        }
        for(int i = nums.size()-2 ; i >= 0; i--){
            backward[i] = backward[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i] = forward[i] * backward[i];
        }
        return nums;
    }
};
