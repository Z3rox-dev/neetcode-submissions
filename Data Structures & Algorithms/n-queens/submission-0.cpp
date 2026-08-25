class Solution {
public:
    vector<string> board;
    vector<int> col;
    vector<int> diag;
    vector<int> anti;
    vector<vector<string>> res;
    int n;
    void backtrack(int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        
        for(int c = 0; c < board.size(); c++){

            if(col[c] != 0) continue;
            if(diag[row + c] != 0) continue;
            if(anti[row - c + n - 1] != 0) continue;

            col[c] = 1;
            diag[row + c] = 1;
            anti[row - c + n - 1] = 1;
            board[row][c] = 'Q';
            backtrack(row + 1);
            col[c] = 0;
            diag[row + c] = 0;
            anti[row - c + n - 1] = 0;
            board[row][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        col = vector(n + 1, 0);
        diag = vector(n * 2 + 1, 0);
        anti = vector(n * 2 + 1, 0);

        board = vector<string>(n, string(n, '.'));
        this->n = n;
        backtrack(0);

        return res;
    }
};
