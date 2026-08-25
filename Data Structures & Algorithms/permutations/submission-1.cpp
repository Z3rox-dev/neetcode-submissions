class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> cur, unordered_set<int> curMemo){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(curMemo.find(nums[i]) != curMemo.end())continue;
            curMemo.insert(nums[i]);
            cur.push_back(nums[i]);
            backtrack(nums, cur, curMemo);
            int temp = cur.back();
            curMemo.erase(temp);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, {}, {});
        return res;
    }
};
