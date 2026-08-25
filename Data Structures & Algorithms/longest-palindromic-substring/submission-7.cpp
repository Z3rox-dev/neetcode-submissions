class Solution {
public:
    int best = 1;
    int len = 0;
    string str = "";

    void expand(string s, int l, int right){
        while(l>= 0 && right < s.size() && s[l] == s[right]){
            l--;
            right++;
        }

        l++; right--;
        if(right - l + 1 > str.length()){
            best = right - l + 1;
            str = s.substr(l, right - l + 1);
        }
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        for(int i = 0; i < s.size(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return str;
    }
};
