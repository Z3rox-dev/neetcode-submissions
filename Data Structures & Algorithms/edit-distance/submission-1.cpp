class Solution {
public:
    string word1;
    string word2;

    int solve(int i, int j, vector<vector<int>>& memo){
        if(i == word1.size()) {
            return word2.size() - j;
        }
        if(j == word2.size()){
            return word1.size() - i;
        }

        int &res = memo[i][j];
        if(res != -1){
            return res;
        }

        if(word1[i] == word2[j]){
            res = solve(i + 1, j + 1, memo);
        }
        else{
            int ins = 1 + solve(i, j + 1, memo);
            int del = 1 + solve(i + 1, j, memo);
            int rep = 1 + solve(i + 1, j + 1, memo);
            res = min({ins, del, rep});
        }

        return res;
    }
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        vector<vector<int>> memo(word1.size() + 1, vector(word2.size() + 1, -1));

        return solve(0, 0, memo);
    }
};
