class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1) return true;

        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        int word = 1;
        while(word < words.size()){
            int i = 0; int j = 0;
            while(i < words[word-1].size() && j < words[word].size()){
                if(mp[words[word-1][i]] > mp[words[word][j]]){
                    return false;
                }
                else if (mp[words[word-1][i]] < mp[words[word][j]]){
                    break;
                }
                
                i++;
                j++;
                if(i < words[word-1].size() && j == words[word].size()){
                    return false;
                }
            }
            word++;
        }
        return true;
    }
};