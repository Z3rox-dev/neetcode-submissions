class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char, int> mp;
       unordered_map<char,int> map_string1;
       int left = 0;
       
       for(auto& c : s1){
        map_string1[c]++;
       }

       for(int i = 0; i < s2.size(); i++){
        mp[s2[i]]++;
        int charMaxFreq = map_string1[s2[i]];
        while(mp[s2[i]] > charMaxFreq 
                        || map_string1.find(s2[i]) == map_string1.end()){
            mp[s2[left]]--;

            if(mp[s2[left]] == 0){
                mp.erase(s2[left]);
            }
            left++;
        }
        if(i - left + 1 == s1.size()){
            return true;
        }
       } 
       return false;
    }
};
