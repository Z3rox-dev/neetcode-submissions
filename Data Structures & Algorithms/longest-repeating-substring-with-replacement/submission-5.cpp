class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hmap;
        int maxCount = 0;
        int tempCount = 0;
        int left = 0;
        int maxFrequency = 0;
        char mostFreqChar = s[0];

        for(int right = 0; right < s.size(); right++){
            hmap[s[right]]++;
            tempCount++;
            if(hmap[s[right]] > maxFrequency){
                maxFrequency = hmap[s[right]];
            }

            while(left <= right && (right - left + 1) - maxFrequency > k){
                hmap[s[left]]--;
                left++;
                tempCount--;
            }
            maxCount = max(tempCount, maxCount);
        }
        return maxCount;
    }
};
