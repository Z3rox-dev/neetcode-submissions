class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int ans = INT_MAX;
        while(left <= right){
            int mid = floor(left + (right - left)/2);
            ans = std::min(nums[mid], ans);
            if(nums[left] < nums[mid]){
                ans = std::min(nums[left], ans);
                left = mid + 1;
            }
            else{
                ans = std::min(nums[right], ans);
                right = mid - 1;
            }
        }
        return ans;
    }
};
