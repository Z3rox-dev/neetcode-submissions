class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited (n,vector<bool>(m,false));
        int numOfIslands = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    numOfIslands++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return numOfIslands;
    }

    void dfs(int row, int col,vector<vector<bool>>& visited, vector<vector<char>>& grid){
        visited[row][col] = true;
        for(auto& direction : directions){
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(isValid(nextRow,nextCol,visited,grid)){
                dfs(nextRow,nextCol, visited, grid);
            }
        }
    }

    bool isValid(int row, int col, vector<vector<bool>>& visited,vector<vector<char>>& grid){
        return 0 <= row && row < n && 0 <= col && col < m && (grid[row][col] == '1') && !visited[row][col];
    }

};
