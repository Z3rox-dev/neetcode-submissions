class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for(string& s : arr){
            mp[s]++;
        }

        vector<string> res;
        for(string& s : arr){
            if(mp.find(s) != mp.end() && mp[s] == 1){
                res.push_back(s);
            }
        }
        if (res.size() < k) return "";

        return res[k-1];
    }
};