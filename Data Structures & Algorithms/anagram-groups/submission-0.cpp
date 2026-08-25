class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> anagram;
        std::vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
                anagram[strs[i]].push_back(s);
        }

        for(auto& [key, value] : anagram){
            ans.push_back(value);
        }
        return ans;
    }
};
