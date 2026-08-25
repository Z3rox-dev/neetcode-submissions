class Solution {
public:
    vector<vector<int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
    int n, m;

    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int totalPaths = 0;
        dfs(0, 0, grid, visited, totalPaths);
        return totalPaths;
    }

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& totalPaths) {
        if(row == n - 1 && col == m - 1) {
            totalPaths++;
            return;
        }
        visited[row][col] = true;
        for(auto& d : directions) {
            int nextRow = row + d[0];
            int nextCol = col + d[1];
            if(isValid(nextRow, nextCol, grid, visited)) {
                dfs(nextRow, nextCol, grid, visited, totalPaths);
            }
        }
        visited[row][col] = false;
    }

    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        return row >= 0 && row < n && col >= 0 && col < m
               && grid[row][col] == 0
               && !visited[row][col];
    }
};
