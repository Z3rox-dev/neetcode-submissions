class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;

        for(const auto& str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            if(anagrams.find(temp) != anagrams.end()){
                anagrams[temp].push_back(str);
            }
            else {
                anagrams[temp] = { str };
            }
        }

        for(auto[key, value] : anagrams){
            ans.push_back(value);
        }
        return ans;
    }
};
