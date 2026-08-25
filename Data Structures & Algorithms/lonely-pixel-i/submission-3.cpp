class Solution {
public:
    vector<vector<char>> p;
    vector<vector<int>> seen;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int res = 0;
    void dfs(int row, int col){
        seen[row][col] = 1;
        
        if(checkIfAlone(row, col)){
            res++;
        }

        for(auto& dir : directions){
            int nr = row + dir[0];
            int nc = col + dir[1];
            if(isValid(nr, nc) && seen[nr][nc] == 0){
                seen[nr][nc] = 1;
                dfs(nr, nc);
            }
        }
    }
    int findLonelyPixel(vector<vector<char>>& picture) {
        this->p = picture;
        seen = vector(p.size(), vector(p.size(), 0));
        dfs(0, 0);
        return res;
    }

    bool isValid(int row, int col){
        return 0 <= row && 0 <= col && row < p.size() && col < p[0].size();
    }

    bool checkIfAlone(int row, int col){
        if(p[row][col] == 'W'){
            return false;
        }
        int count = 0;

        for(int i = 0; i < p[row].size(); i++){
            if(p[row][i] == 'B'){
                if(count == 0){
                    count++;
                }
                else{
                    return false;
                } 
            }
        }
        count = 0;
        for(int i = 0; i < p[col].size(); i++){
            if(p[i][col] == 'B'){
                if(count == 0){
                    count++;
                }
                else{
                    return false;
                } 
            }
        }
        return true;
    }
};
