class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        int left = i;
        int right = j;

        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    vector<vector<string>> res;
    void backtrack(int start, string& s, vector<string> vec){
        if(start == s.size()){
            res.push_back(vec);
            return;
        }
        
        for(int idx = start; idx < s.size(); idx++){
            if(isPalindrome(s, start, idx)){
                string sub = s.substr(start, idx - start + 1);
                vec.emplace_back(sub);
                backtrack(idx + 1, s, vec);
                vec.pop_back();
            }  
        }
    }
    vector<vector<string>> partition(string s) {
            backtrack(0, s, {});
        return res;
    }
};
