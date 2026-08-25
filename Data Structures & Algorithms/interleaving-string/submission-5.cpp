class Solution {
public:
    string s1;
    string s2;
    string s3;

    bool solve(int i, int j, vector<vector<int>>& memo){
        if(i == (int)s1.size() && j == (int)s2.size()){
            return true;
        }

        int &res = memo[i][j];
        if(res != -1){
            return res;
        }
        
        bool ok = false;
        if(i < s1.size() && s1[i] == s3[i + j]){
            ok = solve(i + 1, j, memo);
        }
        if(j < s2.size() && s2[j] == s3[i + j]){
           ok = solve(i, j + 1, memo);
        }
        res = ok == true ? 1 : 0;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        
        vector<vector<int>> memo(s1.size() + 1, vector(s2.size() + 1, -1));
        
        return solve(0, 0, memo);
    }
};
