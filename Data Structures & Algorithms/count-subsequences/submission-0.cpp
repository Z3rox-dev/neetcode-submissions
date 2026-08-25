class Solution {
public:
    string t;
    string s;

    int solve(int i, int j, vector<vector<int>>& memo){
        if(j == t.size()){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }

        int &res = memo[i][j];
        if(res != -1){
            return res;
        }

        if(s[i] == t[j]){
            res = solve(i + 1, j, memo) + solve(i + 1, j + 1, memo);
        }
        else{
            res = solve(i + 1, j, memo);
        }

        return res;
    }
    int numDistinct(string s, string t) {
        this->t = t;
        this->s = s;
        vector<vector<int>> memo(s.size(), vector(t.size(), -1));

        return solve(0, 0, memo);

    }
};
