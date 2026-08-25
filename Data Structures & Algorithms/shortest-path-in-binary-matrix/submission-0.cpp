class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        queue<pair<int,int>> q;
        auto p = make_pair(0,0);
        int pathCount = 1;
        q.push(p);
        while(!q.empty()){
            int size = q.size();

        for(int i = 0; i < size; i++){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if((row == grid.size()-1) && col == (grid[0].size()-1)){
                return pathCount;
            }
            for(auto& direction : directions){
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if(valid(nextRow, nextCol, grid)){
                    q.push(make_pair(nextRow, nextCol));
                    grid[nextRow][nextCol] = 1;
                }
            }
           }
           pathCount++;
        }
        return -1;
    }

    bool valid(int row, int col, vector<vector<int>>& grid){
        return 0 <= row && row < grid.size() && 0 <= col && col < grid[0].size() && grid[row][col] == 0;
    }
};