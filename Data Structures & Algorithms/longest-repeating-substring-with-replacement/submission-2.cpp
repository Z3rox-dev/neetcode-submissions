class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> q;

        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxFrequency = 0;

        while(right < s.length()){
            q[s[right]]++;
            maxFrequency = max(q[s[right]], maxFrequency);

            while((right - left + 1) - maxFrequency > k){
                q[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
