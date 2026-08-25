class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> heights;
    void dfs(int row, int col, vector<vector<int>>& h, vector<vector<int>>& solve){
        solve[row][col] = 1;

        for(auto d : directions){
            int nr = row + d[0];
            int nc = col + d[1];
            if(valid(nr, nc) && solve[nr][nc] == 0){
                if(h[nr][nc] < h[row][col]){
                    continue;
                }
                dfs(nr, nc, h, solve);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int R = heights.size();
        int C = heights[0].size();
        vector<vector<int>> pac(R, vector(C, 0));
        vector<vector<int>> atl(R, vector(C, 0));

        for (int c = 0; c < C; ++c) {
            dfs(0, c, heights, pac);
            dfs(R - 1, c, heights, atl);
        }
        for (int r = 0; r < R; ++r) {
            dfs(r, 0, heights, pac);
            dfs(r, C - 1, heights, atl);
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(atl[i][j] && pac[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }

    bool valid(int row, int col){
       return 0 <= row && row < heights.size() && 0 <= col && col < heights[0].size();
    }
};
