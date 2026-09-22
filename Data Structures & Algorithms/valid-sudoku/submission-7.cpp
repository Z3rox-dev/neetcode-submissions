class Solution {
public:
    vector<unordered_set<char>> horizontal;
    vector<unordered_set<char>> vertical;
    vector<unordered_set<char>> cell;

    bool isValidSudoku(vector<vector<char>>& board) {
        horizontal = vector<unordered_set<char>>(board.size());
        vertical = vector<unordered_set<char>>(board.size());
        cell = vector<unordered_set<char>>(board.size());
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                int box = (i / 3) * 3 + (j / 3);
                if(!horizontal[i].count(board[i][j])){
                 horizontal[i].insert(board[i][j]);
                } else{
                    return false;
                }

                if(!vertical[j].count(board[i][j])){
                  vertical[j].insert(board[i][j]);
                } else{
                    return false;
                }

                if(!cell[box].count(board[i][j])){
                  cell[box].insert(board[i][j]);
                } else{
                    return false;
                }
            }
        }
    return true;
    }
};
