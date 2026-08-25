class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b){
            return a.size() < b.size();
        });
        set<string> _set;
        for(int i = 0; i < words.size(); i++){
            string cur = words[i];
            for(int j = i + 1; j < words.size(); j++){
                size_t pos = words[j].find(cur);
                if(pos != string::npos){
                    _set.insert(cur);
                }
            }
        }
        vector<string> res;
        for(auto ins : _set){
            res.push_back(ins);
        }
        return res;
    }
};