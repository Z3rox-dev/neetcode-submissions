class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int> cur, int index){
        if(cur.size() > nums.size()){
            return;
        }

        res.push_back(cur);
        if (index >= nums.size()) return;
        
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i-1] == nums[i]) continue;
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        backtrack(nums, cur, 0);
        return res;
    }
};
