class Solution {
public:
    string s;
    vector<vector<int>> memo;
    int solve(int i, int open, vector<vector<int>>& memo){
        if(i == s.size() && open == 0){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        if(open < 0){
            return 0;
        }
        int &res = memo[i][open];
        if(res != -1){
            return res;
        }

        if(s[i] == '('){
            res = solve(i + 1, open + 1, memo);
        }
        else if(s[i] == ')'){
            res = solve(i + 1, open - 1, memo);
        }
        else{
            res = solve(i + 1, open + 1, memo) || solve(i + 1, open - 1, memo) || solve(i + 1, open, memo);
        }

        return res;
    }

    bool checkValidString(string s) {
        this->s = s;
        memo = vector(s.size() + 1, vector(s.size(), -1));

        return solve(0, 0, memo);
    }
};
