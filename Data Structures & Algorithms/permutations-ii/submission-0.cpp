class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<vector<int>> seen, vector<int> cur){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        char levelSeen[10] = {}; 
        for(int i = 0; i < nums.size(); i++){
            if(seen[i][nums[i]] == 1) {
                continue;
            }
            if(levelSeen[nums[i]] == 1){
                continue;
            }

            levelSeen[nums[i]] = 1;
            cur.push_back(nums[i]);
            seen[i][nums[i]] = 1;
            backtrack(nums, seen, cur);
            int temp = cur.back();
            seen[i][temp] = 0;
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> seen(nums.size(), vector(10, 0));
       vector<int> cur = {};
       backtrack(nums, seen, cur);
       return res;
    }

};