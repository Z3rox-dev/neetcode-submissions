class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet;
        int right = 0;
        int left = 0;
        int maxLength = 0;
        while(right < s.size()){
            while(charSet.find(s[right]) != charSet.end() && left < right){
                charSet.erase(s[left]);
                left++; 
            }
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, (right - left + 1));
            right++;
        }
    return maxLength;
    }
};
