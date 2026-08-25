class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> duplicates;
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int result = 0;
        while(right < s.length()){
            duplicates[s[right]]++;
            maxLength = std::max(maxLength, duplicates[s[right]]);
            if(right - left + 1 - maxLength > k ){
                duplicates[s[left]]--;
                left++;
            }
            result = std::max(result , right - left + 1);
            right++;
        }
        return result;
    }
};
