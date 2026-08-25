class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool found = false;
    void backtrack(vector<vector<char>>& board, string& word, string current, int row, int col,
                    vector<vector<int>>& visited){
        if(current == word){
            found = true;
            return;
        }
        if (current.size() >= word.size()) return;
        
        for(const auto direction : directions){
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(isValid(nextRow, nextCol, board) && visited[nextRow][nextCol] == 0){
                current += board[nextRow][nextCol];
                visited[nextRow][nextCol] = 1;
                backtrack(board, word, current, nextRow, nextCol, visited);
                current = current.substr(0, current.size()-1);
                visited[nextRow][nextCol] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        string current = "";
        for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    current = board[i][j];
                    visited[i][j] = 9;
                    backtrack(board, word, current, i, j, visited);
                    visited[i][j] = 0;
                    if(found) return found;
                }
            }
        }
        return found;
    }

    bool isValid(int row, int col, vector<vector<char>> board){
        return 0 <= row && row < board.size() && 0 <= col && col < board[0].size();
    }
};
