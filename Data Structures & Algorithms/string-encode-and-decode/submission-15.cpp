class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0; i < strs.size(); i++){
            encoded += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans = {};
        int i = 0;
        while (i < s.size()) {
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            ans.push_back(s.substr(pos + 1, len));
            i = pos + 1 + len;
        }
        return ans;
    }
};