class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        bool bonus = true;
        while(left <= right){
            if(s[left] == s[right]){
                left++;
                right--;
                continue;
            }
            else if(bonus == false){
                return false;
            }
            else{
                bonus = false;
                if(right - 1 >= left && s[left] == s[right-1]){
                    right--;
                }
                else if(left + 1 <= right && s[left + 1] == s[right]){
                    left++;
                }
                else{
                    return false;
                }
            }
            right--;
            left++;
        }
        return true;
    }
};