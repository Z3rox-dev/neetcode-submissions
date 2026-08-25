class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res {};
        for(int i = 0; i < nums.size()-3; i++){
            int num1 = nums[i];
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size()-2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int num2 = nums[j];
                int left = j + 1;
                int right = nums.size()-1;

                while(left < right){
                    long long solve = 1LL*num1 + 1LL*num2 + nums[left] + nums[right];
                    if(solve > target){
                        right--;
                    }
                    else if(solve < target){
                        left++;
                    }
                    else{
                        res.push_back({num1, num2, nums[left], nums[right]});
                        int lv = nums[left], rv = nums[right];
                        while (left < right && nums[left] == lv) left++;
                        while (left < right && nums[right] == rv) right--;
                    }
                }
            }
        }
        return res;
    }
};