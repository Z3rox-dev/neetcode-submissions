class Solution {
public:
    unordered_set<string> words;
    string s;
    bool solve(int i, vector<int>& memo){
        if(i == s.size()){
            return true;
        }
        
        int& m = memo[i];
        if(m != -1){
            return m;
        }

        string cur = "";
        for(int j = i; j < s.size(); j++){
            cur += s[j];
            if(words.count(cur) && (solve(j + 1, memo))){
                return m = 1;
            }
        }
        m = 0;
        return m;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string& w : wordDict){
            words.insert(w);
        }
        this->s = s;
        vector<int> memo(s.size(), -1);
        return solve(0, memo);
    }
};
