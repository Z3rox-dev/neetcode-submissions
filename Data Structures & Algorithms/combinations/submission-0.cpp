class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int n, int k, vector<int> cur, int idx){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }

        for(int i = idx; i <= n; i++){
            cur.push_back(i);
            backtrack(n, k, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, {}, 1);

        return res;
    }
};