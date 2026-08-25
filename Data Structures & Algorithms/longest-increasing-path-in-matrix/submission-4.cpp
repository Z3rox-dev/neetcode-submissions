class Solution {
public:
    int n = 0;
    int m = 0;
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool valid(int r, int c){
        return 0 <= r && r < n && 0 <= c && c < m;
    }
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo){
        int &res = memo[r][c];
        if(res != 0){
            return res;
        }
        res = 1;
        for(auto d : directions){
            int nr = r + d[0];
            int nc = c + d[1];
            if(valid(nr, nc) && matrix[r][c] < matrix[nr][nc]){
                res = max(res, 1 + dfs(matrix, nr, nc, memo));
            }
        }
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->n = matrix.size();
        this->m = matrix[0].size();
        vector<vector<int>> memo(n + 1, vector(m + 1, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }
};
