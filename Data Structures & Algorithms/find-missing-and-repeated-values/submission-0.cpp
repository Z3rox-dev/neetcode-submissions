class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(grid.size() * grid.size(), 0);

        for(auto& vec : grid){
            for(int& v : vec){
                ans[v-1] += 1;
            }
        }
        vector<int> res(2, 0);
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == 0){
                res[1] = i + 1;
            }
            else if(ans[i] > 1){
                res[0] = i + 1;
            }
        }
        return res;
    }
};