class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(const auto& s : strs){
            vector<int> v(26, 0);
            for(char c : s){
                v[c - 'a']++;
            }
            
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string('a' + i) + to_string(v[i]);
            }
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto& pair : map){
            res.push_back(pair.second);
        }

        return res;
    }
};
