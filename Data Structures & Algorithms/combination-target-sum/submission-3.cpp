class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int& target, vector<int> vec, int sum, int index){
        if(sum == target){
            ans.push_back(vec);
            return;
        }
        if( sum > target){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            sum += nums[i];
            vec.push_back(nums[i]);
            backtrack(nums, target, vec, sum, i);
            sum -= nums[i];
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> vec;
        backtrack(nums, target,vec, 0, 0);
        return ans;
    }
};
