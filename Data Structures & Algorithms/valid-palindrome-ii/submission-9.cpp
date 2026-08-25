class Solution {
public:
    bool isValid(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() -1;
        while(i <= j){
            if(s[i] != s[j]){
                if(isValid(s, i, j - 1) || isValid(s, i+1, j)){
                    return true;
                }
                else{
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
};