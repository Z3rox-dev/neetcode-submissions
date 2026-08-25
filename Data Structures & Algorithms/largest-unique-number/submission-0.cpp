class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, pair<int, list<int>::iterator>> mp;
        list<int> uniques;

        for (int x : nums) {
            auto it = mp.find(x);

            if (it == mp.end()) {
                uniques.push_back(x);
                auto lit = prev(uniques.end());
                mp[x] = {1, lit};
            } 
            else {
                it->second.first++;

                if (it->second.first == 2) {
                    uniques.erase(it->second.second);
                }
            }
        }

        int res = -1;
        for (int x : uniques) {
            res = max(res, x);
        }

        return res;
    }
};