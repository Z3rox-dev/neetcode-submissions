class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for(const char& c : s){
            count[c]++;
        }

        for(const char& c : t){
            if(count.find(c) == count.end()){
                return false;
            }
            count[c]--;
            if(count[c] == 0){
                count.erase(c);
            }
        }
        return count.empty();
    }
};
