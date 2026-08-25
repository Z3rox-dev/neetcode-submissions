class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> mp = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        string s = to_string(n);
        string res;
        for(int i = s.length() - 1; i >= 0; i--){
            int num = s[i] - '0';
            if(mp.find(num) != mp.end()){
                res += to_string(mp[num]);
            }
            else{
                return false;
            }
        }
        return res != s;
    }
};
