class Solution {
public:
    vector<vector<int>> memo;
    int solve(int i, int j, string s, string t){
        if(i == s.size()){ return t.size() - j; }
        if(j == t.size()){ return s.size() - i; }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(s[i] == t[j]){
            memo[i][j] = solve(i + 1, j + 1, s, t);
        }
        else{
            int a = 1 + (solve(i + 1, j, s, t));
            int c = 1 + (solve(i, j + 1, s, t));
            int r = 1 + (solve(i + 1, j + 1, s, t));
            memo[i][j] = min({a, c, r});
        }

        return memo[i][j];
    }
    bool isOneEditDistance(string s, string t) {
        memo = vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -1));

        if(solve(0, 0, s, t) == 1){
            return true;
        }

        return false;
    }
};
