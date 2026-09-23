class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1;
            int right = nums.size()-1;
             if(i > 0 && nums[i] == nums[i - 1]) continue;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    left++;
                    right--;
                    while(left < nums.size() && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(right != nums.size() - 1 && right > 0 && nums[right] == nums[right + 1]){
                        right--;
                    }
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
