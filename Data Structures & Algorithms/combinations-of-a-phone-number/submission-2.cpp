class Solution {
public:
    vector<string> res;
    unordered_map<int, int> numCount;
    unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    unordered_map<char, int> count = {{'a', 2}, {'b', 2}, {'c', 2},
    {'d', 3}, {'e', 3}, {'f', 3},{'g', 4}, {'h', 4}, {'i', 4},
    {'j', 5}, {'k', 5}, {'l', 5},{'m', 6}, {'n', 6}, {'o', 6},
    {'p', 7}, {'q', 7}, {'r', 7},{'s', 7}, {'t', 8}, {'u', 8},
    {'v', 8}, {'w', 9}, {'x', 9},{'y', 9}, {'z', 9}};
    unordered_set<string> dd;

    unordered_map<int, int> found;
    void backtrack(int idx, int& k, string cur, vector<char>& alphas){
        if(cur.size() == k){
            for(char c : cur){
                found[count[c]]++;
                if(found[count[c]] > 1 && numCount[count[c]] == 1 || dd.find(cur) != dd.end()){
                    found.clear();
                    return;
                }
                else if(found[count[c]] > numCount[count[c]] || dd.find(cur) != dd.end()){
                    found.clear();
                    return;
                }
            }
            found.clear();
            dd.insert(cur);
            res.push_back(cur);
            return;
        }

        for(int i = idx; i < alphas.size(); i++){
            cur += alphas[i];
            backtrack(i + 1, k, cur, alphas);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<char> alphabet;
        for(char c : digits){
            int num = c - '0';
            numCount[num]++;
            for(auto s : mp[num]){
                alphabet.push_back(s);
            }
        }
        int size = digits.size();
        backtrack(0, size, "", alphabet);

        return res;
    }
};
