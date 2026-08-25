class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, int target, int sum, int index, vector<int> current){
        if(sum == target){
            res.push_back(current);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            if(sum > target) break;
            current.push_back(candidates[i]);
            backtrack(candidates, target, sum, i + 1, current);
            sum -= current.back();
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, current);
        return res;
    }
};
