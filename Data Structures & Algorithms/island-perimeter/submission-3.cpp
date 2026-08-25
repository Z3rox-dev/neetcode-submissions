class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> seen;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int perimeter = 0;

    bool valid(int row, int col){
        return 0 <= row && row < g.size() && 0 <= col && col < g[0].size();
    }
    void compute(int r, int c){
        seen[r][c] = 1;
        for(auto d : directions){
            int nr = r + d[0];
            int nc = c + d[1];
            if(!valid(nr, nc)){
                perimeter++;
                continue;
            }

            if(g[nr][nc] == 0){
                perimeter++;
                continue;
            }

            if(seen[nr][nc] == 0){
                compute(nr, nc);
            }     
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        this->g = grid;
        seen = vector(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    compute(i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};