class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(int i = 0; i < strs.size(); i++){
            encodedString += std::to_string(strs[i].length()) + "#" + strs[i];
        }
        return encodedString;
    }

    vector<string> decode(string s) {

        std::vector<string> ans;
        std::string decodedString = "";
        for(int i = 0; i < s.length();){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int k = std::stoi(s.substr(i, j - i));
            string decodedString = s.substr(j + 1, k);
            ans.push_back(decodedString);

            i = j + 1 + k;
        }
        return ans;
    }
};
