class Solution {
public:
    bool canPermutePalindrome(string s) {
      unordered_map<char, int> mp;
      for(auto c : s){
        mp[c]++;
      }
        vector<char> vc;
      for(auto [key, value] : mp){
        if(value % 2 != 0){
            if(vc.empty()){
                vc.push_back(key);
            }
            else if(vc.back() != key){
                return false;
            }
        }
      }
      return true; 
    }
};
