class Solution {
public:

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(auto& s : strings){
            string temp = "";
           for(int i = 0; i < s.size(); i++){
                for(int j = i + 1; j < s.size(); j++){
                    int difference = (s[i] - 'a') - (s[j] - 'a');
                    if(difference < 0){
                        difference += 26;
                    }
                    temp += difference;
                }
           }
           mp[temp].push_back(s);
        }

        for(auto [key, value] : mp){
            res.push_back(value);
        }
        return res;
    }
};
