class WordDistance {
public:
    unordered_map<string, vector<int>> dict;

    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++){
            dict[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> vec1 = dict[word1];
        vector<int> vec2 = dict[word2];

        int res = INT_MAX;
        for(int& val : vec1){
            auto it= lower_bound(vec2.begin(), vec2.end(), val);
            if(it != vec2.end()){
                res = min(abs(*it - val), res);
            }
            if(it != vec2.begin()){
                it--;
                res = min(abs(*it - val), res);
            }
        }

        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
