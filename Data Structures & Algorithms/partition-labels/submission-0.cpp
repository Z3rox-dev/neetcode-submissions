class Solution {
public:
    vector<int> partitionLabels(string s) {
       unordered_map<char, int> lastIdx;
       for(int i = 0; i < s.size(); i++){
        lastIdx[s[i]] = i;
       }

       int w = 0;
       int ans = 0;
       vector<int> res;
       for(int i = 0; i < s.size(); i++){
        w = max(w, lastIdx[s[i]]);
        ans++;
        if(w == i){
            w = i;
            res.push_back(ans);
            ans = 0;
        }
       }
       return res;
    }
};
