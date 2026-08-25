class Solution {
public:
    set<vector<int>> mySet;
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int target, int index, int sum){
        if(sum > target) return;

        if(sum == target && !mySet.count(path)){
            res.push_back(path);
            mySet.insert(path);
        }
        else if(sum == target){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            sum += nums[i];
            backtrack(nums, target, i, sum);
            sum -= nums[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);

        return res;
    }
};
