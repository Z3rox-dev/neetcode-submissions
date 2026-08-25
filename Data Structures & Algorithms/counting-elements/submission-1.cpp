class Solution {
public:
    int countElements(vector<int>& arr) {
       unordered_set<int> mp;
       unordered_map<int, int> dup;
       for(const auto& num : arr){
        mp.insert(num);
        dup[num]++;
       }
        int ans = 0;
       for(const auto key : mp){
        if(mp.count(key + 1)){
            ans += 1 * dup[key];
        }
       }
       return ans;
    }
};
