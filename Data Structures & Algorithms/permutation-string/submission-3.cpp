class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int s1Freq[26] = {0};
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }
        int left = 0;
        int right = 0;
        while(right < s2.length()){
            if(right - left + 1 > s1.length()){
                freq[s2[left] - 'a']--;
                left++;
            }
            freq[s2[right] - 'a']++;
            right++;
            if(right - left == s1.length()){
                bool match = true;
                for(int i = 0; i < 26; i++){
                    if(s1Freq[i] != freq[i]){
                        match = false;
                        break;
                    }
                }
                if(match == true) return true;
            }
        }
        return false;
    }
};
