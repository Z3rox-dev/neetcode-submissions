class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> duplicates;
        int left = 0;
        int maxCount = 0;
        int temp = 0;
        for(int right = 0; right < s.size(); right++){
            duplicates[s[right]]++;
            temp++;;
            auto it = duplicates.find(s[right]);

            while (left <= right && it->second > 1){
                duplicates[s[left]]--;
                left++;
                temp--;
            }

            maxCount = max(maxCount, temp);
        }
        return maxCount;
    }
};
