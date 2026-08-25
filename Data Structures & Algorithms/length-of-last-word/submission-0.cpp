class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        string res = "";
        int j = i;
        while(i >= 0 && s[i] != ' '){
            res += s[i];
            i--;
        }

        return j - i;
    }
};