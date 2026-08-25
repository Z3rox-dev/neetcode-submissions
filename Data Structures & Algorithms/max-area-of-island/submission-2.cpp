class Solution {
public:
    vector<vector<int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
    int n;
    int m;
    int maxIsland = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int count = 0;
                    dfs(i, j, visited, grid, count);
                    maxIsland = max(maxIsland, count);
                }
            }
        }
        return maxIsland;
    }

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid, int& count){
        visited[row][col] = true;
        count += 1;
        for(auto& direction : directions){
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(isValidPath(nextRow, nextCol, visited, grid)){
                dfs(nextRow, nextCol, visited, grid, count);
            }
        }
    }

    bool isValidPath(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        return 0 <= row && row < n && 0 <= col && col < m && !visited[row][col] && grid[row][col] == 1;
    }
};
