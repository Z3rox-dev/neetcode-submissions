class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet;
        int right = 0;
        int left = 0;
        int maxLength = 0;
        if (s.empty()) return 0;
        charSet.insert(s[left]);
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
