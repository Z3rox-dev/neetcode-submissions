class Solution {
public:
    string s;
    string p;
    vector<vector<int>> memo;
    int solve(int i, int j){
        if(j == (int)p.size()){
            return (i == (int)s.size());
        }
        int &res = memo[i][j];
        if(res != -1){
            return res;
        }
        bool ok = false;
        if(j + 1 < p.size() && p[j + 1] == '*' && i < s.size() && (s[i] == p[j] || p[j] == '.')){
            ok = true;
        }
        if(j + 1 < p.size() && p[j + 1] == '*'){
            res = solve(i, j + 2) || (ok &&(i < s.size() && solve(i + 1, j)));
        }
        else if(i < s.size() && (p[j] == '.' || p[j] == s[i])){
            res = solve(i + 1, j + 1);
        }
        else{
            res = 0;
        }
        return res;

    }
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        memo = vector(s.size() + 1, vector(p.size() + 1, -1));

        return solve(0, 0);
    }
};
