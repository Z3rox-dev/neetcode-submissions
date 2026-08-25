class Solution {
public:
    vector<vector<int>> memo;
    int dp(int idx1, const string& text1, int idx2, const string& text2){
        if(idx1 == text1.size()){
            return 0;
        }
        if(idx2 == text2.size()){
            return 0;
        }

        if(memo[idx1][idx2] != -1){
            return memo[idx1][idx2];
        }

        if(text1[idx1] == text2[idx2]){
            memo[idx1][idx2] = dp(idx1 + 1, text1, idx2 + 1, text2) + 1;
        }
        else{
            memo[idx1][idx2] = max(dp(idx1 + 1, text1, idx2, text2), dp(idx1, text1, idx2 + 1, text2));
        }

        return memo[idx1][idx2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        return dp(0, text1, 0 , text2);
        
    }
};
