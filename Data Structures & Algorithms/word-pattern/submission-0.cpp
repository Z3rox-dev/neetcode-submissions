class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char_to_ss;
        unordered_map<string, char> ss_to_char;
        vector<string> vec;
        string cur = "";

        for (char c : s) {
            if (c == ' ') {
                vec.push_back(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        vec.push_back(cur);

        if (vec.size() != pattern.size()) return false;

        for (int i = 0; i < vec.size(); i++) {
            if (!char_to_ss.count(pattern[i]) && !ss_to_char.count(vec[i])) {
                char_to_ss[pattern[i]] = vec[i];
                ss_to_char[vec[i]] = pattern[i];
            } else {
                if (char_to_ss[pattern[i]] != vec[i] || ss_to_char[vec[i]] != pattern[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};