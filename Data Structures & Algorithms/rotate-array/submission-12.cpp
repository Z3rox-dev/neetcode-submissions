class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int reverseOps = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + reverseOps);
        reverse(nums.begin()  + reverseOps, nums.end());
    }
};