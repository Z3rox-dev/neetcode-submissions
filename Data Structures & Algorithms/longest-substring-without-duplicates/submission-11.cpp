class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int m = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                mp[s[left]]--;
                if(mp[left] == 0){
                    mp.erase(mp[left]);
                }
                left++;
            }
            m = std::max(m, i - left + 1);
        }
        return m;
    }
};
