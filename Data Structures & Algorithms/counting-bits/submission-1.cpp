class Solution {
public:
    vector<int> res;
    
    int solve(int i, vector<int>& memo){
        if(i == 0){
            return 0;
        }

        if(memo[i] != -1){
            return memo[i];
        }

        memo[i] = solve(i >> 1, memo) + (i & 1);
        return memo[i];
    }
    vector<int> countBits(int n) {

        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        
        for(int i = 0; i <= n; i++){
            res.push_back(solve(i, memo));
        }
        

        return res;
    }
};
