class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
      for(char& c : text) {
        mp[c]++;
      }
      if(mp.find('o') != mp.end()){
        mp['o'] = floor(mp['o'] / 2);
      }
      if(mp.find('l') != mp.end()){
        mp['l'] = floor(mp['l'] / 2);
      }

        unordered_set<char> s = {'b', 'a', 'l', 'o', 'n'};
        int m = INT_MAX;
      for(char c : s){
        if(mp.find(c) == mp.end()){
            return 0;
        }
        m = min(m, mp[c]);
      }

      return m;
    }
};